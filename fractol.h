/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:42:55 by framiran          #+#    #+#             */
/*   Updated: 2025/10/17 12:55:44 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# define ESC_KEY 65307

typedef struct s_imgdta
{
	char	*imgptr;
	int		bpp;
	int		linesize;
	int		endi;
}				t_imgdta;

typedef struct s_pl
{
	float	minx;
	float	maxx;
	float	miny;
	float	maxy;
}				t_pl;

typedef struct s_pxl_dta
{
	int		x;
	int		y;
	double	r;
	double	i;
}				t_pxl_dta;

typedef struct s_ws
{
	int	wdth;
	int	hgth;
}					t_ws;

typedef struct s_ldta
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_ldta;

typedef struct s_dta
{
	t_pl			pl;
	int				nmb_of_ite;
	t_ws			wsizs;
	t_ldta			ldta;
	int				fractal;
	int				julia_var;
}	t_dta;

void			handle_mandelbrot(t_dta *dta, char **argv, int argc);
void			handle_julia(t_dta *dta, char **argv, int argc);
int				is_valid_variation(char *str);
int				get_iter_julia(t_pxl_dta pixel, int julia_var, int iter_nmb);
int				get_iter_mandel(t_pxl_dta t_pxl_dta, int iter_nmb);
void			map_pixel(t_pxl_dta *t_pxl_dta, t_dta dta);
void			get_c(int variation, double *r, double *i);
unsigned int	get_color(t_pxl_dta t_pxl_dta, t_dta dta);
unsigned int	calc_color(int iter);
void			paint_pixel(char *img_dta, int pixel, unsigned int color);
void			change_t_pl(int x, int y, t_dta *dta, int zoom);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_is_number(char *str);
void			fill_innit_dta(t_dta *dta, t_pl pl, t_ws ws, t_ldta ldta);
void			fill_dta_from_argv(t_dta *dta, char **argv, int argc);
int				close_program(t_dta *dta);
int				key_press(int keycode, t_dta *dta);
int				mouse_hook(int button, int x, int y, void *param);
void			generate_image(t_dta dta);
void			set_initial_values(t_pl *pl, int *numb_of_ite);
void			innitminilibx(t_ldta *ldta, t_ws *wsizs);

#endif
