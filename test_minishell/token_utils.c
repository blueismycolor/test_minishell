/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:57:55 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/16 17:45:12 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	return ( c == ' ' || (c >= 9 && c <= 13));
}

int	skip_space(char *input)
{
	int	i;

	i = 0;
	while (input[i] && is_space(input[i]))
		i++;
	return(i);
}

t_type get_token_type(char *input)
{
	if (ft_strncmp(input, ">>", 2) == 0)
		return (APPEND);
	else if (ft_strncmp(input, "<<", 2) == 0)
		return (HEREDOC);
	else if (ft_strncmp(input, ">", 1) == 0)
		return (TRUNC);
	else if (ft_strncmp(input, "<", 1) == 0)
		return (INPUT);
	else if (ft_strncmp(input, "|", 1) == 0)
		return (PIPE);
	else
		return (CMD);
}


t_token 	*create_token(t_token **head, char *str, t_type type, t_quote quote)
{
	t_token	*new_token;
	t_token	*tmp;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->str = ft_strdup(str);
	if (!new_token->str)
		return(free(new_token), NULL); // free new token ? 
	new_token->type = type;
	new_token->quote = quote;
	new_token->has_expansion = false;
	new_token->next = NULL;
	if (!*head)
		*head = new_token;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token;
	}
	return (new_token);
}



/*
create_token fonksiyonunda ft_stdup kullanmak gereklidir cunku
eger dogrudan str icinde tutulursa; buffer silinirse veya bellegi baska bir islem kullanirsa
ya da string free edilirse token->str isaretcisi gecersiz hale gelir. 

ft_strdup her zaman bellek hatalarinda, segmentation faultlardan ve garip token 
verilerinden korur.

ornegin:
burada str heapte cunku malloc ile olusturulmus
eger bu bellek baska yere verilmeyecekse dogrudan atanabilir

ornegin:
char buffer[256];
strcpy(buffer, "test");
create_token(&tokens, buffer, word, none);
---> burada buffer stackte ve fonksiyon bitince yok olur
token artik gecersiz bir bellek adresine bakar 
bu yuzden mutlaka strdup gerekir
*/