#ifndef FRACTOL_
# define FRACTOL_

# ifndef HEIGTH
    #define HEIGTH 1300
# endif
# ifndef WIDTH
    #define WIDTH 1000
# endif
# ifndef ESC_KEY
    #define ESC_KEY 65307
# endif
# ifndef SCROLL_UP
    #define SCROLL_UP 4
# endif
# ifndef SCROLL_DOWN
    #define SCROLL_DOWN 5
# endif
# include <stdlib.h>
# include <stdio.h>
#include <math.h>
# include "libft.h"
# include "libftprintf.h"
//#include "mlx_int.h"
#include "mlx.h"

typedef struct s_fract
{
    char c;
    double cor_real;
    double cor_im;
    double min_re;
    double max_re;
    double min_im;
    double max_im;
    double julia_re;
    double julia_im;
    char *ptr_buf_img;
    int zoom;
    int bpp;
    int size_line;
    int mouse_real_cor;
    int mouse_im_cor;
    int counter;
    int flag_escapes;
    int color;
    int type;
    void *init_graphic;
    void *window;
    void *buffer_img;
} t_fract;

void ft_arg_check(int argc, char **argv, t_fract *f);
double ft_atof(const char *str);
int ft_julia(char **argv, t_fract *f, int y, int x);
int ft_mandelbrot(t_fract *f, int y, int x);
int		main(int argc, char **argv);
int		ft_struct_init(t_fract *f);
int		ft_init_graphic(t_fract *f);
int		ft_creation(t_fract *f);
int		ft_set_framework(t_fract *f);
int		ft_set_and_assign(t_fract *f);
int		ft_main_loops(char **argv, t_fract *f);
int		ft_display(t_fract *f);
int		ft_strcmp(char *s1, char *s2);
int		ft_strisalpha(char *str);
void		ft_check_error(int error, t_fract *f);
void        ft_destroy_and_close(t_fract *f);
#endif
