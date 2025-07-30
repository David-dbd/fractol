/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_and_assign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:54:18 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 23:39:41 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_expose_handler(t_fract *f)
{
	ft_display(f);
	return (0);
}

static int	ft_key_handler(int key, t_fract *f)
{
	static int	i = 0;

	if (key == ESC_KEY)
	{
		ft_destroy_and_close(f);
		exit(EXIT_SUCCESS);
	}
	else if (key == ENTER_KEY && i == 0)
	{
		i++;
		return (0);
	}
	else
		ft_check_error(2, f);
	return (0);
}

static int	ft_mouse_handler(int mouse_key, int x, int y, t_fract *f)
{
	if (mouse_key == SCROLL_UP)
	{
		f->zoom *= 1.05;
		f->counter++;
	}
	else if (mouse_key == SCROLL_DOWN)
	{
		f->zoom /= 1.05;
		if (f->counter > -20)
			f->counter--;
	}
	else
	{
		ft_check_error(2, f);
		return (0);
	}
	ft_zoom(f, x, y);
	ft_main_loops_mouse(f);
	ft_display(f);
	return (0);
}

static int	ft_close_handler(t_fract *f)
{
	ft_destroy_and_close(f);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_set_and_assign(t_fract *f)
{
	int	e;

	mlx_hook(f->window, 17, 0, ft_close_handler, f);
	f->ptr_buf_img = mlx_get_data_addr(f->buffer_img, &f->bpp, &f->size_l, &e);
	if (!f->ptr_buf_img)
		ft_check_error(3, f);
	mlx_key_hook(f->window, ft_key_handler, f);
	mlx_mouse_hook(f->window, ft_mouse_handler, f);
	mlx_expose_hook(f->window, ft_expose_handler, f);
	return (0);
}
