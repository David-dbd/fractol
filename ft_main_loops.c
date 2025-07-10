#include "fractol.h"

static void ft_color(t_fract *f, int i)
{
    int color_arr[] = {0x220022, 0x442288, 0x88FFAA, 0xFFFFBB};
    if (f->flag_escapes == 1)
    {
        if (i >= 0 && i<= 9)
            f->color = color_arr[i % 4]; 
        else if (i >= 10 && i<= 19)
            f->color = color_arr[i % 4];
        else if (i >= 20 && i<= 40)
            f->color = color_arr[i % 4];
        else if (i > 40)
            f->color = color_arr[i % 4];
    }
    else if (f->flag_escapes == 0)
        f->color = 0x000000;
}

static int ft_z_equation(t_fract *f)
{
    /*Zn+1 = Zn^2 + c*/
    int i;
    double z;
    double k; /*k works as Zn^2 while z will act as Zn+1*/

    i = 0;
    z = ((i * i) + ((f->cor_real * f->cor_real) + (f->cor_im * f->cor_im))); //I use i * i just to exactly replicate the equation although is not necesary
    k = z * z;
    while (i < 50)
    {
        z = ((k) + ((f->cor_real * f->cor_real) + (f->cor_im * f->cor_im)));
        if (z > 4)
        {
            f->flag_escapes = 1;
            return (i);
        }
        i++;
        k = z * z;
    }
    f->flag_escapes = 0;
    return (0);
}
static int ft_find_complex_co(char **argv, t_fract *f, int y, int x)
{
    /*c = x + yi*/
    if (strcmp(argv[1], "julia") == 0)
    {
        if (f->type == 0)
        {
            f->cor_real = -2.0 + argv[2] * (2.0 - (-2.0)) / WIDTH;
            f->cor_im = 1.5 - argv[4] * (1.5 - (-1.5)) / HEIGTH;
            f->type = 1; //So that we stick with the same c always
        }
        return (0);
    }
    else if (strcmp(argv[1], "mandelbrot") == 0)
    {
        f->cor_real = -2.0 + x * (1.0 - (-2.0)) / WIDTH;
        f->cor_im = 1.2 - y * (1.2 - (-1.2)) / HEIGTH;
    }
    return (0);
}

int ft_main_loops(char ** argv, t_fract *f)
{
    int offset;
    int x;
    int y;
    int i;

    x = 0;
    y = 0;
    offset = 0;
    while (y < HEIGTH)
    {
        x = 0;
        while (x < WIDTH)
        {
            ft_find_complex_co(argv, f, y, x); //find c
            i = ft_z_equation(f); //aply c to the z equation
            ft_color(f, i); //apply the color
            offset = y * f->size_line + x * (f->bpp / 8);
            *(int *)(f->ptr_buf_img + offset) = f->color; //apply the color to the pixel which data points to
            x++;
        }
        y++;
    }
    return (0);
}
