#include "fractol.h"

int ft_set_framework(t_fract *f, char c)
{
    f->counter = 1;
    if (c == 'm')
    {
        f->min_re = -2.0;
        f->max_re = 1.0;
        f->min_im = -1.2;
        f->max_im = 1.2;
    }
    else if (c == 'j')
    {
        f->min_re = -2.0;
        f->max_re = 2.0;
        f->min_im = -1.5;
        f->max_im = 1.5;
    }
    return (0);
}