/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:48:05 by miaghabe          #+#    #+#             */
/*   Updated: 2025/05/02 23:39:24 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_zeros(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '0' && !ft_strchr(argv, '.'))
		exit(EXIT_FAILURE);
	if (argv[i] == '0' && argv[i + 1] == '0' && ft_strchr(argv, '.'))
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((2 == argc && (!ft_strcmp(argv[1], "mandelbrot")
				|| !ft_strcmp(argv[1], "burningship")))
		|| (4 == argc && !ft_strcmp(argv[1], "julia")))
	{
		fractal.name = argv[1];
		if (!ft_strcmp(fractal.name, "julia"))
		{
			if (check_julia_input(argv[2]))
				fractal.julia_x = atodbl(argv[2]);
			if (check_julia_input(argv[3]))
				fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		write(1, "Enter mandelbrot, (julia x y) or burningship\n", 46);
	return (0);
}
