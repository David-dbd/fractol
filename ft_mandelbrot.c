#include "fractol.h"

static int ft_mandelbrot(t_fract *f) /*Zn+1 = Zn^2 + c*/
{
    int i;
    int max;
    double z;
    double k; /*k works as Zn^2 while z will act as Zn+1*/

    i = 0;
    if (f->counter <= 30)
        max = 100 * f->counter;
    else
        max = 100 + log(f->zoom) * 30;
    z = 0;/*This is totally unnecesary. However, lets keep it like the equation says*/
    z = ((i * i) + ((f->cor_real * f->cor_real) + (f->cor_im * f->cor_im))); /*I use i * i just to exactly replicate the equation although is not necesary*/
    while (i < max)
    {
        k = z * z;
        z = ((k) + ((f->cor_real * f->cor_real) + (f->cor_im * f->cor_im)));
        if (z > 4)
        {
            f->flag_escapes = 1;
            return (i);
        }
        i++;
    }
    f->flag_escapes = 0;
    return (0);
}

int ft_mandelbrot(char **argv, t_fract *f, int y, int x)
{
    int i;

    i = 0;
    /*c = x + yi*/
    f->cor_real = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
    f->cor_im = f->max_im - y * (f->max_im - f->min_im) / HEIGTH;
    i = ft_mandelbrot_equation(f);
    return (i);
}