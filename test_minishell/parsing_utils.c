/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:56:31 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/07 19:19:53 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	return ( c == ' ' || c == '\t');
}

int	skip_space(char *input)
{
	int	i;

	i = 0;
	while (input[i] && is_space(input[i]))
		i++;
	return(i);
}

bool is_valid_operator(char *input)
{
	int		i;
	char	operator;
	
	i = 0;
	if (!input || !*input)
		return (false);
	if (input[0] == '<' || input[0] == '>')
	{
		operator = input[0];
		while (input[i] == operator)
			i++;
		if (i == 1 || i == 2)
			return (true);
		else
			return (false);
	}
	else if (input[0] == '|')
	{
		return (input[1] == '\\0');
	}
	return (false);
}