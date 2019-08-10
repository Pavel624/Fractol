/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:13:18 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/23 21:13:21 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			index_matr(int row, int column, int width)
{
	return (row * width + column);
}

void		get_color(t_fractal *fractal)
{
	if (fractal->cur_it == fractal -> max_it)
		img_pixel_put(&fractal->image, fractal->x, fractal->y, 0);
	else
		img_pixel_put(&fractal->image, fractal->x, fractal-> y, fractal->cur_it * fractal->color);
}

void		img_pixel_put(t_image *img, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(img->ptr + (int)(index_matr(y, x, WIDTH) * img->bpp)) = color;
}

int			key_down(int key)
{
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (1);
}

int			key_trans(int key, t_fractal *fractal)
{
	if (key == KEY_DOWN)
		fractal->y1 -= 20 / fractal->zoom;
	else if (key == KEY_UP)
		fractal->y1 += 20 / fractal->zoom;
	else if (key == KEY_LEFT)
		fractal->x1 += 20 / fractal->zoom;
	else if (key == KEY_RIGHT)
		fractal->x1 -= 20 / fractal->zoom;
	else if (key == KEY_NUMPAD_1)
		fractal->color = 265;
	else if (key == KEY_NUMPAD_2)
		fractal->color = 100;
	else if (key == KEY_NUMPAD_3)
		fractal->color = 800;
	else if (key == KEY_NUMPAD_4)
		fractal->color = 1200;
	else if (key == KEY_L)
		fractal->lock = fractal->lock == 1 ? 0 : 1;
	calc_fractal(fractal);
	return (1);
}

int			mouse_moved(int x, int y, t_fractal *fractal)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && fractal->lock == 0) {
		if (x < WIDTH / 2 && y < HEIGHT / 2)
			fractal->cRe += 10;
		else if (x > WIDTH / 2 && y < HEIGHT / 2)
			fractal->cRe -= 10;
		else if (x < WIDTH / 2 && y > HEIGHT / 2)
			fractal->cIm += 10;
		else if (x > WIDTH / 2 && y > HEIGHT / 2)
			fractal->cIm -= 10;
		julia_pthread(fractal);
	}
	return (0);
}

void	zoom_in(int x, int y, t_fractal *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.2));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.2));
	data->zoom *= 1.2;
	data->max_it++;
}

void	zoom_out(int x, int y, t_fractal *data)
{
	data->x1 = (x / data->zoom + data->x1)  - (x / (data->zoom / 1.2));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	data->max_it--;
}


int			mouse(int button, int x, int y, t_fractal *fractal)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (button == 4)
			zoom_in(x, y, fractal);
		else if (button == 5)
			zoom_out(x, y, fractal);
		calc_fractal(fractal);
	}
	return (0);
}