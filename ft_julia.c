/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:29:27 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 20:32:27 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_julia_equation(t_fract *f, double z_real, double z_im)
{
	double	temp_real;
	int		i;
	int		max;

	i = 0;
	max = 100 + (f->counter * f->counter);
	while (i < max)
	{
		temp_real = z_real * z_real - z_im * z_im;
		z_im = 2.0 * z_real * z_im;
		z_real = temp_real;
		z_real += f->julia_re;
		z_im += f->julia_im;
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
/*z = x + yi*/

int	ft_julia(char **argv, t_fract *f, int y, int x)
{
	double	z_real;
	double	z_im;
	int		i;
	int		error;

	i = 0;
	if (f->type == 0)
	{
		f->julia_re = ft_atof(argv[2], &error);
		if (error == -1 || f->julia_re > 2.0 || f->julia_re < -2.0)
			ft_check_error(1, f);
		f->julia_im = ft_atof(argv[3], &error);
		if (error == -1 || f->julia_im > 2.0 || f->julia_im < -2.0)
			ft_check_error(1, f);
		f->type = 1;
	}
	f->cor_real = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
	f->cor_im = f->max_im - y * (f->max_im - f->min_im) / HEIGTH;
	z_real = f->cor_real;
	z_im = f->cor_im;
	i = ft_julia_equation(f, z_real, z_im);
	return (i);
}
