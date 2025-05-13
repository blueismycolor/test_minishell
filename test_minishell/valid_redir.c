/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:43:27 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/12 18:12:21 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool validate_redirections(char *input, int i)
{
	while (input[i])
	{
		if (is_double_redir(input[i], i))
		{
			if (input[i + 2] == '<' || input[i + 2] == '>')
			{
				ft_putstr_fd(ERR_REDIR, STDERR_FILENO);
				return  (false);
			}
			i++;
		}
		else if (is_pipe(input[i], i))
		{
			ft_putstr_fd(ERR_PIPE, STDERR_FILENO);
			return (false);
		}
		i++;
	}
}
		
bool 	is_pipe(char *input, int i)
{
	if (input[i] == '|' && input[i + 1] == '|')
			return (false);
	if (input[i] == '|')
			return (true);
	return (true);	
}

bool	is_single_redir(char c)
{
	return (c == '>' || c == '<');
}


bool	is_double_redir(char *input, int i)
{
	if (!input[i] || !input[i + 1])
		return (false);
	if ((input[i] == '<' && input[i + 1] == '<')
		|| input[i] == '>' && input[i + 1] == '>')
		return (true);
	return (false);
}


