/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wall_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:19:34 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*walls_1(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1' && (*map())[c.y + 1][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x + 1] == '1' && (*map())[c.y + 1][c.x - 1] == '1')
		return ((*sp()).wall5);
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] != '1' && (*map())[c.y + 1][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x + 1] == '1' && (*map())[c.y + 1][c.x - 1] == '1')
		return ((*sp()).wall17);
	else
		return (NULL);
}

void	*walls_2(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1' && (*map())[c.y + 1][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x + 1] != '1' && (*map())[c.y + 1][c.x - 1] == '1')
		return ((*sp()).wall18);
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1' && (*map())[c.y + 1][c.x + 1] != '1'
	&& (*map())[c.y - 1][c.x + 1] == '1' && (*map())[c.y + 1][c.x - 1] == '1')
		return ((*sp()).wall19);
	else
		return (NULL);
}

void	*walls_3(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1' && (*map())[c.y + 1][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x + 1] == '1' && (*map())[c.y + 1][c.x - 1] != '1')
		return ((*sp()).wall20);
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] != '1' && (*map())[c.y + 1][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x + 1] != '1' && (*map())[c.y + 1][c.x - 1] == '1')
		return ((*sp()).wall21);
	else
		return (NULL);
}

void	*walls_4(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1' && (*map())[c.y + 1][c.x + 1] != '1'
	&& (*map())[c.y - 1][c.x + 1] != '1' && (*map())[c.y + 1][c.x - 1] == '1')
		return ((*sp()).wall22);
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1' && (*map())[c.y + 1][c.x + 1] != '1'
	&& (*map())[c.y - 1][c.x + 1] == '1' && (*map())[c.y + 1][c.x - 1] != '1')
		return ((*sp()).wall23);
	else
		return (NULL);
}

void	*walls_5(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] != '1' && (*map())[c.y + 1][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x + 1] == '1' && (*map())[c.y + 1][c.x - 1] != '1')
		return ((*sp()).wall24);
	if (c.x > 0 && c.y >= 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y + 1][c.x] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y][c.x - 1] == '1'
	&& (*map())[c.y + 1][c.x - 1] == '1'
	&& (*map())[c.y + 1][c.x + 1] == '1')
		return ((*sp()).wall2);
	else
		return (NULL);
}
