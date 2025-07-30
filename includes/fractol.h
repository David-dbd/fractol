/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:11:33 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/07/29 23:13:33 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGTH 1000
# define WIDTH 1000
# define ESC_KEY 65307
# define ENTER_KEY 65293
# define SCROLL_UP 4
# define SCROLL_DOWN 5
/*LIBRARIES */
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <math.h>
# include "libft.h"
# include "libftprintf.h"
# include "mlx.h"
/*STRUCT*/
typedef struct s_fract
{
	char	c;
	char	*ptr_buf_img;
	double	cor_real;
	double	cor_im;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	julia_re;
	double	julia_im;
	double	zoom;
	int		bpp;
	int		size_l;
	int		mouse_real_cor;
	int		mouse_im_cor;
	int		counter;
	int		flag_escapes;
	int		color;
	int		type;
	void	*init_graphic;
	void	*window;
	void	*buffer_img;
}	t_fract;
/*FUNCTIONS */
int		ft_strtol(char *str, int *error);
int		ft_burningship(t_fract *f, int y, int x);
int		ft_julia(char **argv, t_fract *f, int y, int x);
int		ft_mandelbrot(t_fract *f, int y, int x);
int		main(int argc, char **argv);
int		ft_struct_init(t_fract *f);
int		ft_init_graphic(t_fract *f);
int		ft_creation(t_fract *f);
int		ft_set_framework(t_fract *f);
int		ft_set_and_assign(t_fract *f);
int		ft_main_loops(char **argv, t_fract *f);
int		ft_main_loops_mouse(t_fract *f);
int		ft_display(t_fract *f);
int		ft_strcmp(char *s1, char *s2);
int		ft_strisalpha(char *str);
int		ft_zoom(t_fract *f, int x, int y);
double	ft_atof(const char *str, int *error);
void	ft_check_error(int error, t_fract *f);
void	ft_destroy_and_close(t_fract *f);
void	ft_arg_check(int argc, char **argv, t_fract *f);
void	ft_color(t_fract *f, int i);
#endif
