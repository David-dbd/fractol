/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_framework.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:01:56 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/30 02:10:30 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_set_framework(t_fract *f)
{
	f->counter = 1;
	if (f->c == 'm')
	{
		f->min_re = -2.0;
		f->max_re = 1.0;
		f->min_im = -1.2;
		f->max_im = 1.2;
	}
	else if (f->c == 'j')
	{
		f->min_re = -1.5;
		f->max_re = 1.5;
		f->min_im = -1.5;
		f->max_im = 1.5;
	}
	else if (f->c == 'b')
	{
		f->min_re = -2.8;
		f->max_re = 2.2;
		f->min_im = -2.2;
		f->max_im = 1.8;
	}
	return (0);
}
