/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:54:22 by framiran          #+#    #+#             */
/*   Updated: 2025/10/17 13:54:55 by framiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_mandelbrot(t_dta *dta, char **argv, int argc)
{
	if (argc != 3)
	{
		write(1, "Usage: ./fractol Mandelbrot <number of iter>\n", 45);
		close_program(dta);
	}
	if (!ft_is_number(argv[2]))
	{
		write(1, "Error: <number of ite> must be int >=100 and <=500.", 51);
		close_program(dta);
	}
	else if (ft_atoi(argv[2]) > 500 || ft_atoi(argv[2]) < 100)
	{
		write(1, "Error: <number of ite> must be int >=100 and <=500.", 51);
		close_program(dta);
	}
	dta->nmb_of_ite = ft_atoi(argv[2]);
	dta->fractal = 1;
}

void	handle_julia(t_dta *dta, char **argv, int argc)
{
	if (argc != 4)
	{
		write(1, "Usage: ./fractol Julia <variation> <number of iter>\n", 52);
		close_program(dta);
	}
	if (!ft_is_number(argv[3]) || !is_valid_variation(argv[2]))
	{
		write(1, "Usage: 'Julia' <int between 1 and 4> <int>\n", 43);
		close_program(dta);
	}
	else if (ft_atoi(argv[3]) > 500 || ft_atoi(argv[3]) < 100)
	{
		write(1, "Error: <number of ite> must be int >=100 and <=500.", 51);
		close_program(dta);
	}
	dta->nmb_of_ite = ft_atoi(argv[3]);
	dta -> julia_var = ft_atoi(argv[2]);
	dta->fractal = 2;
}

int	is_valid_variation(char *str)
{
	if (ft_strlen(str) != 1)
		return (0);
	if (str[0] >= '1' && str[0] <= '4')
		return (1);
	return (0);
}
