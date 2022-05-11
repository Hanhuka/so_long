/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:37:10 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

void	create_by_size(void)
{
	int	i;

	i = 16;
	while (i <= 64)
	{
		(*x_type()) = 'a';
		create_objects(i);
		if ((*x_type()) < 9)
			(*x_type()) += 1;
			i += 16;
	}
}

void	create_player_util(t_coord c, int size)
{
	if (size == 64)
		create_object((*sp()).bee_left, c, size, 'P');
	if (size == 48)
		create_object((*sp()).bee_left_48, c, size, 'P');
	if (size == 32)
		create_object((*sp()).bee_left_32, c, size, 'P');
	if (size == 16)
		create_object((*sp()).bee_left_16, c, size, 'P');
}

void	create_player(int size)
{
	t_coord	c;

	c.y = 0;
	while ((*map())[c.y / size])
	{
		c.x = 0;
		while ((*map())[c.y / size][c.x / size])
		{
			if ((*map())[c.y / size][c.x / size] == 'P')
			{
				create_player_util(c, size);
				return ;
			}
			c.x += size;
		}
		c.y += size;
	}
}

void	create_enemy_util(t_coord c, int size)
{
	if (size == 64)
		create_object((*sp()).sus, c, size, *x_type());
	if (size == 48)
		create_object((*sp()).sus_48, c, size, *x_type());
	if (size == 32)
		create_object((*sp()).sus_32, c, size, *x_type());
	if (size == 16)
		create_object((*sp()).sus_16, c, size, *x_type());
}
