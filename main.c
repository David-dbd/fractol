#include "fractol.h"

int main(int argc, char **argv)
{
    //int validate;
    t_fract f;
    char c;
    //Can Height and WIDTH be 0 or less? i guess so cuz we are talking about a plano cartesiano
    c = '\0';
    if (argc > 5 || argc == 3 || argc == 4)
        ft_check_error(1);
    else if (argc == 2 || argc == 5)
        c = ft_arg_check(argc, argv);
    ft_struct_init(&f);
    ft_init_graphic(&f);
    ft_creation(&f);
    ft_set_framework(&f, c);
    ft_set_and_assign(&f);
    ft_main_loops(argv, &f);
    ft_display(&f);
    mlx_loop(f.init_graphic);
    return (0);
}
