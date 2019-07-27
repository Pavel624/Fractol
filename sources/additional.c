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
		fractal->moveY -= 0.01 / fractal->zoom;
	else if (key == KEY_UP)
		fractal->moveY += 0.01 / fractal->zoom;
	else if (key == KEY_LEFT)
		fractal->moveX += 0.01 / fractal->zoom;
	else if (key == KEY_RIGHT)
		fractal->moveX -= 0.01 / fractal->zoom;
	draw(fractal);
	return (1);
}

int			mouse_moved(int x, int y, t_fractal *fractal)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (x < WIDTH / 2 && y < HEIGHT / 2)
			fractal->cRe += 0.001;
		else if (x > WIDTH / 2 && y < HEIGHT / 2)
			fractal->cRe -= 0.001;
		else if (x < WIDTH / 2 && y > HEIGHT / 2)
			fractal->cIm += 0.001;
		else if (x > WIDTH / 2 && y > HEIGHT / 2)
			fractal->cIm -= 0.001;
	}
	julia(fractal);
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