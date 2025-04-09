/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:14:44 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/09 20:22:26 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct s_image
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		endian;
	int		bp; // byte per pixel
	int		line_len;
}	t_image;


typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_image	img;
}	t_fractal;

typedef struct s_complex
{
	double x;
	double y;
}	t_complex;

void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
void	pixel_handling(int x, int y, t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
double	map(double num, double n_min, double n_max, double max);

#endif
