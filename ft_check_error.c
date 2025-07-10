#include "fractol.h"

static void ft_invalid_arg(void)
{
    /*This function is only to check if the user inputs invalid argv like julia and madelbrot
    at the same time or any other invalid thing before execution*/
    perror("Invalid input from user\n");
    printf("Available input: \n* Type of fractal: Julia or Mandelbrot \n*If you choose Julia, then add: one coordinate separated by 'x' and space Eg. 3 x 4\n");
    exit(EXIT_FAILURE);
}

static void ft_error_ms(void)
{
    /*This function is only to display the available commands when 
    the user inputs a wrong command during execution*/
    perror("Invalid command.\n");
    printf("Available commands: \n* ESC -> Terminate the program \n*Zoom in \n*Zoom out");
    exit(EXIT_FAILURE);
}

static void ft_something_wrong(void)
{
    /*This function is only to highligth if something went wrong during the set up of every functon*/
    perror("Something went wrong. Please try again.\n");
    exit(EXIT_FAILURE);
}

void ft_error(int n)
{
    if (n == 1)
        ft_check_arg();
    else if (n == 2)
        ft_error_ms();
    else if (n == 3)
        ft_something_wrong();
    return (0);
}