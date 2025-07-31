/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DAVID <DAVID@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:39:31 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/31 20:04:17 by DAVID            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_apply_color(t_fract *f, int x, int y)
{
	int	offset;

	offset = 0;
	offset = y * f->size_l + x * (f->bpp / 8);
	*(int *)(f->ptr_buf_img + offset) = f->color;
}

int	ft_main_loops(t_fract *f)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	/*Here we are going throuhg the whole screen, pixel by pixel, line by line.
	First we map the pixels to the complex map -> c = x + yi.
	Secondly we apply the formula z_n+1 = z_2 + c
	Third, we choose the color and apply it to the buffer*/
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (f->type == 'j')
				i = ft_julia(f, y, x);
			else if (f->type == 'm')
				i = ft_mandelbrot(f, y, x);
			else if (f->type == 'b')
				i = ft_burningship(f, y, x);
			ft_color(f, i);
			ft_apply_color(f, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
