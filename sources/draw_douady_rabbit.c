/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_douady_rabbit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 00:11:52 by nbethany          #+#    #+#             */
/*   Updated: 2019/08/13 00:11:54 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_douady_rabbit(t_fractal *fractal)
{
	fractal->name = 4;
	fractal->x1 = -2.2;
	fractal->y1 = -2.5;
	fractal->c_re = 0.122;
	fractal->c_im = 0.744;
	fractal->zoom = 200;
	fractal->max_it = 50;
	fractal->color = 265;
}

void	douady_rabbit_calc(t_fractal *data)
{
	data->z_re = data->x / data->zoom + data->x1;
	data->z_im = data->y / data->zoom + data->y1;
	data->cur_it = 0;
	while (data->z_re * data->z_re + data->z_im * data->z_im <= 4
									&& data->cur_it < data->max_it)
	{
		data->tmp = data->z_re * data->z_re - data->z_im * data->z_im
																- data->c_re;
		data->z_im = 2 * data->z_re * data->z_im + data->c_im;
		data->z_re = data->tmp;
		data->cur_it++;
	}
	get_color(data);
}

void	*douady_rabbit(void *data)
{
	int			tmp;
	t_fractal	*fractal;

	fractal = (t_fractal *)data;
	fractal->x = 0;
	tmp = fractal->y;
	while (fractal->x < WIDTH)
	{
		fractal->y = tmp;
		while (fractal->y < fractal->y_max)
		{
			douady_rabbit_calc(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	return (data);
}
