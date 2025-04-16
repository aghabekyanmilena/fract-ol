/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:32:46 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/16 19:06:08 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

static void	mouse_zoom(t_fractal *fractal, int button, int x, int y)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;
	double	new_height;
	double	new_width;

	if (button == SCROLL_UP)
		zoom_factor = 0.9;
	else if (button == SCROLL_DOWN)
		zoom_factor = 1.1;
	else
		return ;
	mouse_re = fractal->min_re + ((double)x / SIZE) * (fractal->max_re
			- fractal->min_re);
	mouse_im = fractal->min_im + ((double)y / SIZE) * (fractal->max_im
			- fractal->min_im);
	new_width = (fractal->max_re - fractal->min_re) * zoom_factor;
	new_height = (fractal->max_im - fractal->min_im) * zoom_factor;
	fractal->min_re = mouse_re - ((mouse_re - fractal->min_re) * zoom_factor);
	fractal->max_re = fractal->min_re + new_width;
	fractal->min_im = mouse_im - ((mouse_im - fractal->min_im) * zoom_factor);
	fractal->max_im = fractal->min_im + new_height;
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button4 || button == Button5)
		mouse_zoom(fractal, button, x, y);
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, SIZE) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, SIZE) * fractal->zoom)
			+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
