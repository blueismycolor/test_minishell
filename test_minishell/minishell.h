/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeudes <aeudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:53:05 by aeudes            #+#    #+#             */
/*   Updated: 2025/05/16 16:21:46 by aeudes           ###   ########.fr       */
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


# define ERR_PIPE				"Error: failed to create pipe.\n"
# define ERR_REDIR				"Error: invalid redirection.\n"
# define ERR_MALLOC				"Error: memory allocation failed,\n"
# define ERR_QUOTE				"Error: unmatched or invalid quote.\n"
# define OPEN_SNG_QUOTE			"Error: unclosed single quote.\n"
# define OPEN_DBL_QUOTE			"Error: unclosed double quote.\n"
# define ERR_CMD				"Error: command execution failed.\n"
# define ERR_EXECVE				"Error: execve system call failed.\n"
# define ERR_FORK				"Error: fork failed.\n"
# define ERR_DUP				"Error: dup failed.\n"
# define NO_PATH				"Error: no such file or directory.\n"
# define ERR_EOF				"Error: unexpected EOF.\n"
# define TOO_LONG				"Error: argument list too long.\n"
# define ERR_VA_ENV				"Error: unboud variable.\n"			// Erreur avec variable non initialisee (set -u)
# define ERR_SYN				"Error: syntax error in expression.\n"	// Manque un i++ ou qqch dans le genre
# define ERR_FD					"Error: bad file descriptor.\n"		// Fermeture accidentelle dun fd
# define SUCCESS				0
# define ERROR					-1
# define FAIL					1



typedef enum s_type
{
	INPUT = 1,	// "<"  : redirection de l'entrée
	HEREDOC,	// "<<" : redirection here-doc
	TRUNC,		// ">"  : redirection de la sortie (écrasement)
	APPEND,		// ">>" : redirection de la sortie (ajout à la fin)
	PIPE,		// "|"  : pipe
	CMD,		// commande principale et argument(ex: ls -al, cat)
}	t_type;

typedef enum s_quote
{
	NONE,
	SINGLE,
	DOUBLE
}	t_quote;

typedef struct s_token
{
	char	*str;
	t_type	type;
	t_quote	quote;
	bool	has_expansion;
	struct s_token *next;
}	t_token;

typedef struct s_redir
{
	char			*filename;
	t_type			type;
	struct s_redir	*next; 
}	t_redir;

typedef struct s_cmd
{
	char			*cmd;
	bool			is_builtin;
	char			**args;
	int				nb_params;
	bool			has_redir;
	t_redir			*redir;
	t_quote			quote;
	struct s_cmd	*next;
	struct s_cmd	*prev;
	t_type			type;
}	t_cmd;

typedef struct s_data
{
	t_cmd			*cmd;
	char			**env;
	char			*pwd;
	char			*old_pwd;
	int				return_value;
	char			**historic;
}	t_data;


//PARSING UTILS
int		is_space(char c);
int		skip_space(char *input);
bool	is_in_quotes(char *input, int i);
bool	is_in_double_quotes(char *input, int i);

//PARSING
bool	validate_input(char *input);
bool	check_pipe_syntax(char *input, int i);
int		check_quote_syntax(char *input, int i);
bool	check_redirection_syntax(char *input, int i);
int		process_input(char *input);


//TOKENS
t_type	get_token_type(char *str);
t_token	*create_token(t_token **head, char *str, t_type type, t_quote quote);
bool	check_eof(char *input, char **current_token, t_token **tokens);
bool	is_single_redir(char c);
bool	is_double_redir(char *input , int i);
bool 	quoted_token(char **input, char *current_token);
bool	operator_start(char c);

//QUOTES
t_quote	get_quote_type(char *str);
int		check_quote_state(char *input);





//EXEC
void	msg_error(char *msg);

#endif