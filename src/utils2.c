/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:37:47 by miaghabe          #+#    #+#             */
/*   Updated: 2025/03/31 22:39:28 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307) // exit
		exit(0);
	else if (keycode == 65361) // (←)
		data->x_offset -= 0.1 / data->zoom;
	else if (keycode == 65363) // (→)
		data->x_offset += 0.1 / data->zoom;
	else if (keycode == 65362) // (↑)
		data->y_offset -= 0.1 / data->zoom;
	else if (keycode == 65364) // (↓)
		data->y_offset += 0.1 / data->zoom;
	else if (keycode == 61) // '+' Zoom in
		data->zoom *= 1.2;
	else if (keycode == 45) // '-' Zoom out
		data->zoom /= 1.2;
	draw_mandelbrot(data);
	return (0);
}
