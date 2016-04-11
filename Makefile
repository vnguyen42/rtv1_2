# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/11 15:51:01 by vnguyen           #+#    #+#              #
#    Updated: 2016/04/11 16:14:35 by vnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
LIB_NAME = Libft/libft.a
INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = src/main.c src/ft_parse_tools.c src/ft_parser.c src/ft_draw.c src/ft_normal.c src/ft_vector.c src/ft_color.c src/ft_error.c src/ft_init.c src/ft_touch_rotate.c src/ft_draw_suite.c src/ft_utile.c src/ft_vector.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

IFLAGS = -I $(INC_DIR) -I Libft
FLAGS = -Wall -Wextra -Werror

CC = gcc $(FLAGS)
LIBFLAGS = -Llibft -lft -lmlx -framework OpenGL -framework AppKit
RM = /bin/rm -f

all: $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	@make -C Libft re

$(NAME) : $(OBJS)
	@echo "Make Objectfs :\033[1;32m DONE \033[m"
	@$(CC) -o $@ $^ $(LIBFLAGS) -O3
	@echo "Make $(NAME) :\033[1;32m DONE \033[m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(IFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@make -C Libft clean
	@echo "MAke clean DONE"

fclean : clean
	@$(RM) $(NAME)
	@make -C Libft fclean
	@echo "MAke fclean done"

re: fclean all

.PHONY: all clean fclean re
