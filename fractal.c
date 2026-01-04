/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:54:25 by framiran          #+#    #+#             */
/*   Updated: 2025/10/14 16:14:31 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_iter_julia(t_pxl_dta pixel, int julia_var, int iter_nmb)
{
	int			iter;
	double		temp_r;
	t_pxl_dta	c;
	t_pxl_dta	res;

	iter = 0;
	get_c(julia_var, &c.r, &c.i);
	res.r = pixel.r;
	res.i = pixel.i;
	while (res.r * res.r + res.i * res.i <= 4.0 && iter < iter_nmb)
	{
		temp_r = res.r * res.r - res.i * res.i + c.r;
		res.i = 2 * res.r * res.i + c.i;
		res.r = temp_r;
		iter++;
	}
	return (iter);
}

int	get_iter_mandel(t_pxl_dta t_pxl_dta, int iter_nmb)
{
	int		iter;
	double	zx;
	double	zy;
	double	zx_temp;

	iter = 0;
	zx = 0;
	zy = 0;
	while (zx * zx + zy * zy <= 4.0 && iter < iter_nmb)
	{
		zx_temp = zx * zx - zy * zy + t_pxl_dta.r;
		zy = 2 * zx * zy + t_pxl_dta.i;
		zx = zx_temp;
		iter++;
	}
	return (iter);
}

void	map_pixel(t_pxl_dta *p, t_dta d)
{
	p->r = ((double)p->x / d.wsizs.wdth) * (d.pl.maxx - d.pl.minx) + d.pl.minx;
	p->i = ((double)p->y / d.wsizs.hgth) * (d.pl.maxy - d.pl.miny) + d.pl.miny;
}

void	get_c(int variation, double *r, double *i)
{
	if (variation == 1)
	{
		*r = -0.7;
		*i = 0.27015;
	}
	else if (variation == 2)
	{
		*r = 0.285;
		*i = 0.01;
	}
	else if (variation == 3)
	{
		*r = -0.8;
		*i = 0.156;
	}
	else if (variation == 4)
	{
		*r = 0.355;
		*i = 0.355;
	}
	else
	{
		*r = -0.7;
		*i = 0.27015;
	}
}

unsigned int	get_color(t_pxl_dta t_pxl_dta, t_dta dta)
{
	int				iter;
	unsigned int	color;

	iter = 0;
	map_pixel(&t_pxl_dta, dta);
	if (dta.fractal == 1)
		iter = get_iter_mandel(t_pxl_dta, dta.nmb_of_ite);
	else if (dta.fractal == 2)
		iter = get_iter_julia(t_pxl_dta, dta.julia_var, dta.nmb_of_ite);
	color = calc_color(iter);
	return (color);
}
