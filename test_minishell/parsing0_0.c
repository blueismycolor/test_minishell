/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:56:31 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/16 15:45:20 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool		is_in_quotes(char *input, int i)
{
	int index;
	int	quote_count;
	
	index = 0;
	quote_count = 0;
	while (index < i)
	{
		if (input[index] == '\'')
			quote_count++;
		index++;
	}
	if (quote_count % 2 != 0)
		return (true);
	return (false);
}

bool		is_in_double_quotes(char *input, int i)
{
	int	index;
	int	quote_count;

	index = 0;
	quote_count = 0;
	while (index < i)
	{
		if (input[index] == '"')
			quote_count++;
		index++;
	}
	if (quote_count % 2 != 0)
		return (true);
	return (false);
}
























