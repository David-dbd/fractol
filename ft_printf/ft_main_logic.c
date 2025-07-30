/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:20:45 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/03/22 16:47:06 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static void	ft_write_percent(int verify)
{
	char	c;
	int		i;

	c = '%';
	i = verify;
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

static int	write_character(int i, int *counter, const char *format)
{
	write(1, &format[i], 1);
	(*counter)++;
	i++;
	return (i);
}

static int	check_verify(int verify)
{
	int	i;

	i = 0;
	ft_write_percent(verify);
	i += verify;
	return (i);
}

static int	if_logic(int *i, int *counter, const char *format, va_list args)
{
	int	verify;

	verify = ft_logic(args, format[*i + 1]);
	if (verify == -1)
	{
		return (-1);
	}
	else
	{
		(*counter) += verify;
	}
	return (0);
}

int	ft_main_logic(va_list args, const char *format, int counter, int verify)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			verify = ft_check(format, &i);
			if (verify)
				counter += check_verify(verify);
			else if ((format[i + 1] == ' ') || (format[i + 1] == '\0'))
				return (-1);
			else
			{
				if (if_logic(&i, &counter, format, args) == -1)
					return (-1);
				i += 2;
			}
		}
		else
			i = write_character(i, &counter, format);
	}
	return (counter);
}
