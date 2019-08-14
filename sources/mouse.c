/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:38:39 by nbethany          #+#    #+#             */
/*   Updated: 2019/08/14 20:38:41 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		mouse_moved(int x, int y, t_fractal *fractal)
{
	t_mouse *mouse;

	mouse = &fractal->mouse;
	mouse->x0 = mouse->x;
	mouse->y0 = mouse->y;
	mouse->x = x;
	mouse->y = y;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && fractal->lock == 0)
	{
		fractal->c_re += (mouse->x - mouse->x0) / WIDTH;
		fractal->c_im += (mouse->y - mouse->y0) / WIDTH;
		fractal_pthread(fractal, julia);
	}
	return (0);
}

void	zoom_in(int x, int y, t_fractal *fractal)
{
	fractal->x1 = (x / fractal->zoom + fractal->x1) - x / (fractal->zoom * 1.2);
	fractal->y1 = (y / fractal->zoom + fractal->y1) - y / (fractal->zoom * 1.2);
	fractal->zoom *= 1.2;
	fractal->max_it++;
}

void	zoom_out(int x, int y, t_fractal *fractal)
{
	fractal->x1 = (x / fractal->zoom + fractal->x1) - x / (fractal->zoom / 1.2);
	fractal->y1 = (y / fractal->zoom + fractal->y1) - y / (fractal->zoom / 1.2);
	fractal->zoom /= 1.2;
	fractal->max_it--;
}

int		mouse(int button, int x, int y, t_fractal *fractal)
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
