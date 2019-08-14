/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:13:18 by nbethany          #+#    #+#             */
/*   Updated: 2019/08/14 23:23:31 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	print_menu(void)
{
	ft_putstr("Menu:\n[ESC] Exit\n[NUMPAD 1-5] Change color scheme\n"
			"[ARROW KEYS] Move fractal\n[MOUSE WHEEL] Zoom in and out\n"
			"[L] Lock current constant in julia set\n");
}

void	get_color(t_fractal *fractal)
{
	if (fractal->cur_it == fractal->max_it)
		img_pixel_put(&fractal->image, fractal->x, fractal->y, 0);
	else
		img_pixel_put(&fractal->image, fractal->x, fractal->y,
				fractal->cur_it * fractal->color);
}

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(img->ptr + (int)((x + y * WIDTH) * img->bpp)) = color;
}

int		key_down(int key)
{
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (1);
}

int		key_trans(int key, t_fractal *fractal)
{
	if (key == KEY_DOWN)
		fractal->y1 -= 20 / fractal->zoom;
	else if (key == KEY_UP)
		fractal->y1 += 20 / fractal->zoom;
	else if (key == KEY_LEFT)
		fractal->x1 += 20 / fractal->zoom;
	else if (key == KEY_RIGHT)
		fractal->x1 -= 20 / fractal->zoom;
	else if (key == KEY_NUMPAD_1)
		fractal->color = 0x000109;
	else if (key == KEY_NUMPAD_2)
		fractal->color = 0x090201;
	else if (key == KEY_NUMPAD_3)
		fractal->color = 0x040B28;
	else if (key == KEY_NUMPAD_4)
		fractal->color = 0x240F4F;
	else if (key == KEY_NUMPAD_5)
		fractal->color = 0x0FA5A0;
	else if (key == KEY_L && fractal->name == 0)
		fractal->lock = fractal->lock == 1 ? 0 : 1;
	calc_fractal(fractal);
	return (1);
}
