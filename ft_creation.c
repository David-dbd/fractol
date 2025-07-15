#include "fractol.h"

int ft_creation(t_fract *f)
{
    f->window = mlx_new_window(f->init_graphic, WIDTH, HEIGTH, "Fractol");
    f->buffer_img = mlx_new_image(f->init_graphic, WIDTH, HEIGTH);
    if (!f->window || !f->buffer_img)
        ft_check_error(3);
    return (0);
}