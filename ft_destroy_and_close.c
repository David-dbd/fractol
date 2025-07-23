#include "fractol.h"

void ft_destroy_and_close(t_fract *f)
{
    if (f->ptr_buf_img)
        mlx_destroy_image(f->init_graphic, f->ptr_buf_img);
    if (f->window)
        mlx_destroy_window(f->init_graphic, f->window);
    if (f->init_graphic)
        mlx_destroy_display(f->init_graphic);
}