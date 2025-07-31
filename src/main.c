/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DAVID <DAVID@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:06:46 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/31 19:52:59 by DAVID            ###   ########.fr       */
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

	ft_check_size(); //Check just in case user changes the size of the window
	ft_arg_check(argc, argv, &f); //Check if the user inputs a valid argument
	ft_struct_init(&f); //Initialize the struct with default values
	ft_init_graphic(&f); //Initialize the graphic library
	ft_creation(&f); //Create the window and the buffer image
	ft_set_framework(&f); //Set the framework values based on the fractal type
	ft_set_and_assign(&f); //Set the keys and assign the functions/behaviors
	f.argv = argv;
	ft_main_loops(&f); //Main loop to calculate the type of fractal and display it
	ft_display(&f); //Display the initial fractal
	mlx_loop(f.init_graphic); //Start the mlx loop to handle events and keep the window open
	return (0);
}
