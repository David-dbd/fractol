/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:23:10 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/30 04:14:25 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_color3(t_fract *f, int i)
{
	int	color_arr[10];

	color_arr[0] = 0x3c2f2f;
	color_arr[1] = 0x654321;
	color_arr[2] = 0x9e6b30;
	color_arr[3] = 0xdb9034;
	color_arr[4] = 0xf4b860;
	color_arr[5] = 0xfceabb;
	color_arr[6] = 0xc0e5c8;
	color_arr[7] = 0x7abfb0;
	color_arr[8] = 0x3e8c84;
	color_arr[9] = 0x1a4851;
	f->color = color_arr[i % 10];
}

static void	ft_color2(t_fract *f, int i)
{
	int	color_arr[10];

	color_arr[0] = 0x040f0f;
	color_arr[1] = 0x14532d;
	color_arr[2] = 0x1f9c67;
	color_arr[3] = 0x2fdcba;
	color_arr[4] = 0x6ef2e9;
	color_arr[5] = 0x7e9df0;
	color_arr[6] = 0x5371d4;
	color_arr[7] = 0x3e3cb8;
	color_arr[8] = 0x562f94;
	color_arr[9] = 0x7a1fa2;
	f->color = color_arr[i % 10];
}

void	ft_color(t_fract *f, int i)
{
	int	color_arr[10];

	color_arr[0] = 0x000004;
	color_arr[1] = 0x1b0c41;
	color_arr[2] = 0x4a0c6b;
	color_arr[3] = 0x781c6d;
	color_arr[4] = 0xa52c60;
	color_arr[5] = 0xcf4446;
	color_arr[6] = 0xed6925;
	color_arr[7] = 0xfb9b06;
	color_arr[8] = 0xf7d13d;
	color_arr[9] = 0xfcffa4;
	if (f->flag_escapes == 1)
	{
		if (i > 0 && f->counter < 5)
			f->color = color_arr[i % 10];
		else if (i > 0 && f->counter >= 5 && f->counter < 8)
			ft_color2(f, i);
		else if (i > 0 && f->counter >= 8)
			ft_color3(f, i);
	}
	else if (f->flag_escapes == 0)
		f->color = 0x000000;
}
