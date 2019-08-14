/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:24:28 by nbethany          #+#    #+#             */
/*   Updated: 2019/08/12 22:24:30 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_burning_ship(t_fractal *fractal)
{
	fractal->name = 2;
	fractal->x1 = -2.2;
	fractal->y1 = -2.5;
	fractal->zoom = 200;
	fractal->max_it = 50;
	fractal->color = 265;
}

void	burning_ship_calc(t_fractal *data)
{
	data->c_re = data->x / data->zoom + data->x1;
	data->c_im = data->y / data->zoom + data->y1;
	data->z_re = 0;
	data->z_im = 0;
	data->cur_it = 0;
	while (data->z_re * data->z_re + data->z_im * data->z_im <= 4
									&& data->cur_it < data->max_it)
	{
		data->tmp = data->z_re * data->z_re - data->z_im * data->z_im
																+ data->c_re;
		data->z_im = 2 * fabs(data->z_re * data->z_im) + data->c_im;
		data->z_re = data->tmp;
		data->cur_it++;
	}
	get_color(data);
}

void	*burning_ship(void *data)
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
			burning_ship_calc(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	return (data);
}
