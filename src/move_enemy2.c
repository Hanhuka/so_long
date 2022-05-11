/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:44:23 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_direction(t_objt *tmp, int i, int x)
{
	if (x > 0)
	{
		if (i == 64)
			tmp->img = (*sp()).sus;
		if (i == 48)
			tmp->img = (*sp()).sus_48;
		if (i == 32)
			tmp->img = (*sp()).sus_32;
		if (i == 16)
			tmp->img = (*sp()).sus_16;
	}
	if (x < 0)
	{
		if (i == 64)
			tmp->img = (*sp()).sus_left;
		if (i == 48)
			tmp->img = (*sp()).sus_48_left;
		if (i == 32)
			tmp->img = (*sp()).sus_32_left;
		if (i == 16)
			tmp->img = (*sp()).sus_16_left;
	}
}
