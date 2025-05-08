/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:14:33 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/07 21:54:11 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_operator_start(char c)
{
	return (c == '<' || c == '>' || c == '|'); // ???
}

bool	handle_space()
{
	
}
/*
	eger karakter bosluk ise ve tirnak icinde degilse yok sayilir
	echo bonjour        tout le monde
	tokens : "echo", "bonjour", "tout" "le" "monde"
	arasinda kac bosluk olursa olsun, tek bosluk gibi islenir
	
	ornegin:
		echo "bonjour    tout le monde"
		tokens :"echo" ve "bonjour    tout le monde"
	
	ornegin: 
		echo a '' b
		tokens : "a", "", "b"
		
	---> ' ' ICI BOS AMA TIRNAKLAR QUOTED OLDUGU ICIN BU TOKEN DIR. 
	---> EGER TIRNAKSIZ BOSLUKLAR OLSAYDI BU TOKEN OLARAK DEGERLENDIRILMEYECEKTI. 
*/
// t_token	handle_comment();
// t_token	append_to_word();
// t_token start_new_word();