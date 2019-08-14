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

# define THREAD_NUMBER 30
# define THREAD_WIDTH (HEIGHT / THREAD_NUMBER)

# define KEY_ESC 53

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_NUMPAD_1 83
# define KEY_NUMPAD_2 84
# define KEY_NUMPAD_3 85
# define KEY_NUMPAD_4 86
# define KEY_NUMPAD_5 87

# define KEY_L 37

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
	int			y_max;
	double 		x1;
	double 		y1;
	double		zoom;
	int			cur_it;
	int 		max_it;
	double 		tmp;
	int			color;
	double 		cRe;
	double 		cIm;
	double		zRe;
	double 		zIm;
	int 		lock;
}				t_fractal;

/*
** additional.c
*/

void		print_menu();
void		img_pixel_put(t_image *img, int x, int y, int color);
void		get_color(t_fractal *fractal);
int			key_trans(int key, t_fractal *fractal);
int			key_down(int key);

/*
** mouse.c
*/

void		zoom_in(int x, int y, t_fractal *fractal);
void		zoom_out(int x, int y, t_fractal *fractal);
int			mouse_moved(int x, int y, t_fractal *fractal);
int			mouse(int mousecode, int x, int y, t_fractal *data);

void		init_julia(t_fractal *fractal);
void		init_mandelbrot(t_fractal *fractal);
void 		init_burning_ship(t_fractal *fractal);
void 		init_tricorn(t_fractal *fractal);
void 		init_douady_rabbit(t_fractal *fractal);
void 		init_celtic_mandelbrot(t_fractal *fractal);
void		init_heart_mandelbrot(t_fractal *fractal);

void 		*julia(void *data);
void		*mandelbrot(void *data);
void		*burning_ship(void *data);
void		*tricorn(void *data);
void		*douady_rabbit(void *data);
void		*celtic_mandelbrot(void *data);
void		*heart_mandelbrot(void *data);
/*
** fractal_additional.c
*/

void		fractal_pthread(t_fractal *data, void *(f)(void *));
void		calc_fractal(t_fractal *fractal);
int 		select_fractal(t_fractal *fractal, char* param);


#endif