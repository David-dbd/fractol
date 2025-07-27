#include "fractol.h"

void ft_arg_check(int argc, char **argv, t_fract *f)
{
    f->c = 'm';
    if (argc == 2)
    {
        if (ft_strcmp(argv[1], "mandelbrot") != 0)
            ft_check_error(1, f);
    }
    else if (argc == 4)
    {
        if (ft_strcmp(argv[1], "julia") != 0)
            ft_check_error(1, f);
        else
        {
            if (ft_strisalpha(argv[2]) == -1 || ft_strisalpha(argv[3]) == -1)
                ft_check_error(1, f);
        }
        f->c = 'j';
    }
    else
        ft_check_error(1, f);
}