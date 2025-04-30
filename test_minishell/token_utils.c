/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:57:55 by aeudes            #+#    #+#             */
/*   Updated: 2025/04/30 13:49:23 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_type get_token_type(char *str)
{
	if (ft_strncmp(str, ">>", 2) == 0)
		return (APPEND);
	else if (ft_strncmp(str, "<<", 2) == 0)
		return (HEREDOC);
	else if (ft_strncmp(str, ">", 1) == 0)
		return (TRUNC);
	else if (ft_strncmp(str, "<", 1) == 0)
		return (INPUT);
	else if (ft_strncmp(str, "|", 1) == 0)
		return (PIPE);
	else
		return (CMD);
}


t_token *create_token(t_token **head, char *str, t_type type, t_quote quote)
{
	t_token	*new_token;
	t_token	*tmp;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->str = ft_strdup(str);
	new_token->type = type;
	new_token->quote = quote;
	new_token->next = NULL;
	new_token->prev = NULL;
	if (!*head)
		*head = new_token;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token;
		new_token->prev = tmp;
	}
	return (new_token);
}