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
	fractal->x = 0;
	fractal->y = 0;
	fractal->c_re = -0.7;
	fractal->c_im = -0.54;
	fractal->zoom = 1;
	fractal->moveX = 0;
	fractal->moveY = 0;
	fractal->cur_iteration = 0;
	fractal->max_iterations = 128;
}

void julia(t_fractal *fractal)
{
	double newRe, newIm, oldRe, oldIm;
	init_julia(fractal);
	while (fractal->y < HEIGHT)
	{
		while (fractal->x < WIDTH)
		{
			newRe = 1.5 * (fractal->x - WIDTH / 2) / (0.5 * fractal->zoom * WIDTH) + fractal->moveX;
			newIm = (fractal->y - HEIGHT / 2) / (0.5 * fractal->zoom * HEIGHT) + fractal->moveY;

			while (fractal->cur_iteration < fractal->max_iterations)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = pow(oldRe, 2)  - pow(oldIm, 2) + fractal->c_re;
				newIm = 2 * oldRe * oldIm + fractal->c_im;
				if (pow(newRe, 2) + pow(newIm, 2) > 4)
					break;
				fractal->cur_iteration++;
			}
			get_color(fractal);
			fractal->cur_iteration = 30;
			fractal->x++;
		}
		fractal->y++;
		fractal->x = 0;
	}
	fractal->x = 0;
	fractal->y = 0;
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image.image, 0, 0);
}