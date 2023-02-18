NAME	:= minishell
CC		:= cc
CFLAGS	:= -I src/ -I lib/ -g3 -Wall -Werror -Wextra 
LDFLAGS	:= -L ./lib/the_lib -l_extended -lreadline -L ~/.brew/opt/readline/lib/
VPATH	:= src/ src/env/ src/parsing/ src/token/ src/minishell/ src/builtin/ src/exec/ src/structure/
OBJ_DIR	:= obj/

SRC		:=	main.c \
			minishell.c \
			env.c env_too.c \
			parsing.c expansion.c \
			command.c redirection.c \
			token.c token_init.c \
			exec.c pipes.c exec_rede.c\
			bi_cd.c bi_echo.c bi_env.c bi_exit.c bi_export.c bi_pwd.c bi_unset.c\
			

OBJ		:= $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))

LIBFT	:= lib/the_lib/lib_extended.a

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR): 
	mkdir obj

$(OBJ_DIR)%.o: %.c 
	$(CC) $(CFLAGS) $< -c -o $@

$(LIBFT):
	make -C ./lib/the_lib

clean:
	make -C ./lib/the_lib clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C ./lib/the_lib fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libft