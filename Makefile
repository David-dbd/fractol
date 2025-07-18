# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: DAVID <DAVID@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 20:03:43 by davdiaz-          #+#    #+#              #
#    Updated: 2025/07/10 12:44:47 by davdiaz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

LIBFT_DIR = libft

PRINTF_DIR = ft_printf

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
LIBFT_OBJ = $(LIBFT_SRCS:.c=.o)
LIBFT_DEP = $(LIBFT_SRCS:.c=.d)

FUNC 	= main.c ft_buffer_creation.c ft_strisalpha.c ft_unsort.c ft_range.c ft_new_median.c ft_ss.c ft_count_elements.c ft_free_data_set.c ft_greater_than_pivot.c ft_check_error.c ft_free_stacks.c ft_how_far.c ft_better_mediana.c ft_mediana.c ft_search.c ft_send_organize.c ft_recive_organize.c ft_data_base.c ft_deep_search_creation.c ft_abs.c ft_push_a.c ft_push_b.c ft_ra.c ft_rra.c ft_rb.c ft_rrb.c ft_swap_a.c ft_swap_b.c ft_small_stack_a.c ft_small_stack_b.c ft_three_elements.c ft_quick_sort_a.c ft_quick_sort_b.c ft_strcmp.c ft_strtol.c

OBJS = $(FUNC:.c=.o)

DEP = $(FUNC:.c=.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -MMD -MP

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT): $(LIBFT_SRCS)
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF): $(PRINTF_SRCS) $(LIBFT)
	@$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	@echo "Compilando $< → $@"
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)
	@echo "push_swap compilado correctamente."

-include $(DEP)

clean:
	@rm -f $(OBJS)
	@rm -f $(DEP)
	@rm -f $(LIBFT_OBJ)
	@rm -f $(LIBFT_DEP)
	@rm -f $(PRINTF_OBJ)
	@echo "Archivos objeto eliminados."

fclean: clean
	@rm -f $(LIBFT)
	@echo "Ejecutables eliminados para libft."
	@rm -f $(PRINTF)
	@echo "Ejecutables eliminados para ft_printf."
	@rm -f $(NAME)
	@echo "Ejecutables eliminados para push_swap."

re: fclean all

.PHONY: all clean fclean re comp
