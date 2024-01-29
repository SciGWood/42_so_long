# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 14:40:12 by gdetourn          #+#    #+#              #
#    Updated: 2023/12/29 13:38:16 by gdetourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME	= so_long

# Compiler options
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

# Libft
LIBFT_PATH = ./libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

# MinilibX
MLX_PATH = ./mlx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# so_long files
SRC		= 	error_exit.c \
			game.c \
			images.c \
			parsing.c \
			so_long.c \
			valid_path.c \

OBJ		= $(SRC:.c=.o)

# Includes
INCLUDES = 	-I ./includes/\
			-I ./mlx/\
			-I ./libft/\

# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m
BLUE = \033[94m

all : $(MLX_LIB) $(LIBFT_LIB) $(NAME)

# Compiling Libft and Mlx
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_LIB):	
	@make -sC $(LIBFT_PATH)
	@echo "\n"
	@echo "$(BOLD)$(GREEN)🎆     Libft Compiled    🎆$(RESET)"
	@echo "\n"
	@echo "$(BOLD)$(BLUE)-----------------------$(RESET)"
	@echo "\n"

$(MLX_LIB):
	@echo "$(BOLD)$(RED)🛠️ 🚧      Compiling MiniLibX      🚧🛠️$(RESET)"
	@echo "\n"	
	@make -C $(MLX_PATH)
	@echo "$(BOLD)$(GREEN)🎆     MiniLibX Compiled    🎆$(RESET)"
	@echo "\n"
	@echo "$(BOLD)$(BLUE)-----------------------$(RESET)"
	@echo "\n"

# Compiling so_long
$(NAME): $(OBJ)
	@echo "$(BOLD)$(RED)🛠️ 🚧      Compiling so_long      🚧🛠️$(RESET)"
	@echo "\n"	
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME) -g
	@echo "$(BOLD)$(GREEN)📟👾🕹️    so_long ready to use    📟👾🕹️$(RESET)"
	@echo "\n"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ)
	@echo "$(BOLD)$(ORANGE)🧹🧼     Cleaned .o Libft's files   🧼🧹$(RESET)"
	@make clean -sC $(MLX_PATH)
	@echo "$(BOLD)$(ORANGE)🧹🧼     Cleaned .o MiniLibX's files  🧼🧹$(RESET)"

fclean: clean
#	@make fclean -sC 
	@rm -rf $(MLX_LIB) $(LIBFT_LIB) $(NAME)
	@echo "$(BOLD)$(ORANGE)🧹🧼    Cleaned libs and so_long exec    🧼🧹$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
