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

void	init_julia(t_fractal *fractal)
{
	fractal->name = 0;
	fractal->mouse.x = WIDTH / 2.0;
	fractal->mouse.y = HEIGHT / 2.0;
	fractal->x1 = -2.3;
	fractal->y1 = -2.3;
	fractal->c_re = -0.85;
	fractal->c_im = 0;
	fractal->zoom = 200;
	fractal->max_it = 50;
	fractal->color = 265;
	fractal->lock = 0;
}

void	julia_calc(t_fractal *data)
{
	data->z_re = data->x / data->zoom + data->x1;
	data->z_im = data->y / data->zoom + data->y1;
	data->cur_it = 0;
	while (data->z_re * data->z_re + data->z_im * data->z_im <= 4
									&& data->cur_it < data->max_it)
	{
		data->tmp = data->z_re;
		data->z_re = data->z_re * data->z_re - data->z_im * data->z_im
																+ data->c_re;
		data->z_im = 2 * data->z_im * data->tmp + data->c_im;
		data->cur_it++;
	}
	get_color(data);
}

void	*julia(void *data)
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
			julia_calc(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	return (data);
}
