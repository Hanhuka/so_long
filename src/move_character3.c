/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:41:31 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	remove_collectable_utils(t_objt	*tmp, int x, int y, int i)
{
	if ((((*objects(64))->x + x >= tmp->x
				&& (*objects(64))->x + x <= tmp->x2)
			|| ((*objects(64))->x2 + x >= tmp->x
				&& (*objects(64))->x2 + x <= tmp->x2))
		&& (((*objects(64))->y + y >= tmp->y
				&& (*objects(64))->y + y <= tmp->y2)
			|| ((*objects(64))->y2 + y >= tmp->y
				&& (*objects(64))->y2 + y <= tmp->y2)))
	{
		tmp->type = '0';
		tmp->img = (*sp()).wall5;
		(*counter()).collect -= 1;
		remove_colectables_size(i);
		if (!((*counter()).collect))
			open_exits();
	}
}
