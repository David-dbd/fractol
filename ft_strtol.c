/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DAVID <DAVID@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:40:28 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 21:03:43 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_auxiliar(int sign, long result, int *error)
{
	*error = 0;
	if ((sign == 1 && result > INT_MAX)
		|| (sign == -1 && result > (long)INT_MAX + 1))
	{
		*error = -1;
		return (-1);
	}
	return (0);
}

static int	ft_ignore(int i, char *str, int *sign)
{
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

static	void	ft_verify(char *str, int i, int *error)
{
	if (str[i] == '\0' || (str[i] >= 0 && str[i] < 48) || str[i] > 57)
		*error = -1;
}

int	ft_strtol(char *str, int *error)
{
	long int	result;
	int			i;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	if (ft_strlen(str) == 2)
	{
		if (str[0] == '-' && str[1] == '0')
			*error = -1;
		return (-1);
	}
	i = ft_ignore(i, str, &sign);
	ft_verify(str, i, error);
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (ft_auxiliar(sign, result, error) == -1)
			return (0);
	}
	return (sign * result);
}
