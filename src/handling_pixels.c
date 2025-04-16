/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_pixels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:58:08 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/16 19:04:13 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_complex get_initial_z(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	
	z.x = fractal->min_re + ((double)x / SIZE) * (fractal->max_re
		- fractal->min_re);
	z.y = fractal->min_im + ((double)y / SIZE) * (fractal->max_im
		- fractal->min_im);
	return (z);
}

static int compute_pixel_color(t_complex z, t_complex c, t_fractal *fractal)
{
    int i = 0;
    while (i++ < fractal->iterations)
    {
        if (!ft_strncmp(fractal->name, "burningship", 11))
        {
            z.x = fabs(z.x);
            z.y = fabs(z.y);
        }
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x + z.y * z.y) > fractal->escape_value)
            return get_color(i, fractal->iterations, fractal->color_shift);
    }
    return 0x000000; // Black color for points inside the set
}

void pixel_handling(int x, int y, t_fractal *fractal)
{
    t_complex z = get_initial_z(x, y, fractal);
    t_complex c;
    mandelbrot_or_julia(&z, &c, fractal);
    int color = compute_pixel_color(z, c, fractal);
    pixel_put(x, y, &fractal->img, color);
}
