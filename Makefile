# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: DAVID <DAVID@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 19:01:11 by davdiaz-          #+#    #+#              #
#    Updated: 2025/07/31 19:27:00 by DAVID            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile para fractol - Versión optimizada
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -Ift_printf
DEPFLAGS = -MMD -MP
SANITIZE = -fsanitize=address

GREEN      		= \033[1;92m
RED 			= \033[1;31m
BLUE 			= \033[1;34m
RESET           = \033[0m

# Lista explícita de fuentes
SRCS = \
    src/main.c \
    src/ft_mandelbrot.c \
    src/ft_julia.c \
    src/ft_burning_ship.c \
    src/ft_arg_check.c \
    src/ft_atof.c \
    src/ft_check_error.c \
    src/ft_color.c \
    src/ft_creation.c \
    src/ft_destroy_and_close.c \
    src/ft_display.c \
    src/ft_init_graphic.c \
    src/ft_main_loops.c \
    src/ft_set_and_assign.c \
    src/ft_set_framework.c \
    src/ft_strcmp.c \
    src/ft_strisalpha.c \
    src/ft_strtol.c \
    src/ft_struct_init.c \
    src/ft_zoom.c

# Objetos en directorio obj/
OBJS = $(addprefix obj/,$(notdir $(SRCS:.c=.o)))
DEPS = $(OBJS:.o=.d)

# Bibliotecas
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
MINILIBX = minilibx-linux/libmlx.a
MINILIBX_TAR = minilibx-linux.tgz
LDFLAGS = -Llibft -lft -Lft_printf -lftprintf -Lminilibx-linux -lmlx -lXext -lX11 -lm

# Reglas principales
all: $(LIBFT) $(PRINTF) $(MINILIBX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(dir $@)

$(PRINTF):
	@$(MAKE) -C ft_printf

$(MINILIBX): $(MINILIBX_TAR)
	@echo "$(BLUE)📦 Extrayendo $(MINILIBX_TAR)...$(RESET)"
	@tar -xzf $(MINILIBX_TAR)
	@echo "$(GREEN)✅ MinilibX extraída$(RESET)"
	@$(MAKE) -C $(dir $@)

$(NAME): $(OBJS)
	@echo "🔗 Enlazando $@"
	@$(CC) $(OBJS) $(LDFLAGS) -o $@
	@echo "$(GREEN)✅ Fractol compilado correctamente$(RESET)"

# Regla genérica para objetos
obj/%.o: src/%.c
	@mkdir -p obj
	@echo "$(BLUE)🛠  Compilando $<$(RESET)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	@rm -rf obj
	@echo "$(BOLD)$(RED)🧹 Objetos eliminados$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C ft_printf fclean
	@echo "$(RED)🧼 Ejecutable y librerías limpiadas$(RESET)"

re: fclean all

.PHONY: all clean fclean re