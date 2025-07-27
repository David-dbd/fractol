#include "fractol.h"

/*aunque el zoom y el metodo en el que saca el fractal no tienen relacion, el zoom comparte 
una propiedad de base con el tipo de fractal. Esta propiedad viene a ser el marco en el 
que este se genera, creando una relacion entre el zoom desde ese marco en 
adelante o hacia atras (zoom in zoom out). Por ende, ambos se calculan de la misma manera*/
static int ft_mouse_calc(t_fract *f, int x, int y)
{
    double new_width;
    double new_heigth;
    /*The mouse cor only works in the window dimensions, not the complex map*/
    /*We first find the mouse x - y position*/
    f->mouse_real_cor = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
    f->mouse_im_cor = f->max_im - y * (f->max_im - f->min_im) / HEIGTH;
    new_width  = (f->max_re - f->min_re) * f->zoom;/*We need to recalculate the dimensions of the complex map (NOT THE WINDOW OR IMAGE) with the zoom*/
    new_heigth = (f->max_im - f->min_im) * f->zoom;/*both new represent the new WIDTH and HEIGHT withing the complex map and when mulpitplying by zoom, we get the new size of the map*/
    f->min_re  = f->mouse_real_cor - new_width / 2.0;/*We use 2.0 because we want to divide in 2 halfs both x and y in context with the mouse*/
    f->max_re  = f->mouse_real_cor + new_width / 2.0;/*So this is the new frame based on the new size of the map*/
    f->min_im  = f->mouse_im_cor - new_heigth / 2.0;
    f->max_im  = f->mouse_im_cor + new_heigth / 2.0;
    return (0);
}

static int ft_key_handler(int key, t_fract *f)
{
    if (key == ESC_KEY)
    {
        ft_destroy_and_close(f);
        exit(EXIT_SUCCESS);
    }   
    else if (key != ESC_KEY)
        ft_check_error(2, f);
    return (0);
}

static int ft_mouse_handler(int mouse_key, int x, int y, t_fract *f)
{
    if (mouse_key == SCROLL_UP || mouse_key == SCROLL_DOWN)
    {
        if (mouse_key == SCROLL_UP) //4
        {
            f->zoom *= 1.1;
            if (f->counter <= 30)
                f->counter++;
        }
        else if (mouse_key == SCROLL_DOWN) //5
        {
            f->zoom /= 1.1;
            if (f->counter - 1 > 0)
                f->counter--;
        }
        ft_mouse_calc(f, x, y);
        ft_creation(f);
        ft_display(f);
    }
    return (0);
}

static int ft_close_handler(t_fract *f)
{
    ft_struct_init(f);
    ft_destroy_and_close(f);
    exit(EXIT_SUCCESS);
    return (0);
}

int ft_set_and_assign(t_fract *f)
{
    int endian;

    mlx_hook(f->window, 17, 0, ft_close_handler, f);
    f->ptr_buf_img = mlx_get_data_addr(f->buffer_img, &f->bpp, &f->size_line, &endian);
    if (!f->ptr_buf_img)
        ft_check_error(3, f);
    mlx_key_hook(f->window, ft_key_handler, f);
    mlx_mouse_hook(f->window, ft_mouse_handler, f);
    return (0);
}