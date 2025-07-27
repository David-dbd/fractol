#include "fractol.h"

static int ft_julia_equation(t_fract *f, double z_real, double z_im)
{
    int i;
    int max;
    double temp_real;
    
    i = 0;
    if (f->counter <= 30)
        max = 50 * f->counter;
    else
        max = 100 + log(f->zoom) * 10;
    while (i < max)
    {
        temp_real = z_real * z_real - z_im * z_im;
        z_im = 2.0 * z_real * z_im;
        z_real = temp_real;
        z_real += f->julia_re;
        z_im += f->julia_im;
        if (z_real * z_real + z_im * z_im > 4.0)
        {
            f->flag_escapes = 1;
            return (i);
        }
        i++;
    }
    f->flag_escapes = 0;
    return (0);
}

int ft_julia(char **argv, t_fract *f, int y, int x)
{
    int i;
    double z_real;
    double  z_im;

    i = 0;
    /*c = constant*/
    if (f->type == 0)
    {
        f->julia_re = ft_atof(argv[2]);
        f->julia_im = ft_atof(argv[3]);
        f->type = 1; /*So that we stick with the same c always*/
    }
    /*z = x + yi*/
    f->cor_real = -2.0 + x * (2.0 - (-2.0)) / WIDTH;
    f->cor_im = 1.5 - y * (1.5 - (-1.5)) / HEIGTH;
    z_real = f->cor_real;
    z_im = f->cor_im;
    i = ft_julia_equation(f, z_real, z_im);
    return (i);
}