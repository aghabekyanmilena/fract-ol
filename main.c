#include <../minilibx-linux/mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractol
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    double  min_re;
    double  max_re;
    double  min_im;
    double  max_im;
    int     max_iter;
}   t_fractol;

int mandelbrot(double cr, double ci, int max_iter)
{
    double zr = 0, zi = 0;
    int i = 0;
    while (zr * zr + zi * zi <= 4 && i < max_iter)
    {
        double tmp = zr * zr - zi * zi + cr;
        zi = 2 * zr * zi + ci;
        zr = tmp;
        i++;
    }
    return (i);
}

void draw_fractal(t_fractol *fract)
{
    int x, y;
    double cr, ci;
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            cr = fract->min_re + x * (fract->max_re - fract->min_re) / WIDTH;
            ci = fract->max_im - y * (fract->max_im - fract->min_im) / HEIGHT;
            int iter = mandelbrot(cr, ci, fract->max_iter);
            int color = (iter * 255 / fract->max_iter) << 16;
            ((int *)(fract->addr))[y * WIDTH + x] = color;
        }
    }
    mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}

int key_hook(int keycode, t_fractol *fract)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(fract->mlx, fract->win);
        exit(0);
    }
    return (0);
}

int main()
{
    t_fractol fract;
    fract.mlx = mlx_init();
    fract.win = mlx_new_window(fract.mlx, WIDTH, HEIGHT, "Fract-ol");
    fract.img = mlx_new_image(fract.mlx, WIDTH, HEIGHT);
    fract.addr = mlx_get_data_addr(fract.img, &fract.bpp, &fract.line_length, &fract.endian);
    fract.min_re = -2.0;
    fract.max_re = 1.0;
    fract.min_im = -1.5;
    fract.max_im = 1.5;
    fract.max_iter = 100;
    draw_fractal(&fract);
    mlx_key_hook(fract.win, key_hook, &fract);
    mlx_loop(fract.mlx);
    return (0);
}
