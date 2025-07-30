/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:11:04 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/30 10:01:45 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*aunque el zoom y el metodo en el que saca el fractal 
no tienen relacion, el zoom comparte 
una propiedad de base con el tipo de fractal. 
Esta propiedad viene a ser el marco en el 
que este se genera, creando una relacion entre 
el zoom desde ese marco en 
adelante o hacia atras (zoom in zoom out). 
Por ende, ambos se calculan de la misma manera*/
int	ft_zoom(t_fract *f, int x, int y)
{
	double	new_width;
	double	new_heigth;

	f->mouse_real_cor = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
	f->mouse_im_cor = f->max_im - y * (f->max_im - f->min_im) / HEIGTH;
	new_width = (f->max_re - f->min_re) / f->zoom;
	new_heigth = (f->max_im - f->min_im) / f->zoom;
	f->min_re = f->mouse_real_cor - new_width / 2.0;
	f->max_re = f->mouse_real_cor + new_width / 2.0;
	f->min_im = f->mouse_im_cor - new_heigth / 2.0;
	f->max_im = f->mouse_im_cor + new_heigth / 2.0;
	return (0);
}

/*
int	ft_zoom(t_fract *f)
{
	double	center_real;
	double	center_im;
	double	new_width;
	double	new_height;

	center_real = (f->min_re + f->max_re) / 2.0;
	center_im = (f->min_im + f->max_im) / 2.0;
	new_width = (f->max_re - f->min_re) / f->zoom;
	new_height = (f->max_im - f->min_im) / f->zoom;
	f->min_re = center_real - new_width / 2.0;
	f->max_re = center_real + new_width / 2.0;
	f->min_im = center_im - new_height / 2.0;
	f->max_im = center_im + new_height / 2.0;
	return (0);
}*/
