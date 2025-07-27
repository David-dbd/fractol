#include "fractol.h"

int ft_set_framework(t_fract *f)
{
    f->counter = 1;
    if (f->c == 'm')
    {
        f->min_re = -2.0;
        f->max_re = 1.0;
        f->min_im = -1.2;
        f->max_im = 1.2;
    }
    else if (f->c == 'j')
    {
        f->min_re = -2.0;
        f->max_re = 2.0;
        f->min_im = -1.5;
        f->max_im = 1.5;
    }
    return (0);
}