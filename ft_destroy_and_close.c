/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_and_close.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DAVID <DAVID@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:27:49 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/31 20:00:26 by DAVID            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_destroy_and_close(t_fract *f)
{
	if (f->buffer_img)
	{
		mlx_destroy_image(f->init_graphic, f->buffer_img);
		f->buffer_img = NULL;
	}
	if (f->window)
	{
		mlx_destroy_window(f->init_graphic, f->window);
		f->window = NULL;
	}
	if (f->init_graphic)
	{
		mlx_destroy_display(f->init_graphic);
		free (f->init_graphic); //We want to manually free since the library might not free all the memory
	}
}
