/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:36:42 by miaghabe          #+#    #+#             */
/*   Updated: 2025/03/31 22:36:47 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
	data.zoom = 1.0;
	data.x_offset = 0.0;
	data.y_offset = 0.0;

	draw_mandelbrot(&data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 0, handle_close, &data); // Close button hook
	mlx_loop(data.mlx);
}
