/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:14:44 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/11 14:12:51 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

#define WIDTH 800
#define HEIGHT 800

// colors
#define BLACK	0x000000
#define WHITE	0xFFFFFF
#define RED		0xFF0000
#define GREEN	0x00FF00
#define BLUE 	0x0000FF

// Psychedelic colors
#define MAGENTA_BURST	0xFF00FF
#define LIME_SHOCK		0xCCFF00
#define NEON_ORANGE		0xFF6600
#define PSY_PURPLE		0x660066
#define AQUA_DREAM		0x33CCCC
#define HOT_PINK		0xFF66B2
#define ELECTRIC_BLUE	0x0066FF
#define LAVA_RED		0xFF3300


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
	double	escape_value;
	int		iterations;
}	t_fractal;

typedef struct s_complex
{
	double x;
	double y;
}	t_complex;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		map(double num, double n_min, double n_max, double max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
