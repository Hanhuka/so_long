/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:38:56 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_character(int x, int y)
{
	int		i;

	i = 'a';
	character_direction(x);
	if (!check_colision(x, y, '1'))
	{
		if (x || y)
			(*steps())++;
		move_all(x, y);
		if (check_colision2('C'))
			remove_collectable(x, y, 0);
	}
	while (i <= 'z')
	{
		if (check_colision2(i))
			exit_game("\e[1;91mYOU LOST\n\e[0m");
		i++;
	}
	if (check_colision2('E') && (*counter()).collect == 0)
		exit_game("\e[1;92mYOU WIN\n\e[0m");
}

int	check_colision(int x, int y, char type)
{
	t_objt	*tmp;

	tmp = (*objects(64));
	while (tmp)
	{
		if (tmp->type == type)
		{
			if ((((*objects(64))->x + x >= tmp->x
						&& (*objects(64))->x + x <= tmp->x2)
					|| ((*objects(64))->x2 + x >= tmp->x
						&& (*objects(64))->x2 + x <= tmp->x2))
				&& (((*objects(64))->y + y >= tmp->y
						&& (*objects(64))->y + y <= tmp->y2)
					|| ((*objects(64))->y2 + y >= tmp->y
						&& (*objects(64))->y2 + y <= tmp->y2)))
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	remove_colectables_size(int i)
{
	t_objt	*tmp16;
	t_objt	*tmp32;
	t_objt	*tmp48;

	tmp16 = (*objects(16));
	tmp32 = (*objects(32));
	tmp48 = (*objects(48));
	while (i > 0)
	{
		tmp16 = tmp16->next;
		tmp32 = tmp32->next;
		tmp48 = tmp48->next;
		i--;
	}
	tmp16->type = '0';
	tmp16->img = (*sp()).wall5;
	tmp32->type = '0';
	tmp32->img = (*sp()).wall5;
	tmp48->type = '0';
	tmp48->img = (*sp()).wall5;
}

void	open_exits(void)
{
	t_objt	*tmp;
	int		i;

	i = 64;
	while (i > 0)
	{
		tmp = (*objects(i));
		while (tmp)
		{
			if (tmp->type == 'E')
			{
				if (i == 64)
					tmp->img = (*sp()).exit_open;
				if (i == 48)
					tmp->img = (*sp()).exit_48_open;
				if (i == 32)
					tmp->img = (*sp()).exit_32_open;
				if (i == 16)
					tmp->img = (*sp()).exit_16_open;
			}
			tmp = tmp->next;
		}
		i -= 16;
	}
}

void	remove_collectable(int x, int y, int i)
{
	t_objt	*tmp;

	tmp = (*objects(64));
	while (tmp)
	{
		if (tmp->type == 'C')
			remove_collectable_utils(tmp, x, y, i);
		tmp = tmp->next;
		i++;
	}
}
