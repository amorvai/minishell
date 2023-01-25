# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 14:52:03 by amorvai           #+#    #+#              #
#    Updated: 2023/01/24 14:50:33 by pnolte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -fsanitize=address
VPATH	:= printf/ printf/print_conversions/ get_next_line/
OBJ_DIR	:= obj/

NAME	:= lib_extended.a #inc/the_library/

SRC		:=	ft_printf.c \
			print_char.c \
			print_int.c \
			print_lowerhexadec.c \
			print_string.c \
			print_unsigneddecimal.c \
			print_upperhexadec.c \
			print_voidptr.c \
			get_next_line_fd.c \
			get_next_line_utils_fd.c

OBJ		:=	$(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))

LIBFT	:= libft/libft.a

all: $(NAME) 

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	cp libft/libft.a $(NAME)
	ar -crs $(NAME) $(OBJ) 

$(OBJ_DIR)%.o: %.c 
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR): 
	mkdir obj

$(LIBFT):
	make --directory=./libft

clean:
	make clean --directory=./libft
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean --directory=./libft
	rm -f $(NAME) 

re: fclean all 

.PHONY: all clean fclean re
