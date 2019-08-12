/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:06:28 by nbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:06:30 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static	int	close_app(void *param)
{
	(void)param;
	exit(0);
}

static	void	ft_error(char *msg, int i)
{
    ft_putstr(msg);
    exit(i);
}

void calc_fractal(t_fractal *fractal)
{
	if (fractal->max_it < 0)
		fractal->max_it = 0;
	if (fractal->name == 0)
		julia_pthread(fractal);
	else if (fractal->name == 1)
		mandelbrot_pthread(fractal);
	else if (fractal->name == 2)
		burning_ship_pthread(fractal);
	else if (fractal->name == 3)
		tricorn_pthread(fractal);
	else if (fractal->name == 4)
		douady_rabbit_pthread(fractal);
}

void draw(t_fractal *fractal)
{
	if (fractal-> name == 0)
		init_julia(fractal);
	else if (fractal->name == 1)
		init_mandelbrot(fractal);
	else if (fractal->name == 2)
		init_burning_ship(fractal);
	else if (fractal->name == 3)
		init_tricorn(fractal);
	else if (fractal->name == 4)
		init_douady_rabbit(fractal);
	calc_fractal(fractal);
}

int select_fractal(t_fractal *fractal, char* param)
{
	if (ft_strcmp("julia",param) == 0)
		fractal->name = 0;
	else if (ft_strcmp("mandelbrot", param) == 0)
		fractal->name = 1;
	else if (ft_strcmp("burning_ship", param) == 0)
		fractal->name = 2;
	else if (ft_strcmp("tricorn", param) == 0)
		fractal->name = 3;
	else if (ft_strcmp("douady_rabbit", param) == 0)
		fractal->name = 4;
	else
		return (0);
	return (1);
}

void			init(t_fractal *fractal)
{
	t_image *image;

	image = &fractal->image;
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractol");
	image->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	image->ptr = mlx_get_data_addr(image->image, &image->bpp,
								   &image->line_s, &image->endian);
	image->bpp /= 8;
}



int main(int argc, char *argv[])
{
	t_fractal fractal;

    if (argc != 2 || !select_fractal(&fractal, argv[1]))
		ft_error("usage: ./fractol [julia]/[mandelbrot]/[burning_ship]/[tricorn]/[douady_rabbit]\n", 0);
    init(&fractal);
    draw(&fractal);
	mlx_key_hook(fractal.window, key_down, &fractal);
	mlx_hook(fractal.window, 4, (1L << 2), mouse, &fractal);
	mlx_hook(fractal.window, 2, (1L << 0), key_trans, &fractal);
	mlx_hook(fractal.window, 6, (1L << 13), mouse_moved, &fractal);
    mlx_hook(fractal.window, 17, 0L, close_app, &fractal);
    mlx_loop((&fractal)->mlx);
    return (0);
}
