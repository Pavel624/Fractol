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

static	void	init(t_fractal *fractal)
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
		ft_error("usage: ./fractol [julia]/[mandelbrot]/[burning_ship]/[tricorn]/[douady_rabbit]/[celtic_mandelbrot]/[heart_mandelbrot]\n", 0);
    init(&fractal);
    calc_fractal(&fractal);
    print_menu();
	mlx_key_hook(fractal.window, key_down, &fractal);
	mlx_hook(fractal.window, 4, (1L << 2), mouse, &fractal);
	mlx_hook(fractal.window, 2, (1L << 0), key_trans, &fractal);
	mlx_hook(fractal.window, 6, (1L << 13), mouse_moved, &fractal);
    mlx_hook(fractal.window, 17, 0L, close_app, &fractal);
    mlx_loop((&fractal)->mlx);
    return (0);
}
