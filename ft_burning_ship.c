/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:10:54 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 23:12:04 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_burningship_equation(t_fract *f)
{
	double	zx;
	double	zy;
	double	temp;
	int		i;
	int		max;

	zx = 0.0;
	zy = 0.0;
	i = 0;
	max = 300;
	f->flag_escapes = 0;
	while (i < max)
	{
		if (zx * zx + zy * zy > 4.0)
		{
			f->flag_escapes = 1;
			return (i);
		}
		temp = zx * zx - zy * zy + f->cor_real;
		zy = fabs(2.0 * zx * zy) + f->cor_im;
		zx = fabs(temp);
		i++;
	}
	f->flag_escapes = 0;
	return (0);
}

int	ft_burningship(t_fract *f, int y, int x)
{
	int	i;

	f->cor_real = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
	f->cor_im = f->min_im + y * (f->max_im - f->min_im) / HEIGTH;
	i = ft_burningship_equation(f);
	return (i);
}
