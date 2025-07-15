#include "fractol.h"

int ft_display(t_fract *f)
{
    mlx_put_image_to_window(f->init_graphic, f->window, f->buffer_img, 0, 0);
    return (0);
}