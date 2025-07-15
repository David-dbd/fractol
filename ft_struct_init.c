#include "fractol.h"

int ft_struct_init(t_fract *f)
{
    f->cor_real = 0;
    f->cor_im = 0;
    f->ptr_buf_img = NULL;
    f->flag_escapes = 0;
    f->color = 0;
    f->type = 0;
    f->init_graphic = NULL;
    f->window = NULL;
    f->buffer_img = NULL;
    f->bpp = 32;
    f->size_line = 0;
    f->zoom = 1;
    f->max_re = 0;
    f->min_re = 0;
    f->max_im = 0;
    f->min_im = 0;
    f->counter = 0;
    return (0);
}