/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:56:31 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/13 14:20:08 by aeudes           ###   ########.fr       */
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





























// bool validate_tokens(t_token *tokens)
// {
// 	if (!check_invalid_redirect(tokens))
// 	{
// 		ft_putstr_fd(ERR_REDIR, STDERR_FILENO);
// 		return (false);
// 	}
// 	else if (!check_invalid_pipes(tokens))
// 	{
// 		ft_putstr_fd(ERR_PIPE, STDERR_FILENO);
// 		return (false);
// 	}
// 	else if (!check_unclosed_quotes(tokens))
// 	{
// 		ft_putstr_fd(UNCLOSED_QUOTES, STDERR_FILENO);
// 		return (false);
// 	}
// 	else if (!check_unclosed_expansions(tokens))
// 	{
// 		ft_putstr_fd(UNCLOSED_BRACE, STDERR_FILENO);
// 		return (false);
// 	}
// 	else if (!check_empty_command_segments(tokens)) // iki pipe arasi bos ise hata vermelidir.
// 		return (ft_putstr_fd(EMPTY_COMMAND, STDERR_FILENO), false);
// 	return (true);
// }


