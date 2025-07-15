#include "fractol.h"

char ft_arg_check(int argc, char **argv)
{
    char c;

    c = 'm';
    if (argc == 2)
    {
        if (strcmp(argv[2], "mandelbrot") != 0)
            ft_check_error(1);
    }
    else if (argc == 5)
    {
        if (strcmp(argv[1], "julia") != 0)
            ft_check_error(1);
        else
        {
            if (ft_strisalpha(argv[2]) == -1 || ft_strisalpha(argv[4]) == -1)
                ft_check_error(1);
            if (argv[3][0] != 'x')
                ft_check_error(1);
        }
        c = 'j';
    }
    return (c);
}