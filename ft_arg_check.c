#include "fractol.h"

char ft_arg_check(int argc, char **argv, t_fract *f)
{
    char c;

    c = 'm';
    if (argc == 2)
    {
        if (ft_strcmp(argv[2], "mandelbrot") != 0)
            ft_check_error(1, f);
    }
    else if (argc == 5)
    {
        if (ft_strcmp(argv[1], "julia") != 0)
            ft_check_error(1, f);
        else
        {
            if (ft_strisalpha(argv[2]) == -1 || ft_strisalpha(argv[4]) == -1)
                ft_check_error(1, f);
            if (argv[3][0] != 'x')
                ft_check_error(1, f);
        }
        c = 'j';
    }
    return (c);
}