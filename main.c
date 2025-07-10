#include "fractol.h"

int main(int argc, char **argv)
{
    //int validate;
    typedef struct s_fract
    {
        double cor_real;
        double cor_im;
        char *ptr_buf_img;
        int flag_escapes;
        int color;
        int type;
        void *init_graphic;
        void *window;
        void *buffer_img;
        int bpp;
        int size_line;
    } t_fract;

    t_fract f;
    //Ask if when the user Defines a macro if it counts as argc or not. This case WIDTH and HEIGTH
    //Can Height and WIDTH be 0 or less? i guess so cuz we are talking about a plano cartesiano
    if (argc > 5 || argc == 3 || argc == 4)
        ft_check_error(1);
    else if (argc == 2 || argc == 5)
        ft_arg_check(argc, argv);
    ft_inti_graphic(&f);
    ft_creation(&f);
    ft_set_and_assing(&f);
    ft_main_loops(argv, &f);
    ft_display(&f);
    return (0);
}