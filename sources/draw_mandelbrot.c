/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:32:00 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/24 21:32:01 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"

void init_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->cRe = -0.7;
	fractal->cIm = -0.54;
	fractal->zoom = 100;
	fractal->moveX = -0.5;
	fractal->moveY = 0;
	fractal->cur_it = 0;
	fractal->max_it = 128;
}

void	mandelbrot(t_fractal *fractal)
{
	double newRe, newIm, oldRe, oldIm;
	double pr, pi;
	while (fractal->y < HEIGHT)
	{
		while (fractal->x < WIDTH)
		{
			pr = 1.5 * (fractal->x - WIDTH / 2) / (0.5 * fractal->zoom * WIDTH) + fractal->moveX;
			pi = (fractal->y - HEIGHT / 2) / (0.5 * fractal->zoom * HEIGHT) + fractal->moveY;
			newRe = newIm = oldRe = oldIm = 0;
			while (fractal->cur_it < fractal->max_it)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = pow(oldRe, 2)  - pow(oldIm, 2) + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if (pow(newRe, 2) + pow(newIm, 2) > 4)
					break;
				fractal->cur_it++;
			}
			get_color(fractal);
			fractal->cur_it = 30;
			fractal->x++;
		}
		fractal->y++;
		fractal->x = 0;
	}
	fractal->x = 0;
	fractal->y = 0;
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image.image, 0, 0);
}