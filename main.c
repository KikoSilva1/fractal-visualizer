/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:33:45 by framiran          #+#    #+#             */
/*   Updated: 2025/10/17 12:52:23 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_image(t_dta dta)
{
	t_imgdta		i;
	t_pxl_dta		t_pxl_dta;
	int				pixel;
	unsigned int	color;

	t_pxl_dta.y = 0;
	i.imgptr = mlx_get_data_addr(dta.ldta.img, &i.bpp, &i.linesize, &i.endi);
	while (t_pxl_dta.y < dta.wsizs.hgth)
	{
		t_pxl_dta.x = 0;
		while (t_pxl_dta.x < dta.wsizs.wdth)
		{
			pixel = t_pxl_dta.y * i.linesize + t_pxl_dta.x * 4;
			color = get_color(t_pxl_dta, dta);
			paint_pixel(i.imgptr, pixel, color);
			t_pxl_dta.x++;
		}
		t_pxl_dta.y++;
	}
}

void	set_initial_values(t_pl *pl, int *numb_of_ite)
{
	pl -> maxx = 1;
	pl -> minx = -2;
	pl -> maxy = 1.5;
	pl -> miny = -1.5;
	*numb_of_ite = 100;
}

void	innitminilibx(t_ldta *ldta, t_ws *wsizs)
{
	wsizs->hgth = 600;
	wsizs->wdth = 800;
	ldta->mlx = mlx_init();
	ldta->win = mlx_new_window(ldta->mlx, wsizs->wdth, wsizs->hgth, "");
	ldta->img = mlx_new_image(ldta->mlx, wsizs->wdth, wsizs->hgth);
}

int	main(int argc, char **argv)
{
	int			nmb_of_ite;
	t_ldta		ldta;
	t_pl		t_pl;
	t_ws		wsizs;
	t_dta		dta;

	if (argc < 3)
	{
		write(1, "Usage:./fractol Mandelbrot <number of iterations>.\n", 51);
		write(1, "or ./fractol Julia <1 to 4> <number of iter>.\n", 46);
		exit(EXIT_FAILURE);
	}
	innitminilibx(&ldta, &wsizs);
	set_initial_values(&t_pl, &nmb_of_ite);
	fill_innit_dta(&dta, t_pl, wsizs, ldta);
	fill_dta_from_argv(&dta, argv, argc);
	generate_image(dta);
	mlx_put_image_to_window(ldta.mlx, ldta.win, ldta.img, 0, 0);
	mlx_hook(dta.ldta.win, 2, 1L << 0, key_press, &dta);
	mlx_hook(dta.ldta.win, 17, 1L << 17, close_program, &dta);
	mlx_mouse_hook(ldta.win, mouse_hook, &dta);
	mlx_loop(ldta.mlx);
}
