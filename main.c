/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:06:46 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 21:13:17 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_check_size(void)
{
	if (WIDTH < 1 || HEIGTH < 1)
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fract	f;

	ft_check_size();
	ft_arg_check(argc, argv, &f);
	ft_struct_init(&f);
	ft_init_graphic(&f);
	ft_creation(&f);
	ft_set_framework(&f);
	ft_set_and_assign(&f);
	ft_main_loops(argv, &f);
	ft_display(&f);
	mlx_loop(f.init_graphic);
	return (0);
}
