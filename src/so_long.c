/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:29:22 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/26 17:44:45 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <math.h>

t_coord	*init_p(void)
{
	static t_coord	c;

	return (&c);
}

t_win	*window(void)
{
	static t_win	win;

	return (&win);
}

int	animations(t_win *win)
{
	animation(win);
	enemys(win);
	nyan(win);
	return (0);
}

int	animation(t_win *win)
{
	static int	i;

	if (i < 5000)
	{
		i++;
		return (0);
	}
	i = 0;
	animate_collectable();
	mlx_clear_window((*win).mlx, (*win).mlx_win);
	print_to_window(win);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2 && ac != 3)
		return (1);
	check_file(av[1]);
	checker(av[1], map());
	(*window()).size = 20;
	(*window()).px_size = 64;
	(*window()).mlx = mlx_init();
	(*window()).width = (*window()).px_size * (*window()).size;
	(*window()).height = (*window()).px_size * (*window()).size;
	(*window()).mlx_win = mlx_new_window((*window()).mlx, (*window()).width
			+ (5 * 64), (*window()).height, "Honey Catcher");
	init_sprites(window(), ac, av);
	stackadd_back(collec(), new_module((*sp()).collectable));
	stackadd_back(collec(), new_module((*sp()).collectable2));
	stackadd_back(collec(), new_module((*sp()).collectable3));
	(*x_type()) = 'a';
	create_by_size();
	(*init_p()).x = (*objects(64))->x;
	(*init_p()).y = (*objects(64))->y;
	print_to_window(window());
	mlx_hook((*window()).mlx_win, 2, 1, key_down, window());
	mlx_hook((*window()).mlx_win, 3, 1, key_up, window());
	mlx_hook((*window()).mlx_win, 17, 0, window_close, window());
	mlx_loop_hook((*window()).mlx, animations, window());
	mlx_loop((*window()).mlx);
}
