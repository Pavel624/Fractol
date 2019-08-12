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

# include "../fractol.h"

void init_douady_rabbit(t_fractal *fractal)
{
	fractal->x1 = -2.2;
	fractal->y1 = -2.5;
	fractal->cRe = 0.122;
	fractal->cIm = 0.744;
	fractal->zoom = 200;
	fractal->max_it = 50;
	fractal->color = 265;
}

void	douady_rabbit_calc(t_fractal *data)
{
	data->zRe = data->x / data->zoom + data->x1;
	data->zIm = data->y / data->zoom + data->y1;
	data->cur_it = 0;
	while (data->zRe * data->zRe + data->zIm * data->zIm < 4 && data->cur_it < data->max_it)
	{
		data->tmp = data->zRe * data->zRe - data->zIm * data->zIm - data->cRe;
		data->zIm = 2 * data->zRe * data->zIm + data->cIm;
		data->zRe = data->tmp;
		data->cur_it++;
	}
	get_color(data);
}

void	*douady_rabbit(void *tab)
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
			douady_rabbit_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	douady_rabbit_pthread(t_fractal *data)
{
	t_fractal	fractals[THREAD_NUMBER];
	pthread_t	threads[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		fractals[i] = *data;
		fractals[i].y = THREAD_WIDTH * i;
		fractals[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&threads[i], NULL, douady_rabbit, &fractals[i]);
		i++;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
}