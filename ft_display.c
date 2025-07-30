/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:28:40 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 20:28:49 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_display(t_fract *f)
{
	mlx_put_image_to_window(f->init_graphic, f->window, f->buffer_img, 0, 0);
	return (0);
}
