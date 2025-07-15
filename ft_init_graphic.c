#include "fractol.h"

int ft_init_graphic(t_fract *f)
{
    f->init_graphic = mxl_init();
    if (!f->init_graphic)
        ft_check_error(3);
    return (0);
}