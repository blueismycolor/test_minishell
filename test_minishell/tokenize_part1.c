/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:08:26 by aeudes            #+#    #+#             */
/*   Updated: 2025/04/30 17:39:33 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
	input = su anda islenen giris verisi (bir komut satiri ornegin "echo hello")
	current_token = su ana kadar birikmis karakterlerden olusan gecici token
	type = token turu
	tokens = token listesinin basi, yeni tokenlar bu listeye eklenir
	current_token[0] = '\0'; //sonrasinda kullanilmasin diye temizle.
*/

bool	check_eof(char *input, char *current_token, t_type type, t_token **tokens)
{
	int		i;
	
	i = 0;
	if (input[i] == '\0')
	{
		if (current_token && *current_token)
		{
			type = get_token_type(current_token);
			create_token(tokens, current_token, type, NONE);
			current_token[0] = '\0';
		}
			
		return (true);
	}
	return (false);
}

bool	check_single_operator(char c)
{
	return (c == '|' || c == '>' || c == '<');
}

bool	check_double_operator(char *input)
{
	if (!input)
		return (false);
	if (ft_strncmp(input, ">>", 2) == 0 && input[2] == '\0')
		return (true);
	if (ft_strncmp(input, "<<", 2) == 0 && input[2] == '\0')
		return (true);
	return (false);
	
}


// t_token	handle_quotes();
// t_token	handle_expansion();

