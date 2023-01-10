NAME	:= minishell
CC		:= cc
CFLAGS	:= -I src/ -I lib/ -g3 -fsanitize=address #-Wall -Werror -Wextra
LDFLAGS	:= -L ./lib/the_lib -l_extended -lreadline -L ~/.brew/opt/readline/lib/
VPATH	:= src/ src/parsing/ src/env/
OBJ_DIR	:= obj/

SRC		:=	main.c \
			env.c \
			env_too.c \
			split_token.c

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
