/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:53:05 by aeudes            #+#    #+#             */
/*   Updated: 2025/04/30 17:38:57 by aeudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft-complete/libft/libft.h"
# include "../libft-complete/ft_printf/ft_printf.h"

# define ERR_PIPE			"Error: failed to create pipe.\n"
# define ERR_MALLOC			"Error: memory allocation failed,\n"
# define ERR_QUOTE			"Error: unmatched or invalid quote.\n"
# define ERR_CMD			"Error: command execution failed.\n"
# define ERR_QUOTE_OPEN		"Error: unclosed quote.\n"
# define ERR_EXECVE			"Error: execve system call failed.\n"
# define ERR_FORK			"fork failed.\n"
# define ERR_DUP			"dup failed.\n"
# define NO_PATH			"no such file or directory.\n"
# define ERR_EOF			"unexpected EOF.\n"
# define TOO_LONG			"argument list too long.\n"
# define ERR_VA_ENV			"unboud variable.\n"			// Erreur avec variable non initialisee (set -u)
# define ERR_SYN			"syntax error in expression.\n"	// Manque un i++ ou qqch dans le genre
# define ERR_FD				"bad file descriptor.\n"		// Fermeture accidentelle dun fd
# define SUCCESS			0
# define ERROR				1

typedef enum s_type
{
	INPUT = 1,	// "<"  : redirection de l'entrée
	HEREDOC,	// "<<" : redirection here-doc
	TRUNC,		// ">"  : redirection de la sortie (écrasement)
	APPEND,		// ">>" : redirection de la sortie (ajout à la fin)
	PIPE,		// "|"  : pipe
	CMD,		// commande principale et argument(ex: ls -al, cat)
}	t_type;

typedef struct t_command
{
	char	*str;
	char	**command;
}	t_command;

typedef enum s_quote
{
	NONE,
	SINGLE,
	DOUBLE
}	t_quote;

typedef struct s_token
{
	char	*str;	// "cat", "|", "input.txt"
	t_type	type;	// CMD. PIPE,TRUNC etc.
	t_quote	quote;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;



//PARSING UTILS

int		is_space(char c);

//TOKENS
t_type	get_token_type(char *str);
t_token	*create_token(t_token **head, char *str, t_type type, t_quote quote);
bool	check_eof(char *input, char *current_token, t_type type, t_token **tokens);
bool	check_single_operator(char c);
bool	check_double_operator(char *input);



//QUOTES
t_quote	get_quote_type(char *str);
int		check_quotes(char *str);

//EXEC
void	msg_error(char *msg);

#endif