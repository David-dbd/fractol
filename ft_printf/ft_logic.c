/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:05:24 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/03/22 18:38:00 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static char	*is_str(va_list args)
{
	char	*result;

	result = va_arg(args, char *);
	if (result == NULL)
	{
		return (ft_strdup("(null)"));
	}
	else
	{
		return (ft_strdup(result));
	}
}

static char	*is_ptr(va_list args)
{
	unsigned long	address;
	char			*ptr;
	char			*result;
	char			prefijo[3];
	char			*temp;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (ft_strdup("(nil)"));
	else
	{
		address = (unsigned long)ptr;
		result = ft_itoa_base(address, 0, 16);
		if (!result)
			result = NULL;
	}
	prefijo[0] = '0';
	prefijo[1] = 'x';
	prefijo[2] = '\0';
	temp = result;
	result = ft_strjoin(prefijo, result);
	free (temp);
	if (!result)
		result = NULL;
	return (result);
}

static void	is_char(va_list args, int *len)
{
	char	c;

	c = va_arg(args, int);
	len++;
	write(1, &c, 1);
}

static int	if_error(char *result)
{
	free (result);
	return (-1);
}

int	ft_logic(va_list args, char x)
{
	char	*result;
	int		len;

	if ((x == 'd') || (x == 'i'))
		result = ft_itoa(va_arg(args, int));
	else if (x == 's')
		result = is_str(args);
	else if (x == 'p')
		result = is_ptr(args);
	else if (x == 'c')
	{
		is_char(args, &len);
		return (1);
	}
	else if (x == 'x')
		result = ft_itoa_base(va_arg(args, unsigned int), 0, 16);
	else if (x == 'X')
		result = ft_itoa_base(va_arg(args, unsigned int), 1, 16);
	else if (x == 'u')
		result = ft_itoa_base(va_arg(args, unsigned int), 0, 10);
	if (result == NULL)
		if_error(result);
	len = ft_write_type(len, result);
	return (len);
}
