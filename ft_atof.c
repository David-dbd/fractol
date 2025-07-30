/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:02:21 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 22:34:12 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static void	ft_fraction(const char *str, int *i, double *frac, double *res)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*frac /= 10.0;
		*res += (str[*i] - '0') * (*frac);
		(*i)++;
	}
}

static double	ft_auxiliar(double result, int *error)
{
	if (fabs(result) > HUGE_VAL || fabs(result) < -HUGE_VAL)
		*error = -1;
	return (result);
}

static void	ft_ignore(const char *str, int *i, int *sign)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

double	ft_atof(const char *str, int *error)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	result = 0.0;
	fraction = 1.0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	ft_ignore(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		ft_fraction(str, &i, &fraction, &result);
	}
	return (ft_auxiliar(result * sign, error));
}
