/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:04:45 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	*steps(void)
{
	static int	steps;

	return (&steps);
}

t_coord	c_pos(char **map)
{
	t_coord	c;

	c.y = 0;
	while (map[c.y])
	{
		c.x = 0;
		while (map[c.y][c.x])
		{
			if (map[c.y][c.x] == 'P')
			{
				return (c);
			}
			c.x++;
		}
		c.y++;
	}
	return (c);
}

void	move_all(int x, int y)
{
	int	i;

	i = 64;
	while (i >= 16)
	{
		(*objects(i))->x += (i / 4) * x;
		(*objects(i))->x2 += (i / 4) * x;
		(*objects(i))->y += (i / 4) * y;
		(*objects(i))->y2 += (i / 4) * y;
		i -= 16;
	}
}

void	character_direction(int x)
{
	if (x > 0)
	{
		(*objects(64))->img = ((*sp()).bee_right);
		(*objects(48))->img = ((*sp()).bee_right_48);
		(*objects(32))->img = ((*sp()).bee_right_32);
		(*objects(16))->img = ((*sp()).bee_right_16);
	}
	if (x < 0)
	{
		(*objects(64))->img = ((*sp()).bee_left);
		(*objects(48))->img = ((*sp()).bee_left_48);
		(*objects(32))->img = ((*sp()).bee_left_32);
		(*objects(16))->img = ((*sp()).bee_left_16);
	}
}

int	check_colision2(char type)
{
	t_objt	*tmp;

	tmp = (*objects(64));
	while (tmp)
	{
		if (tmp->type == type)
		{
			if ((((*objects(64))->x >= tmp->x
						&& (*objects(64))->x <= tmp->x2)
					|| ((*objects(64))->x2 >= tmp->x
						&& (*objects(64))->x2 <= tmp->x2))
				&& (((*objects(64))->y >= tmp->y
						&& (*objects(64))->y <= tmp->y2)
					|| ((*objects(64))->y2 >= tmp->y
						&& (*objects(64))->y2 <= tmp->y2)))
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
