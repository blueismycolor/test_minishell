/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:57:24 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/16 15:45:32 by aeudes           ###   ########.fr       */
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

t_quote	get_quote_type(char *str)
{
	int		i;
	t_quote	quote;

	i = 0;
	quote = NONE;
	while (str[i])
	{
		if (str[i] == '\'' && quote == NONE)
			return (SINGLE);
		if (str[i] == '"' && quote == NONE)
			return (DOUBLE);
		i++;
	}
	return (NONE);
	
}

int	check_quote_state(char *input)
{
	int i;
	t_quote quote_state;
	
	i = 0;
	quote_state = NONE;
	while (input[i] != '\0') 
	{
		if (input[i] == '\'' && quote_state == NONE)
			quote_state = SINGLE;
		else if (input[i] == '\'' && quote_state == SINGLE)
			quote_state = NONE;
		else if (input[i] == '\"' && quote_state == NONE)
			quote_state = DOUBLE;
		else if (input[i] == '\"' && quote_state == DOUBLE)
			quote_state = NONE;
		i++;
	}
	if (quote_state != NONE)
	{
		msg_error(ERR_QUOTE);
		return(ERROR);
	}
	return (SUCCESS);
}