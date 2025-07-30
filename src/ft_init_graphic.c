/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_graphic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:29:05 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 20:29:15 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_init_graphic(t_fract *f)
{
	f->init_graphic = mlx_init();
	if (!f->init_graphic)
		ft_check_error(3, f);
	return (0);
}
