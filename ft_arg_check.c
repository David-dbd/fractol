/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:35:58 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 23:13:12 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	ft_check_julia(char **argv, t_fract *f)
{
	int	error;

	if (ft_strisalpha(argv[2]) == -1 || ft_strisalpha(argv[3]) == -1)
		ft_check_error(1, f);
	f->julia_re = ft_strtol(argv[2], &error);
	if (error == -1)
		ft_check_error(1, f);
	f->julia_im = ft_strtol(argv[3], &error);
	if (error == -1)
		ft_check_error(1, f);
}

void	ft_arg_check(int argc, char **argv, t_fract *f)
{
	f->c = 'm';
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			f->c = 'm';
		else if (ft_strcmp(argv[1], "burningship") == 0)
			f->c = 'b';
		else
			ft_check_error(1, f);
	}
	else if (argc == 4)
	{
		if (ft_strcmp(argv[1], "julia") != 0)
			ft_check_error(1, f);
		else
			ft_check_julia(argv, f);
		f->c = 'j';
	}
	else
		ft_check_error(1, f);
}
