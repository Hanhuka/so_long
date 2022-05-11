/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:32:35 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_exit(t_coord c, int size)
{
	if (size == 64)
		create_object((*sp()).exit, c, size, 'E');
	if (size == 48)
		create_object((*sp()).exit_48, c, size, 'E');
	if (size == 32)
		create_object((*sp()).exit_32, c, size, 'E');
	if (size == 16)
		create_object((*sp()).exit_16, c, size, 'E');
}

void	create_objects(int size)
{
	t_coord	c;
	t_coord	d;

	c.y = 0;
	create_player(size);
	create_enemy(size);
	while ((*map())[c.y / size])
	{
		c.x = 0;
		while ((*map())[c.y / size][c.x / size])
		{
			if ((*map())[c.y / size][c.x / size] == '1')
			{
				d.x = c.x / size;
				d.y = c.y / size;
				create_object(put_walls(size, d), c, size, '1');
			}
			if ((*map())[c.y / size][c.x / size] == 'C')
				create_collectables(c, size);
			if ((*map())[c.y / size][c.x / size] == 'E')
				create_exit(c, size);
			c.x += size;
		}
		c.y += size;
	}
}
