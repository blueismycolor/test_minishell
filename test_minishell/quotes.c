/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:57:24 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/16 16:31:31 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


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