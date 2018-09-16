# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/07 02:03:14 by gcaixeta          #+#    #+#              #
#    Updated: 2018/09/07 02:07:33 by gcaixeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

SRC_PATH = ./sources/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
MLX_PATH = ./minilibx_macos/
LFT_PATH = ./libft/

SRC_NAME = main.c\
			read_map.c\
			prints.c\
			checks.c\
			keys.c\
			ext_keys.c\
			matrix.c\
			colors.c\
			plot_line.c

INC_NAME = fdf.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
INC = $(addprefix -I,$(INC_PATH))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_PATH)
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -L $(LFT_PATH) -lft -L $(MLX_PATH) -lmlx \
	-framework OpenGL -framework AppKit

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

simple: $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -L $(LFT_PATH) -lft -L $(MLX_PATH) -lmlx \
	-framework OpenGL -framework AppKit

.PHONY: clean $(NAME) fclean all re
