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
	while (data->zRe * data->zRe + data->zIm * data->zIm < 4 && data->cur_it < data->max_it)
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
		while (data->y < data->ymax)
		{
			julia_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	julia_pthread(t_fractal *data)
{
	t_fractal	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_fractal));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].ymax = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, julia, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
}