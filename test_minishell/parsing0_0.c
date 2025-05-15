/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:56:31 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/15 13:06:19 by aeudes           ###   ########.fr       */
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




























