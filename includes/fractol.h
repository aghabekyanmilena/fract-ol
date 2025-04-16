/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:14:44 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/16 14:42:16 by miaghabe         ###   ########.fr       */
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
# include <X11/X.h>
# include <X11/keysym.h>

# define SIZE 500

// colors
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE 	0x0000FF

# define ZOOM_IN1 61
# define ZOOM_OUT1 45
# define ZOOM_IN2 65451
# define ZOOM_OUT2 65453

# define SCROLL_UP 4
# define SCROLL_DOWN 5

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
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		map(double num, double n_min, double n_max, double max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handle(int keysym, t_fractal *fractal);
int			close_handle(t_fractal *fractal);
int			mouse_handle(int button, int x, int y, t_fractal *fractal);
double		atodbl(char *s);
int			julia_track(int x, int y, t_fractal *fractal);
void		clean(t_fractal *fractal);

#endif