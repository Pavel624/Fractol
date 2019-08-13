/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:32:00 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/23 21:32:01 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void init_julia(t_fractal *fractal)
{
	fractal->mouse.x0 = 0;
	fractal->mouse.y0 = 0;
	fractal->mouse.x = 0;
	fractal->mouse.y = 0;
	fractal->x1 = -2.3;
	fractal->y1 = -2.3;
	fractal->cRe = 0.285;
	fractal->cIm = 0.01;
	fractal->zoom = 200;
	fractal->max_it = 50;
	fractal->color = 265;
	fractal->lock = 0;
}

void	julia_calc(t_fractal *data)
{
	data->zRe = data->x / data->zoom + data->x1;
	data->zIm = data->y / data->zoom + data->y1;
	data->cur_it = 0;
	while (data->zRe * data->zRe + data->zIm * data->zIm <= 4 && data->cur_it < data->max_it)
	{
		data->tmp = data->zRe;
		data->zRe = data->zRe * data->zRe - data->zIm * data->zIm - 0.8 + (data->cRe / WIDTH);
		data->zIm = 2 * data->zIm * data->tmp + data->cIm / WIDTH;
		data->cur_it++;
	}
	get_color(data);
}

void	*julia(void *tab)
{
	int		tmp;
	t_fractal	*data;

	data = (t_fractal *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			julia_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}