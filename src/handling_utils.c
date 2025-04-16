/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:32:46 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/16 14:55:18 by miaghabe         ###   ########.fr       */
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

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handle(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations += 10;
	else if (keysym == XK_minus)
		fractal->iterations -= 10;
	else if (keysym == ZOOM_IN1 || keysym == ZOOM_IN2)
		fractal->zoom /= 1.1;
	else if (keysym == ZOOM_OUT1 || keysym == ZOOM_OUT2)
		fractal->zoom *= 1.1;
	fractal_render(fractal);
	return (0);
}

static void	mouse_zoom(t_fractal *fractal, int keycode, int x, int y)
{
	double	center_x;
	double	center_y;
	double	zoom_factor;
	double	prev_zoom;

	prev_zoom = fractal->zoom;
	center_x = SIZE / 2.0;
	center_y = SIZE / 2.0;
	if (keycode == SCROLL_UP)
		zoom_factor = 1.1;
	else
		zoom_factor = 1 / 1.1;
	fractal->zoom *= zoom_factor;
	fractal->shift_x -= ((x - center_x) / SIZE
			* (fractal->zoom - prev_zoom)) * 5;
	fractal->shift_y -= ((y - center_y) / SIZE
			* (fractal->zoom - prev_zoom)) * 5;
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
