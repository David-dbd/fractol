/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DAVID <DAVID@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:29:27 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/31 19:59:40 by DAVID            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_julia_equation(t_fract *f, double z_real, double z_im)
{
	double	temp_real;
	int		i;
	int		max;

	i = 0;
	/*max will be the number of iterations we want to calculate and it will be 
	proportional to the zoom counter to bring more detail when needed*/
	max = 100 + (f->counter * f->counter);
	while (i < max)
	{
		//Here we are using algebra to replace the use of pow(); -> z = z^2 + c
		temp_real = z_real * z_real - z_im * z_im;
		z_im = 2.0 * z_real * z_im;
		z_real = temp_real;
		z_real += f->julia_re;
		z_im += f->julia_im;
		//Here we are using algebra to replace the use of sqrt(); -> |z|^2 = z * z
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

int	ft_julia(t_fract *f, int y, int x)
{
	double	z_real;
	double	z_im;
	int		i;
	int		error;

	i = 0;
	if (f->flag == 0) //Althhough we already checked with strtol, now we need to convert the input to double
	{
		f->julia_re = ft_atof(f->argv[2], &error);
		if (error == -1 || f->julia_re > 2.0 || f->julia_re < -2.0)
			ft_check_error(1, f);
		f->julia_im = ft_atof(f->argv[3], &error);
		if (error == -1 || f->julia_im > 2.0 || f->julia_im < -2.0)
			ft_check_error(1, f);
		f->flag = 1;
	}
	//We are mapping the pixel coordinates to the complex plane
	f->cor_real = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
	f->cor_im = f->max_im - y * (f->max_im - f->min_im) / HEIGTH;
	z_real = f->cor_real;
	z_im = f->cor_im;
	i = ft_julia_equation(f, z_real, z_im);
	return (i);
}
