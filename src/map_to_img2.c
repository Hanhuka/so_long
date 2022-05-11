/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:30:02 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:56:32 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_enemy(int size)
{
	t_coord	c;

	c.y = 0;
	while ((*map())[c.y / size])
	{
		if (*x_type() > 'z')
			return ;
		c.x = 0;
		while ((*map())[c.y / size][c.x / size])
		{
			if ((*map())[c.y / size][c.x / size] == 'X')
			{
				if ((*x_type()) <= 'z')
					create_enemy_util(c, size);
				else
					return ;
				(*x_type()) += 1;
			}
			c.x += size;
		}
		c.y += size;
	}
}

void	create_object(void *img, t_coord c, int size, char type)
{
	t_objt	*ob;
	t_objt	*tmp;

	ob = malloc(sizeof(t_objt));
	if (!ob)
		return ;
	ob->next = NULL;
	ob->img = img;
	ob->x = c.x;
	ob->x2 = c.x + size - 1;
	ob->y = c.y;
	ob->y2 = c.y + size - 1;
	ob->type = type;
	if (!(*objects(size)))
		(*objects(size)) = ob;
	else
	{
		tmp = (*objects(size));
		while ((*objects(size))->next)
			(*objects(size)) = (*objects(size))->next;
		(*objects(size))->next = ob;
		(*objects(size)) = tmp;
	}
}

void	*put_walls(int size, t_coord c)
{
	if (size == 64)
		return (wall_cond2(c));
	if (size == 48)
		return (((*sp())).wall_48);
	if (size == 32)
		return (((*sp())).wall_32);
	else
		return (((*sp())).wall_16);
}

void	create_collectables(t_coord c, int size)
{
	if (size == 64)
		create_object((*collec())->img, c, size, 'C');
	if (size == 48)
		create_object((*sp()).collectable_48, c, size, 'C');
	if (size == 32)
		create_object((*sp()).collectable_32, c, size, 'C');
	if (size == 16)
		create_object((*sp()).collectable_16, c, size, 'C');
}
