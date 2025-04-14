/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:13:39 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/14 15:56:44 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = ((y * img->line_len) + (x * img->bp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	mandelbrot_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
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

static int	get_color(int i, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static void	pixel_handling(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, 2, SIZE) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, -2, SIZE) * fractal->zoom) + fractal->shift_y;
	mandelbrot_or_julia(&z, &c, fractal);
	while (i++ < fractal->iterations)
	{
		if (!ft_strncmp(fractal->name, "burningship", 11))
		{
			z.x = fabs(z.x);
			z.y = fabs(z.y);
		}
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x + z.y * z.y) > fractal->escape_value)
		{
			color = get_color(i, fractal->iterations);
			pixel_put(x, y, &fractal->img, color);
			return ;
		}
	}
	pixel_put(x, y, &fractal->img, 0x000000);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			pixel_handling(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, \
		fractal->img.img_ptr, 0, 0);
}
