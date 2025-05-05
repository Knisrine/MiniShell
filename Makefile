CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell
MFILES = ./built-in/main.c ./built-in/built-in.c ./built-in/ft_strdup.c ./built-in/update_env.c ./built-in/ft_addback.c ./built-in/ft_lstnew.c \
		 ./built-in/ft_strlen.c ./built-in/export.c ./built-in/error_msg.c ./built-in/env_function.c ./built-in/len_env.c ./built-in/ft_strncmp.c \
		 ./built-in/ft_strchr.c ./built-in/unset.c ./built-in/new_env.c ./built-in/ft_split.c
OFILES = $(MFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

%.o: %.c minishell.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean