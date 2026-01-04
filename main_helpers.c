/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:54:34 by framiran          #+#    #+#             */
/*   Updated: 2025/10/17 13:56:32 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_innit_dta(t_dta *dta, t_pl pls, t_ws ws, t_ldta t_ldta)
{
	dta->pl = pls;
	dta->wsizs = ws;
	dta->ldta = t_ldta;
}

void	fill_dta_from_argv(t_dta *dta, char **argv, int argc)
{
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		handle_mandelbrot(dta, argv, argc);
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
		handle_julia(dta, argv, argc);
	else
	{
		write(1, "Unknown fractal: Use 'Mandelbrot' or 'Julia'.\n", 46);
		close_program(dta);
	}
}

int	close_program(t_dta *dta)
{
	if (dta->ldta.win)
		mlx_destroy_window(dta->ldta.mlx, dta->ldta.win);
	if (dta->ldta.img)
		mlx_destroy_image(dta->ldta.mlx, dta->ldta.img);
	if (dta->ldta.mlx)
	{
		mlx_destroy_display(dta->ldta.mlx);
		free(dta->ldta.mlx);
	}
	exit(0);
	return (0);
}

int	key_press(int keycode, t_dta *dta)
{
	if (keycode == ESC_KEY)
		close_program(dta);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_dta	*dta;

	dta = (t_dta *)param;
	if (button == 4)
		change_t_pl(x, y, dta, 1);
	else if (button == 5)
		change_t_pl(x, y, dta, 0);
	generate_image(*dta);
	mlx_put_image_to_window(dta->ldta.mlx, dta->ldta.win, dta->ldta.img, 0, 0);
	return (0);
}
