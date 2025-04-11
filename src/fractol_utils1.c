/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:13:39 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/11 16:20:39 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = ((y * img->line_len) + (x * img->bp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	pixel_handling(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, 2, WIDTH);
	c.y = map(y, 2, -2, HEIGHT);
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if (((z.x * z.x) + (z.y * z.y)) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations);
			pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	pixel_put(x, y, &fractal->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
			pixel_handling(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_connection, \
		fractal->img.img_ptr, 0, 0);
}
