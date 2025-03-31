/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:37:16 by miaghabe          #+#    #+#             */
/*   Updated: 2025/03/31 22:37:21 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	double	zr = 0;
	double	zi = 0;
	double	tmp;
	int		iter = 0;

	while (zr * zr + zi * zi <= 4 && iter < MAX_ITER)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot(t_data *data)
{
	int		x, y, iter, color;
	double	cr, ci;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			cr = (x - WIDTH / 2.0) * (4.0 / WIDTH) / data->zoom + data->x_offset;
			ci = (y - HEIGHT / 2.0) * (4.0 / HEIGHT) / data->zoom + data->y_offset;
			iter = mandelbrot(cr, ci);
			color = iter * 0x0F0F0F; // Grayscale color mapping
			put_pixel(data, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
