/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DAVID <DAVID@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:04:37 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/31 19:55:16 by DAVID            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_mandelbrot_equation(t_fract *f, int max, int i)
{
	double	z_real;
	double	z_im;
	double	temp_real;

	z_real = 0.0;
	z_im = 0.0;
	while (i < max)
	{
		temp_real = z_real * z_real - z_im * z_im;
		z_im = 2.0 * z_real * z_im;
		z_real = temp_real;
		z_real += f->cor_real;
		z_im += f->cor_im;
		if (z_real * z_real + z_im * z_im > 4.0)
		{
			f->flag_escapes = 1;
			return (i);
		}
		i++;
	}
	f->flag_escapes = 0;
	return (0);
}

int	ft_mandelbrot(t_fract *f, int y, int x)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 30;
	f->cor_real = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
	f->cor_im = f->max_im - y * (f->max_im - f->min_im) / HEIGTH;
	i = ft_mandelbrot_equation(f, max, j);
	return (i);
}
