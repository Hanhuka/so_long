/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:38:48 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_collectables(void)
{
	t_coord	c;

	c.y = 0;
	while ((*map())[c.y])
	{
		c.x = 0;
		while ((*map())[c.y][c.x])
		{
			if ((*map())[c.y][c.x] == 'C')
				(*counter()).collect += 1;
			c.x++;
		}
		c.y++;
	}
}

void	init_walls5(t_win *win, int *s)
{
	((*sp())).wall_48 = mlx_xpm_file_to_image((*win).mlx,
			"wall_48.xpm", s, s);
	((*sp())).wall_32 = mlx_xpm_file_to_image((*win).mlx,
			"wall_32.xpm", s, s);
	((*sp())).wall_16 = mlx_xpm_file_to_image((*win).mlx,
			"wall_16.xpm", s, s);
	((*sp()).sus) = mlx_xpm_file_to_image((*win).mlx,
			"Sus_64.xpm", s, s);
	((*sp()).sus_left) = mlx_xpm_file_to_image((*win).mlx,
			"Sus_64_left.xpm", s, s);
	((*sp()).sus_48) = mlx_xpm_file_to_image((*win).mlx,
			"Sus_48.xpm", s, s);
	((*sp()).sus_48_left) = mlx_xpm_file_to_image((*win).mlx,
			"Sus_48_left.xpm", s, s);
	((*sp()).sus_32) = mlx_xpm_file_to_image((*win).mlx,
			"Sus_32.xpm", s, s);
	((*sp()).sus_32_left) = mlx_xpm_file_to_image((*win).mlx,
			"Sus_32_left.xpm", s, s);
	((*sp()).sus_16) = mlx_xpm_file_to_image((*win).mlx,
			"Sus_16.xpm", s, s);
	((*sp()).sus_16_left) = mlx_xpm_file_to_image((*win).mlx,
			"Sus_16_left.xpm", s, s);
}

void	init_exits(t_win *win, int s)
{
	((*sp()).exit) = mlx_xpm_file_to_image((*win).mlx,
			"Exit_64.xpm", &s, &s);
	((*sp()).exit_48) = mlx_xpm_file_to_image((*win).mlx,
			"Exit_48.xpm", &s, &s);
	((*sp()).exit_32) = mlx_xpm_file_to_image((*win).mlx,
			"Exit_32.xpm", &s, &s);
	((*sp()).exit_16) = mlx_xpm_file_to_image((*win).mlx,
			"Exit_16.xpm", &s, &s);
	((*sp()).exit_open) = mlx_xpm_file_to_image((*win).mlx,
			"Exit_64_open.xpm", &s, &s);
	((*sp()).exit_48_open) = mlx_xpm_file_to_image((*win).mlx,
			"Exit_48_open.xpm", &s, &s);
	((*sp()).exit_32_open) = mlx_xpm_file_to_image((*win).mlx,
			"Exit_32_open.xpm", &s, &s);
	((*sp()).exit_16_open) = mlx_xpm_file_to_image((*win).mlx,
			"Exit_16_open.xpm", &s, &s);
}

void	init_sprites(t_win *win, int ac, char **av)
{
	int	s;

	if (ac == 2)
		((*sp()).background) = mlx_xpm_file_to_image((*win).mlx,
				"Fundo_2048_1.xpm", &s, &s);
	if (ac == 3)
	{
		if (ft_strlen(av[2]) == 1 && av[2][0] == '0')
			;
		else if (ft_strlen(av[2]) == 1 && av[2][0] == '1')
			((*sp()).background) = mlx_xpm_file_to_image((*win).mlx,
					"so_long_bckg.xpm", &s, &s);
		else
			errors("\e[1;91mError\nWrong arguments\n\e[0m");
	}
	init_sprites2(win, s);
	init_exits(win, s);
	init_bees(win, s);
	init_walls1(win, &s);
	init_walls2(win, &s);
	init_walls3(win, &s);
	init_walls4(win, &s);
	init_walls5(win, &s);
	init_collectables();
}

void	init_sprites2(t_win *win, int s)
{
	s = 64;
	((*sp()).side_info) = mlx_xpm_file_to_image((*win).mlx,
			"side_info_3.xpm", &s, &s);
	((*sp()).collectable) = mlx_xpm_file_to_image((*win).mlx,
			"Collectable_1.xpm", &s, &s);
	((*sp()).collectable2) = mlx_xpm_file_to_image((*win).mlx,
			"Collectable_2.xpm", &s, &s);
	((*sp()).collectable3) = mlx_xpm_file_to_image((*win).mlx,
			"Collectable_3.xpm", &s, &s);
	((*sp()).collectable_16) = mlx_xpm_file_to_image((*win).mlx,
			"Collectable_16.xpm", &s, &s);
	((*sp()).collectable_32) = mlx_xpm_file_to_image((*win).mlx,
			"Collectable_32.xpm", &s, &s);
	((*sp()).collectable_48) = mlx_xpm_file_to_image((*win).mlx,
			"Collectable_48.xpm", &s, &s);
}
