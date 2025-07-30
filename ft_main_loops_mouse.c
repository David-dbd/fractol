/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loops_mouse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:44:04 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 23:19:51 by davdiaz-         ###   ########.fr       */
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

int	ft_main_loops_mouse(t_fract *f)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (f->c == 'j')
				i = ft_julia(NULL, f, y, x);
			else if (f->c == 'm')
				i = ft_mandelbrot(f, y, x);
			else if (f->c == 'b')
				i = ft_burningship(f, y, x);
			ft_color(f, i);
			ft_apply_color(f, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
