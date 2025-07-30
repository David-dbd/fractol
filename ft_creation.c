/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:27:09 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 20:27:24 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_creation(t_fract *f)
{
	f->window = mlx_new_window(f->init_graphic, WIDTH, HEIGTH, "Fractol");
	f->buffer_img = mlx_new_image(f->init_graphic, WIDTH, HEIGTH);
	if (!f->window || !f->buffer_img)
		ft_check_error(3, f);
	mlx_do_sync(f->init_graphic);
	return (0);
}
