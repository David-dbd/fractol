/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:55:54 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/05/23 15:36:38 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	ft_check(const char *format, int *i)
{
	int	count;
	int	start;
	int	pairs;

	pairs = 0;
	count = 0;
	start = *i;
	while (format[start + count] == '%')
		count++;
	if (count < 2)
		return (0);
	pairs = count / 2;
	*i += pairs * 2;
	return (pairs);
}
