/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:37:04 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_every_enemy(void)
{
	int		i;
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		i = rand();
		if (i % 8 == 0)
			move_enemy(c, 1, 0);
		if (i % 8 == 1)
			move_enemy(c, 1, 1);
		if (i % 8 == 2)
			move_enemy(c, 0, 1);
		if (i % 8 == 3)
			move_enemy(c, -1, 1);
		if (i % 8 == 4)
			move_enemy(c, -1, 0);
		if (i % 8 == 5)
			move_enemy(c, -1, -1);
		if (i % 8 == 6)
			move_enemy(c, 0, -1);
		if (i % 8 == 7)
			move_enemy(c, 1, -1);
		c += 1;
	}
}

void	move_enemy(char xtype, int x, int y)
{
	if (!check_colision_enemy(x, y, '1', xtype))
		move_e_all(x, y, xtype);
	if (check_colision_enemy(x, y, '1', xtype) == 2)
		return ;
	if (check_colision_enemy2('P', xtype))
		exit_game("\e[1;91mYOU LOST\n\e[0m");
}

void	move_e_all(int x, int y, char xtype)
{
	t_objt	*tmp;
	int		i;

	i = 64;
	while (i >= 16)
	{
		tmp = (*objects(i));
		while (tmp && tmp->type != xtype)
			tmp = tmp->next;
		enemy_direction(tmp, i, x);
		if (tmp->type != xtype)
			return ;
		tmp->x += (i / 4) * x;
		tmp->x2 += (i / 4) * x;
		tmp->y += (i / 4) * y;
		tmp->y2 += (i / 4) * y;
		i -= 16;
	}
}

int	check_colision_enemy(int x, int y, char type, char typeX)
{
	t_objt	*tmp;
	t_objt	*tmp2;

	tmp = (*objects(64));
	tmp2 = (*objects(64));
	while (tmp2 && tmp2->type != typeX)
		tmp2 = tmp2->next;
	if (!tmp2)
		return (2);
	while (tmp)
	{
		if (tmp->type == type)
		{
			if (((tmp2->x + x >= tmp->x && tmp2->x + x <= tmp->x2)
					|| (tmp2->x2 + x >= tmp->x && tmp2->x2 + x <= tmp->x2))
				&& ((tmp2->y + y >= tmp->y && tmp2->y + y <= tmp->y2)
					|| (tmp2->y2 + y >= tmp->y
						&& tmp2->y2 + y <= tmp->y2)))
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_colision_enemy2(char type, char typeX)
{
	t_objt	*tmp;
	t_objt	*tmp2;

	tmp = (*objects(64));
	tmp2 = (*objects(64));
	while (tmp2 && tmp2->type != typeX)
		tmp2 = tmp2->next;
	if (!tmp2)
		return (2);
	while (tmp)
	{
		if (tmp->type == type)
		{
			if (((tmp2->x >= tmp->x && tmp2->x <= tmp->x2)
					|| (tmp2->x2 >= tmp->x && tmp2->x2 <= tmp->x2))
				&& ((tmp2->y >= tmp->y && tmp2->y <= tmp->y2)
					|| (tmp2->y2 >= tmp->y
						&& tmp2->y2 <= tmp->y2)))
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
