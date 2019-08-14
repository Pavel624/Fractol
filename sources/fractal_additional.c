/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_additional.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:56:30 by nbethany          #+#    #+#             */
/*   Updated: 2019/08/14 19:56:31 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fractal_pthread(t_fractal *data, void *(func)(void *))
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
		pthread_create(&threads[i], NULL, func, &fractals[i]);
		i++;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
}

void calc_fractal(t_fractal *fractal)
{
	if (fractal->max_it < 0)
		fractal->max_it = 0;
	if (fractal->name == 0)
		fractal_pthread(fractal, julia);
	else if (fractal->name == 1)
		fractal_pthread(fractal, mandelbrot);
	else if (fractal->name == 2)
		fractal_pthread(fractal, burning_ship);
	else if (fractal->name == 3)
		fractal_pthread(fractal, tricorn);
	else if (fractal->name == 4)
		fractal_pthread(fractal, douady_rabbit);
	else if (fractal->name == 5)
		fractal_pthread(fractal, celtic_mandelbrot);
	else if (fractal->name == 6)
		fractal_pthread(fractal, heart_mandelbrot);
}

int select_fractal(t_fractal *fractal, char* param)
{
	if (ft_strcmp("julia",param) == 0)
		init_julia(fractal);
	else if (ft_strcmp("mandelbrot", param) == 0)
		init_mandelbrot(fractal);
	else if (ft_strcmp("burning_ship", param) == 0)
		init_burning_ship(fractal);
	else if (ft_strcmp("tricorn", param) == 0)
		init_tricorn(fractal);
	else if (ft_strcmp("douady_rabbit", param) == 0)
		init_douady_rabbit(fractal);
	else if (ft_strcmp("celtic_mandelbrot", param) == 0)
		init_celtic_mandelbrot(fractal);
	else if (ft_strcmp("heart_mandelbrot", param) == 0)
		init_heart_mandelbrot(fractal);
	else
		return (0);
	return (1);
}