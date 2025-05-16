/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:08:26 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/16 16:29:25 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool check_eof(char *input, char **current_token, t_token **tokens) // 1
{
	t_type type;

	if (input[0] == '\0')
	{
		if (*current_token && (*current_token)[0] != '\0')
		{
			type = get_token_type(*current_token);
			create_token(tokens, *current_token, type, NONE);
			free(*current_token);
			*current_token = NULL;
		}
		return true;
	}
	return false;
}

bool	is_single_redir(char c) //2
{
	return (c == '>' || c == '<');
}


bool	is_double_redir(char *input, int i) //3
{
	if (!input[i] || !input[i + 1])
		return (false);
	if ((input[i] == '<' && input[i + 1] == '<')
		|| (input[i] == '>' && input[i + 1] == '>'))
			return (true);
	return (false);
}

bool quoted_token(char **input, char *current_token) // 4
{
	int		i;
	char	quote;
	char	*current_input_pos;

	i = 0;
	if (**input != '\'' && **input != '\"')
		return (false);

	quote = **input;
	(*input)++;
	current_input_pos = *input;
	while (*current_input_pos && *current_input_pos != quote)
	{
		current_token[i++] = *current_input_pos;
		current_input_pos++;	
	}
	if (*current_input_pos == quote)
		current_input_pos++;  

	current_token[i] = '\0';
	*input = current_input_pos;
	return (true);
}

bool	operator_start(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

/*
	eger bir karakter yeni bir operator baslatabiliyorsa onceki token sona erer
	ve yeni bir operator tokeni baslatir.
	|, <, >, <<, >> 
	
	ornegin echo test | grep ok
	token 1 echo
	token 2 test
	token 3 | 
	token 4 grep
	token 5 ok

	karakter karakter oku
	eger bir karakter olabilir | < > kontrol et
	eger evet onceki token bitir bu karakterler ile yeni bir token baslat
	eger devam ederse << >> o zaman ayni token'a karakter eklemeye basla

	bu sadece burada bir operator baslayabilir mi sorusunun cevabini verir true donerse
	tokenizer fonksiyonunda sunu yapariz: 
	if (operator_start(line[i]))
		t_type type = get_operator_type(&line[i]);

*/


/*	QUOTED_TOKEN
	Amacimiz: tirnak ile basliyorsa icerigi al ve current token'a yaz.
	Amac sadece tirnakli ifadeleri okumak
	Acilan tirnagin kapanana kadarki kismi tek bir token olarak algilanir.
	Tirnak icindeki bosluklarda oldugu gibi yazilir.
	- tirnak ile baslamiyorsa false
	- tirnak tipini quote icerisine kaydediyoruz.
	- tirnak tipini elde ettikten sonra bir adim ilerletiyoruz ki alacagimiz metne gecebilelim. 
	- current_input_positionuna erisiyoruz.
	- tirnakla karsilasincaya kadar her karakteri current_token icerisine kopyaliyoruz.
	- eger tirnaga ulastiysak, bu tirnagi atliyoruz.
	- kaldigimiz yerden devam edebilmek icin *input = current_input_pos; aksi halde ayni yeri 
*/

/*
	if (is_single_operator(token_str[0] && token_len == 1))
	 {
	 	token_type = token_operator
	 }
*/

/*	CHECK_EOF
	cette fonction verifie si la fin d'une ligne d'entree a ete atteinte
	si l'entree est terminee comme EOF et qu'il existe encore un current_token
	en cours de traitement, ce token est converti en une structure t_cmd
	et ajoute a la liste des tokens.
*/