/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ie_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:54:29 by framiran          #+#    #+#             */
/*   Updated: 2025/10/14 15:55:19 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	calc_color(int iter)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(128 + 127 * sin(iter * 0.3));
	g = (unsigned char)(128 + 127 * sin(iter * 0.15 + 2));
	b = (unsigned char)(128 + 127 * sin(iter * 0.1 + 4));
	return ((r << 16) | (g << 8) | b);
}

void	paint_pixel(char *img_dta, int pixel, unsigned int color)
{
	img_dta[pixel + 0] = color & 0xFF;
	img_dta[pixel + 1] = (color >> 8) & 0xFF;
	img_dta[pixel + 2] = (color >> 16) & 0xFF;
	img_dta[pixel + 3] = 0;
}

void	change_t_pl(int x, int y, t_dta *dta, int zoom)
{
	float		reason;
	float		abs_distance_x;
	float		abs_distance_y;
	t_pxl_dta	t_pxl_dta;

	t_pxl_dta.x = x;
	t_pxl_dta.y = y;
	map_pixel(&t_pxl_dta, *dta);
	abs_distance_x = (dta->pl.maxx) - (dta->pl.minx);
	abs_distance_y = (dta->pl.maxy) - (dta->pl.miny);
	reason = 1.2;
	if (zoom == 1)
	{
		dta->pl.maxx = t_pxl_dta.r + ((abs_distance_x / 2) / reason);
		dta->pl.minx = t_pxl_dta.r - ((abs_distance_x / 2) / reason);
		dta->pl.maxy = t_pxl_dta.i + ((abs_distance_y / 2) / reason);
		dta->pl.miny = t_pxl_dta.i - ((abs_distance_y / 2) / reason);
	}
	else
	{
		dta->pl.maxx = t_pxl_dta.r + ((abs_distance_x / 2) * reason);
		dta->pl.minx = t_pxl_dta.r - ((abs_distance_x / 2) * reason);
		dta->pl.maxy = t_pxl_dta.i + ((abs_distance_y / 2) * reason);
		dta->pl.miny = t_pxl_dta.i - ((abs_distance_y / 2) * reason);
	}
}
