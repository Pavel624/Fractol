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

void		initialize_image(t_render *render)
{
	t_image	*image;

	image = &render->image;
	image->image = mlx_new_image(render->mlx, WIDTH, HEIGHT);
	image->ptr = mlx_get_data_addr(image->image, &image->bpp,
								   &image->line_s, &image->endian);
	image->bpp /= 8;
}

void			init(t_render *render)
{

	render->mlx = mlx_init();
	render->window = mlx_new_window(render->mlx, WIDTH, HEIGHT, "FDF");
}

int main(int argc, char *argv[])
{
	t_render render;
	t_fractal fractal;

    if (argc < 2)
		ft_error("Not enough arguments\n", 0);
    fractal.name = argv[1];
    init(&render);
    initialize_image(&render);
    mlx_hook(render.window, 17, 0L, close_app, &render);
    mlx_loop((&render)->mlx);
    return (0);
}
