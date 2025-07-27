#include "fractol.h"

static void ft_color(t_fract *f, int i)
{
    int color_arr[] = {0x220022, 0x442288, 0x88FFAA, 0xFFFFBB, 0xEE88CC, 0x336666, 0xDDCC88, 0x553377};
    if (f->flag_escapes == 1)
    {
        if (i > 0)
            f->color = color_arr[i % 8];
    }
    else if (f->flag_escapes == 0)
        f->color = 0x000000;
}

int ft_main_loops(char **argv, t_fract *f)
{
    int offset;
    int x;
    int y;
    int i;

    y = 0;
    offset = 0;
    while (y < HEIGTH)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (ft_strcmp("julia", argv[1]) == 0)
                i = ft_julia(argv, f, y, x);
            else if (ft_strcmp("mandelbrot", argv[1]) == 0)
                i = ft_mandelbrot(f, y, x); /*aply c to the z equation. it returns the iteration number*/
            ft_color(f, i); /*apply the color*/
            offset = y * f->size_line + x * (f->bpp / 8);
            *(int *)(f->ptr_buf_img + offset) = f->color; /*apply the color to the pixel which data points to*/
            x++;
        }
        y++;
    }
    return (0);
}
