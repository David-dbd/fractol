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
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -MMD -MP
LFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm
PRINTF_DIR = ft_printf
LIBFT_DIR = libft
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINTF_SRCS = ft_printf/ft_logic.c ft_printf/ft_main_logic.c ft_printf/ft_printf.c ft_printf/ft_putstr.c ft_printf/ft_write_type.c ft_printf/ft_itoa_base.c ft_printf/ft_check.c
PRINTF_OBJ = $(PRINTF_SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRCS = libft/ft_atoi.c libft/ft_itoa.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c \
       libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memchr.c \
       libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
       libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c \
       libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c \
       libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
       libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c

SRC = main.c ft_strcmp.c ft_atof.c ft_strisalpha.c ft_julia.c ft_mandelbrot.c ft_arg_check.c ft_destroy_and_close.c ft_check_error.c ft_creation.c ft_display.c ft_init_graphic.c ft_main_loops.c ft_set_and_assign.c ft_set_framework.c ft_struct_init.c
OBJS = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

GREEN = \033[1;32m

all:  $(LIBFT) $(PRINTF) $(MINILIBX) $(NAME)

$(LIBFT): $(LIBFT_SRCS)
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF): $(PRINTF_SRCS) $(LIBFT)
	@$(MAKE) -C $(PRINTF_DIR)


$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR)

%.o: %.c
	@echo "Compilando $< → $@"
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJS) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) $(LIBFT) $(PRINTF)
	@echo "$(GREEN)Fractol successfully compiled"

-include $(DEP)

clean:
	@rm -f $(OBJS)
	@rm -f $(DEP)
	@rm -f $(LIBFT_OBJ)
	@rm -f $(LIBFT_DEP)
	@rm -f $(PRINTF_OBJ)
	@echo "Archivos objeto eliminados."

fclean:
	@rm -f $(LIBFT)
	@echo "Ejecutables eliminados para libft."
	@rm -f $(PRINTF)
	@echo "Ejecutables eliminados para ft_printf."
	@rm -f $(NAME)
	@echo "Ejecutables eliminados para fractol."
	@rm -f $(DEP)

re:
	fclean all

.PHONY: all clean fclean re

