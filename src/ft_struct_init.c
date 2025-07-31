/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DAVID <DAVID@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:03:59 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/31 19:40:18 by DAVID            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_struct_init(t_fract *f)
{
	f->cor_real = 0;
	f->cor_im = 0;
	f->ptr_buf_img = NULL;
	f->flag_escapes = 0;
	f->color = 0;
	f->flag = 0;
	f->init_graphic = NULL;
	f->window = NULL;
	f->buffer_img = NULL;
	f->bpp = 32;
	f->size_l = 0;
	f->zoom = 1;
	f->max_re = 0;
	f->min_re = 0;
	f->max_im = 0;
	f->min_im = 0;
	f->julia_re = 0;
	f->julia_im = 0;
	f->counter = 0;
	return (0);
}
