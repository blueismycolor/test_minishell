/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:52:50 by aeudes            #+#    #+#             */
/*   Updated: 2025/04/30 17:39:08 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	print_tokens(t_token *input)
{
	while(input)
	{
		printf("Token: [%s], Type: %d, Quote: %d\n", input->str, input->type, input->quote);
		input = input->next;
	}
}
int main(void)
{
	t_token *tokens = NULL;
	char	buffer[4] = "echo";

	if (check_eof("", buffer, CMD, &tokens))
		printf("EOF'e ulasildi, token finalize edildi.\n");
	print_tokens(tokens);
	return (0);
	
}
