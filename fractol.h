#ifndef FRACTOL_
# define FRACTOL_

# ifndef HEIGTH
    #define HEIGTH 600;
# endif
# ifndef WIDTH
    #define WIDTH 400;
# endif
# include <stdlib.h>
# include <stdio.h>
# include "./minilibx/mlx.h"
# include "libft.h"
# include "libftprintf.h"
typedef struct s_fract
{
    double cor_real;
    double cor_im;
    char *ptr_buf_img;
    int zoom;
    int bpp;
    int size_line;
    int min_re;
    int max_re;
    int min_im;
    int max_im;
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

char ft_arg_check(int argc, char **argv);
int main(int argc, char **argv);
int ft_check_error(int error);
int ft_struct_init(t_fract *f);
int ft_init_graphic(t_fract *f);
int ft_creation(t_fract *f);
int ft_set_framework(t_fract *f, char c);
int ft_set_and_assign(t_fract *f);
int ft_main_loops(char **argv, t_fract *f);
int ft_display(t_fract *f);

#endif
