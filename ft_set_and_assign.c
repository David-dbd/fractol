#include "fractol.h"

static int ft_key_handler(int key, t_fract *f)
{
    if (key == ESC_KEY)
        exit(EXIT_SUCCESS);
    else if (key != ESC_KEY)
        ft_check_error(2);
    return (0);
}


static int ft_mouse_handler(int mouse_key, int x, int y, t_frac *f)
{
    if (mouse_key == SCROLL_UP) //4
        f->zoom *= 1.1;
    else if (mouse_key == SCROLL_DOWN) //5
        f->zoom /= 1.1;
    return (0);
}

static void ft_close_handler(t_fract *f)
{
    f->cor_real = 0;
    f->cor_imaginary = 0;
    f->flag_escapes = 0;
    f->color = 0;
    f->zoom = 0;
    f->*init_graphic = NULL;
    f->*window = NULL;
    f->*buffer_img = NULL;
    f->bpp = 0;
    f->size_line = 0;
    exit(EXIT_SUCCESS);
}

ft_set_and_assign(t_fract *f)
{
    int endian;

    mlx_hook(f->window, 17, 0, ft_close_handler, f);
    f->ptr_buf_img = mlx_get_data_addr(f->buffer_image, &f->bpp, &f->size_line, &endian);
    if (!f->ptr_buf_img)
        ft_check_error(f->ptr_buf_img, 3);
    mlx_key_hook(f->window, ft_key_handler, f);
    mlx_mouse_hook(f->window, ft_mouse_handler, f);
    return (0);
}