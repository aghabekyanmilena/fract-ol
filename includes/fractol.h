/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:14:44 by miaghabe          #+#    #+#             */
/*   Updated: 2025/03/31 22:48:06 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	double	x_offset;
	double	y_offset;
	double	zoom;
}	t_data;

void	draw_mandelbrot(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
int		mandelbrot(double cr, double ci);
int		handle_key(int keycode, t_data *data);
int		handle_close(t_data *data);

#endif
