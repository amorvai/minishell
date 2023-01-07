# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:01:23 by amorvai           #+#    #+#              #
#    Updated: 2023/01/07 17:34:23 by amorvai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
OBJ_DIR	:= obj/

NAME	:= libft.a

SRC		:=	\
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ		:=	$(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))

BONUS_SRC		:=	\
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJ	:= $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(BONUS_SRC)))

all: $(NAME)

bonus: $(NAME) $(BONUS_OBJ)
	$(AR) -r $(NAME) $^

$(NAME): $(OBJ_DIR) $(OBJ)
	$(AR) -r $@ $(OBJ)

$(OBJ_DIR)%.o: %.c 
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR): 
	mkdir obj

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) 

re: fclean all 

.PHONY: all bonus clean fclean re
