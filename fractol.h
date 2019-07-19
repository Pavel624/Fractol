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

# define WIDTH 1600
# define HEIGHT 900

# define KEY_ESC 53

typedef struct	s_fractal
{
	char *name;
}				t_fractal;

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
	int			pressed;
}				t_mouse;

typedef struct s_render
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_mouse		mouse;
	t_fractal *fractal;

}				t_render;

#endif