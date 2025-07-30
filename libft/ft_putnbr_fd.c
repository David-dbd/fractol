/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:44:58 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/29 19:23:58 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	num_sorting(char *s, int len)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

static int	is_negative(int n, char *x)
{
	unsigned int	m;
	int				len;

	len = 0;
	if (n < 0)
		m = -n;
	else
		m = n;
	if (n == 0)
	{
		x[len++] = '0';
	}
	else
	{
		while (m > 0)
		{
			x[len++] = (m % 10) + '0';
			m /= 10;
		}
	}
	if (n < 0)
		x[len++] = '-';
	return (len);
}

void	ft_putnbr_fd(int i, int fd)
{
	char	x[12];
	int		len;

	len = is_negative(i, x);
	num_sorting(x, len);
	x[len] = '\0';
	write(fd, x, len);
}
/*
#include <unistd.h>

void ft_putnbr_fd(int i, int fd);

int main(void)
{
    // Prueba con números positivos
    ft_putnbr_fd(12345, STDOUT_FILENO);
    write(STDOUT_FILENO, "\n", 1);

    // Prueba con números negativos
    ft_putnbr_fd(-67890, STDOUT_FILENO);
    write(STDOUT_FILENO, "\n", 1);

    // Prueba con el número cero
    ft_putnbr_fd(0, STDOUT_FILENO);
    write(STDOUT_FILENO, "\n", 1);

    return 0;
}
*/
