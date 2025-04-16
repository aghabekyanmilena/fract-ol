/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:13:39 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/16 19:04:23 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = ((y * img->line_len) + (x * img->bp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	mandelbrot_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

int	get_color(int i, int max_iter, int color_shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i >= max_iter)
		return (0x000000);
	t = (double)i / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	r = (r + color_shift) % 256;
	g = (g + color_shift) % 256;
	b = (b + color_shift) % 256;
	return ((r << 16) | (g << 8) | b);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	clean(fractal);
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			pixel_handling(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
