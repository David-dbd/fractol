/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:13:20 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 20:23:00 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*This function is only to check if the user inputs invalid argv
like julia and madelbrot at the same time or any other invalid
thing before execution*/
static	void	ft_invalid_arg(void)
{
	ft_printf("\nInvalid input from user\n\n");
	ft_printf("Available input: \n\n");
	ft_printf("* Type of fractal: Julia - Mandelbrot - Burningship\n\n");
	ft_printf("* If you choose Julia, then add: \n");
	ft_printf("  one coordinate separated by space.\n\n");
	ft_printf("* Egs. \n  ./fractol julia -0.7 0.5675\n");
	ft_printf("  ./fractol julia -0.8 0.156 \n");
	ft_printf("  ./fractol julia -0.4 0.6 \n");
	ft_printf("  ./fractol julia -0.75 0.11\n");
	ft_printf("  ./fractol julia 0.285 0\n\n");
	ft_printf("* Please note values can go from -2.0 - 2.0\n\n");
}

/*This function is only to display the available commands when
the user inputs a wrong command during execution*/
static void	ft_error_ms(void)
{
	ft_printf("\nInvalid command.\n\n");
	ft_printf("Available commands: \n");
	ft_printf("* ESC->Terminate the program \n* Zoom in \n* Zoom out \n");
}

/*This function is only to highligth if something
went wrong during the set up of every functon*/
static void	ft_something_wrong(void)
{
	perror("\nSomething went wrong. Please try again.\n");
}

void	ft_check_error(int error, t_fract *f)
{
	errno = 0;
	if (error == 1)
		ft_invalid_arg();
	else if (error == 2)
	{
		ft_error_ms();
		return ;
	}
	else if (error == 3)
	{
		ft_something_wrong();
		ft_destroy_and_close(f);
	}
	exit(EXIT_FAILURE);
}
