# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: DAVID <DAVID@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 19:01:11 by davdiaz-          #+#    #+#              #
#    Updated: 2025/07/23 23:15:29 by DAVID            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -MMD -MP
SRC = main.c ft_strcmp.c ft_atof.c ft_strisalpha.c ft_arg_check.c ft_destroy_and_close.c ft_check_error.c ft_creation.c ft_display.c ft_init_graphic.c ft_main_loops.c ft_set_and_assign.c ft_set_framework.c ft_struct_init.c
OBJS = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

##MINILIBX = minilibx/libmlx.a

GREEN = \033[1;32m

all: $(NAME)

%.o: %.c
	@echo "Compilando $< → $@"
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)
	@echo "$(GREEN)Fractol successfully compiled"

-include $(DEP)

clean:
	@rm -f $(OBJS)
	@rm -f $(DEP)
	@echo "Archivos objeto eliminados."

fclean:
	@rm -f $(NAME)
	@echo "Ejecutables eliminados para fractol."
	@rm -f $(DEP)

re:
	fclean all

.PHONY: all clean fclean re

