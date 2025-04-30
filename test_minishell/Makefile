NAME		= minishell

RM			= rm -f
SRCS_MAIN	= main.c
SRCS		= token_utils.c \
			tokenize_part1.c \
			tokenize_part2.c \
			quotes.c \
			parsing_utils.c \
			exit.c

LIBFT_DIR   = libft-complete
LIBFT       = $(LIBFT_DIR)/libft-complete.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I$(LIBFT_DIR) -g

OBJS_MAIN   = $(SRCS_MAIN:.c=.o) $(SRCS:.c=.o)

$(NAME): $(LIBFT) $(OBJS_MAIN)
	$(CC) $(CFLAGS) $(OBJS_MAIN) $(LIBFT) -o $(NAME)

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

