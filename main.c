#include "fractol.h"

int main(int argc, char **argv)
{
    t_fract f;
    //Can Height and WIDTH be 0 or less? i guess so cuz we are talking about a plano cartesiano
    ft_arg_check(argc, argv, &f);
    ft_printf("arg_check\n");
    fflush(stdout);
    ft_struct_init(&f);
    ft_printf("strcut init\n");
    fflush(stdout);
    ft_init_graphic(&f);
    ft_printf("init_graphic\n");
    fflush(stdout);
    ft_creation(&f);
    ft_printf("ft_creation\n");
    fflush(stdout);
    ft_set_framework(&f);
    ft_printf("set_framework\n");
    fflush(stdout);
    ft_set_and_assign(&f, argv);
    ft_printf("set and assign\n");
    fflush(stdout);
    ft_main_loops(argv, &f);
    ft_printf("main_loops\n");
    fflush(stdout);
    ft_display(&f);
    fflush(stdout);
    mlx_loop(f.init_graphic);
    return (0);
}
