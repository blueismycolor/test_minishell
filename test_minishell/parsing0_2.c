/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:43:27 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/15 14:58:23 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	validate_input(char *input, t_token *tokens)
{
	if (!check_pipe_syntax(input))
		return false;
	if (!check_quote_syntax(input, 0))
		return false;
	if (!check_redirection_syntax(tokens))
		return false;
	return true;
}

bool	check_pipe_syntax(char *input)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	quote = 0;
	while (input[i])
	{
		if((input[i] == '\'' || input[i] == '\"') && quote == 0)
			quote = input[i];
		else if (input[i] == quote)
			quote = 0;
		if (quote == 0 && input[i] =='|')
		{
			j = i + 1;
			while (input[j] == ' ')
				j++;
			if (input[i + 1] == '|' || input[0] == '|' || input[j] == '|')
				return (ft_putstr_fd(ERR_SYN, STDERR_FILENO), false);
		}
		i++;
	}
	return (true);
}


int	check_quote_syntax(char *input, int i)
{
	while (input[i] && input[i] != '|' && input[i] != '>' && input[i] != '<')
	{
		if (input[i] == '\'')
		{
			i++;
			while (input[i] && input[i] != '\'')
				i++;
			if (input[i] == '\0')
				return (ft_putstr_fd(UNCLOSED_QUOTES, STDERR_FILENO), ERROR);
		}
		else if (input[i] == '\"')
		{
			i++;
			while (input[i]  && input[i] != '\"')
				i++;
			if (input[i] == '\0')
				return (ft_putstr_fd(UNCLOSED_QUOTES, STDERR_FILENO), ERROR);
		}
		i++;
	}
	return (i);
}

bool	check_redirection_syntax(t_token *tokens)
{
	t_token *current;

	current = tokens;
	while (current)
	{
		if (current->type == INPUT || current->type == TRUNC
			|| current->type == HEREDOC || current->type == APPEND)
		{
			if (!current->next || current->next->type != CMD)
			{
				ft_putstr_fd(ERR_REDIR, STDERR_FILENO);
				return (false);
			}
		}
		current = current->next;	
	}
	return (true);
}



/*
	acilan tirnak kapanmamissa hata

	ic ice tirnak kullanimi hata
	
	tirnak acildiginda icerigi bir butun olarak kabul edilmeli split yapilmamali

	baslangic ve sondaki tirnaklar dogru bir sekilde eslesmeli
	
	tirnak icinde | < > vs var ise yok sayilmali (ancak "tirnak arasi $USER" var ise expansion)
	
*/



/* PIPE KONTROLU 
eger ' veya "" karakterine rastlanirsa ve su anda tirnak icinde degilsek tirnak bloguna girilir

eger su anki karakter daha once acilmis tirnagin aynisiysa tirnak blogu kapanir

amac tirnak icindeki | karakterlerini dikkate almamak

eger tirnak icinde degilsek ve | sembolune rastladiysak pipe kontrolune gecilir

| semobolundan sonraki bosluklar atlanir j = i + 1 ile.

bu satirda birden fazla kontrol yapilir : 
if (input[i + 1] == '|' || input[0] == '|' || input[i] == '\0'|| input[j] == '|')
	iki pipe arka arkaya yazilmis mi
	komutun basinda pipe var mi 
	iki pipe arasi bos birakilmis mi 

*/

/*
Si un pipe est au début :
	Ex : | ls → erreur
Si un pipe est à la fin :
	Ex : ls | → erreur
S’il y a un espace vide entre deux pipes :
	Ex : ls | | wc → erreur
S’il y a plusieurs pipes consécutifs :
	Ex : ls || wc → erreur (tu l’as déjà vérifié)
Les pipes à l’intérieur des guillemets doivent être ignorés.
	Ex : "echo | test" → valide, car le | est entre guillemets
*/