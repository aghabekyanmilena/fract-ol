/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:35:40 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/11 16:32:43 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	malloc_error(void)
{
	perror("Malloc failed");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 42;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handle, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handle,\
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,\
		close_handle, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, \
		HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, \
		HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, \
		&fractal->img.bp, &fractal->img.line_len, &fractal->img.endian);
	events_init();
	data_init(fractal);
}
