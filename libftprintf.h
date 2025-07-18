/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:21:41 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/03/22 15:57:27 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_main_logic(va_list args, const char *format, int count, int ver);
int		ft_check(const char *format, int *i);
int		ft_logic(va_list args, char x);
int		ft_write_type(int len, char *result);
char	*ft_itoa_base(unsigned long int n, int base, int indicador);
void	ft_putstr(char *s);
#endif
