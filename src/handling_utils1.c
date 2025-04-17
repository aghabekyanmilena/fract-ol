/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:30:27 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/17 16:06:17 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handle(fractal);
	else if (keysym == XK_Left || keysym == XK_Right || keysym == XK_Up
		|| keysym == XK_Down)
		arrows(keysym, fractal);
	else if (keysym == ZOOM_IN1 || keysym == ZOOM_IN2 || keysym == ZOOM_OUT1
		|| keysym == ZOOM_OUT2)
		zoom(keysym, fractal);
	else if (keysym == XK_m)
		fractal->color_shift += 5;
	else if (keysym == XK_l)
		fractal->flag = !fractal->flag;
	fractal_render(fractal);
	return (0);
}

void	arrows(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Left)
	{
		fractal->min_re -= (0.1 * (fractal->max_re - fractal->min_re));
		fractal->max_re -= (0.1 * (fractal->max_re - fractal->min_re));
	}
	else if (keysym == XK_Right)
	{
		fractal->min_re += (0.1 * (fractal->max_re - fractal->min_re));
		fractal->max_re += (0.1 * (fractal->max_re - fractal->min_re));
	}
	else if (keysym == XK_Up)
	{
		fractal->min_im -= (0.1 * (fractal->max_im - fractal->min_im));
		fractal->max_im -= (0.1 * (fractal->max_im - fractal->min_im));
	}
	else if (keysym == XK_Down)
	{
		fractal->min_im += (0.1 * (fractal->max_im - fractal->min_im));
		fractal->max_im += (0.1 * (fractal->max_im - fractal->min_im));
	}
}

void	zoom(int keysym, t_fractal *fractal)
{
	double	zoom_factor;

	zoom_factor = 1.1;
	if (keysym == ZOOM_IN1 || keysym == ZOOM_IN2)
	{
		fractal->min_re += (fractal->max_re - fractal->min_re)
			* (1 - 1 / zoom_factor);
		fractal->max_re -= (fractal->max_re - fractal->min_re)
			* (1 - 1 / zoom_factor);
		fractal->min_im += (fractal->max_im - fractal->min_im)
			* (1 - 1 / zoom_factor);
		fractal->max_im -= (fractal->max_im - fractal->min_im)
			* (1 - 1 / zoom_factor);
	}
	else if (keysym == ZOOM_OUT1 || keysym == ZOOM_OUT2)
	{
		fractal->min_re -= (fractal->max_re - fractal->min_re)
			* (zoom_factor - 1);
		fractal->max_re += (fractal->max_re - fractal->min_re)
			* (zoom_factor - 1);
		fractal->min_im -= (fractal->max_im - fractal->min_im)
			* (zoom_factor - 1);
		fractal->max_im += (fractal->max_im - fractal->min_im)
			* (zoom_factor - 1);
	}
}
