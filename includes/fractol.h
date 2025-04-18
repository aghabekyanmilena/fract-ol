/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:14:44 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/18 14:16:09 by miaghabe         ###   ########.fr       */
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
	int		bp;
	int		line_len;
}	t_image;

typedef struct s_fractal
{
	t_image	img;
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	int		iterations;
	int		color_shift;
	int		flag;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	escape_value;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handle(int keysym, t_fractal *fractal);
int			close_handle(t_fractal *fractal);
int			mouse_handle(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
void		clean(t_fractal *fractal);
void		arrows(int keysym, t_fractal *fractal);
void		zoom(int keysym, t_fractal *fractal);
void		mandelbrot_or_julia(t_complex *z, t_complex *c, t_fractal *fractal);
int			get_color(int i, int max_iter, int color_shift);
void		pixel_handling(int x, int y, t_fractal *fractal);
void		pixel_put(int x, int y, t_image *img, int color);
int			ft_strcmp(char *s1, char *s2);
double		atodbl(char *s);
int		check_julia_input(char *argv);


#endif