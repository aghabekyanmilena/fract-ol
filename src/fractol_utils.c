/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:35:40 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/17 16:09:52 by miaghabe         ###   ########.fr       */
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
	fractal->min_re = -2.0;
	fractal->max_re = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;
	fractal->escape_value = 4;
	fractal->iterations = 200;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->flag = 0;
}

void	clean(t_fractal *fractal)
{
	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, SIZE, SIZE);
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bp,
			&fractal->img.line_len,
			&fractal->img.endian);
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handle, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handle, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handle, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask,
		julia_track, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, SIZE,
			SIZE, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, SIZE,
			SIZE);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
