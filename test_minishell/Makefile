NAME		= minishell

RM			= rm -f
SRCS_MAIN	= main.c
SRCS		= exit.c \
 			parsing0_0.c \
			parsing0_1.c \
			quotes.c \
			token_utils.c \
			tokenize_part1.c


LIBFT_DIR	= libft-complete
LIBFT		= $(LIBFT_DIR)/libft-complete.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -g
LFLAG		= -lreadline 

OBJS_MAIN   = $(SRCS_MAIN:.c=.o) $(SRCS:.c=.o)

$(NAME): $(LIBFT) $(OBJS_MAIN)
	$(CC) $(CFLAGS) $(LFLAG) $(OBJS_MAIN) $(LIBFT) -o $(NAME) 

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_MAIN)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

