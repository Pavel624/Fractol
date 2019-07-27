/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:19:06 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:19:08 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>

# define WIDTH 900
# define HEIGHT 900

# define THREAD_NUMBER 180
# define THREAD_WIDTH 5

# define KEY_ESC 53

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_NUMPAD_1 83
# define KEY_NUMPAD_2 84
# define KEY_NUMPAD_3 85
# define KEY_NUMPAD_4 86

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			line_s;
	int			endian;
}				t_image;

typedef struct	s_mouse
{
	double		x;
	double		y;
	double		x0;
	double		y0;
}				t_mouse;

typedef struct	s_fractal
{
	int			name;
	void		*mlx;
	void		*window;
	t_image		image;
	t_mouse		mouse;
	int			x;
	int 		y;
	int			ymax;
	double 		x1;
	double 		y1;
	double		zoom;
	double		moveX;
	double		moveY;
	int 		max_it;
	int 		tmp;
	int			cur_it;
	int			color;
	double 		cRe;
	double 		cIm;
}				t_fractal;

void		img_pixel_put(t_image *img, int x, int y, int color);
void		get_color(t_fractal *fractal);
int			mouse_moved(int x, int y, t_fractal *fractal);
int			key_trans(int key, t_fractal *fractal);
void		zoom_in(int x, int y, t_fractal *fractal);
void		zoom_out(int x, int y, t_fractal *fractal);
void		draw(t_fractal *fractal);
void		init_julia(t_fractal *fractal);
void		calc_fractal(t_fractal *fractal);
int			mouse(int mousecode, int x, int y, t_fractal *data);
void 		*julia(void *data);
void		init_mandelbrot(t_fractal *fractal);
void		mandelbrot(t_fractal *fractal);
void		julia_pthread(t_fractal *fractal);

#endif