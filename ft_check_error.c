#include "fractol.h"

static void ft_invalid_arg(void)
{
    /*This function is only to check if the user inputs invalid argv like julia and madelbrot
    at the same time or any other invalid thing before execution*/
    perror("Invalid input from user\n");
    ft_printf("Available input: \n* Type of fractal: Julia or Mandelbrot \n*If you choose Julia, then add: one coordinate separated by 'x' and space Eg. 3 x 4\n");
}

static void ft_error_ms(void)
{
    /*This function is only to display the available commands when 
    the user inputs a wrong command during execution*/
    perror("Invalid command.\n");
    ft_printf("Available commands: \n* ESC -> Terminate the program \n*Zoom in \n*Zoom out");
}

static void ft_something_wrong(void)
{
    /*This function is only to highligth if something went wrong during the set up of every functon*/
    perror("Something went wrong. Please try again.\n");
}

void ft_check_error(int error, t_fract *f)
{
    if (error == 1)
        ft_invalid_arg();
    else if (error == 2)
        ft_error_ms();
    else if (error == 3)
        ft_something_wrong();
    ft_destroy_and_close(f);
    exit(EXIT_FAILURE);
}