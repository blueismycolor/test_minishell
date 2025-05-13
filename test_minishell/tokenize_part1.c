/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:08:26 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/12 16:23:43 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool check_eof(char *input, char **current_token, t_token **tokens)
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

bool quoted_token(char **input, char *current_token)
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


bool	has_expansion(char *str)
{
	t_quote quote;
	
	quote = NONE;
	if (quote == SINGLE)
		return (false);
	return (ft_strchr(str, '$') != NULL);
}























/*
	HAS_EXPANSION
	eger tek tirnak ise icindeki her sey oldugu gibi disari cikar
	ama eger cift tirnaksa ve icerisinde $ isareti var ise burada expansion var demektir.
	strchr fonksiyonu ile $ sembolu aranir, eger var ise bu karakterin adresi dondurulur
	ve true doner.
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