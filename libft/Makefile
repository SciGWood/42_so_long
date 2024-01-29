# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 14:10:42 by gdetourn          #+#    #+#              #
#    Updated: 2023/12/29 11:09:54 by gdetourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror
CC		= cc

SRC		= 	ft_itoa.c \
			ft_printf_sl.c \
			ft_split.c \
			read_text.c\
			utils.c \

OBJ		= $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
		ar rc $@ $^

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re