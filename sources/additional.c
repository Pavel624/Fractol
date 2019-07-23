/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:13:18 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/23 21:13:21 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			index_matr(int row, int column, int width)
{
	return (row * width + column);
}

void		get_color(t_fractal *fractal)
{
	if (fractal->cur_iteration == fractal -> max_iterations)
		img_pixel_put(&fractal->image, fractal->x, fractal-> y, 0);
	else
		img_pixel_put(&fractal->image, fractal->x, fractal-> y, fractal->cur_iteration * 1100000);
}

void		img_pixel_put(t_image *img, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(img->ptr + (int)(index_matr(y, x, WIDTH) * img->bpp)) = color;
}