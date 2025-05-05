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
// static void	print_tokens(t_cmd *input)
// {
// 	while(input)
// 	{
// 		printf("Token: [%s], Type: %d, Quote: %d\n", input->str, input->type, input->quote);
// 		input = input->next;
// 	}
// }
#include <stdio.h>
#include <string.h>

#define ERROR -1
#define SUCCESS 0

void test_skip_quotes(char *input, int start_index) {
    int result = skip_quotes(input, start_index);
    if (result == ERROR) {
        printf("Error: Mismatched quotes detected!\n");
    } else {
        printf("Next index after skipping quotes: %d\n", result);
    }
}

int main() {
    // Test case 1: Tek tırnak testi
    char *test_input1 = "echo 'Hello World' > file.txt";
    printf("Test 1: %s\n", test_input1);
    test_skip_quotes(test_input1, 5); // Start after 'echo'

    // Test case 2: Çift tırnak testi
    char *test_input2 = "echo \"Hello World\" > file.txt";
    printf("Test 2: %s\n", test_input2);
    test_skip_quotes(test_input2, 5); // Start after 'echo'

    // Test case 3: Tırnak yok, sadece boşluk
    char *test_input3 = "echo Hello World > file.txt";
    printf("Test 3: %s\n", test_input3);
    test_skip_quotes(test_input3, 5); // Start after 'echo'

    // Test case 4: Eşleşmeyen tırnak (hata durumu)
    char *test_input4 = "echo 'Hello World > file.txt";
    printf("Test 4: %s\n", test_input4);
    test_skip_quotes(test_input4, 5); // Start after 'echo'

    return 0;
}

