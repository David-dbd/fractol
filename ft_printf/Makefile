# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 19:33:09 by davdiaz-          #+#    #+#              #
#    Updated: 2025/07/10 12:19:18 by davdiaz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT_SRCS = libft/ft_atoi.c libft/ft_itoa.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c \
       libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memchr.c \
       libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
       libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c \
       libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c \
       libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
       libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c

INC_DIR = includes
SRCS = ft_logic.c ft_main_logic.c ft_printf.c ft_putstr.c ft_write_type.c ft_itoa_base.c ft_check.c
OBJS = $(SRCS:.c=.o)
DEP = $(SRCS:.c=.d)
LIBFT = $(LIBFT_DIR)/libft.a
NAME = libftprintf.a

all: $(LIBFT) $(NAME)

# Compila Libft antes de compilar ft_printf
$(LIBFT): $(LIBFT_SRCS)
	@$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) ./$(NAME)

# Regla para compilar los archivos .c en .o
%.o: %.c
	@echo "Compilando $< → $@"
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -c $< -o $@

# Regla para crear la biblioteca libftprintf.a
$(NAME): $(OBJS) $(LIBFT)
	@$(MAKE) -C $(LIBFT_DIR)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

-include $(DEP)

# Reglas de limpieza
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f libft.a

re: fclean all

# Indicar que ciertas reglas no son archivos
.PHONY: all clean fclean re
