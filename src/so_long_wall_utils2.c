/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wall_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:26:25 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*walls_6(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y <= ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y][c.x - 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1'
	&& (*map())[c.y - 1][c.x + 1] == '1')
		return ((*sp()).wall8);
	if (c.x > 0 && c.y > 0 && c.x <= ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1'
	&& (*map())[c.y + 1][c.x - 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1')
		return ((*sp()).wall6);
	else
		return (NULL);
}

void	*walls_7(t_coord c)
{
	if (c.x >= 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y + 1][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x + 1] == '1')
		return ((*sp()).wall4);
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y <= ft_height((*map())) - 1
	&& (*map())[c.y][c.x + 1] == '1' && (*map())[c.y][c.x - 1] == '1'
	&& (*map())[c.y - 1][c.x] == '1'
	&& (*map())[c.y - 1][c.x + 1] == '1')
		return ((*sp()).wall33);
	else
		return (NULL);
}

void	*walls_8(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y <= ft_height((*map())) - 1
	&& (*map())[c.y][c.x + 1] == '1' && (*map())[c.y][c.x - 1] == '1'
	&& (*map())[c.y - 1][c.x] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1')
		return ((*sp()).wall34);
	if (c.x >= 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y + 1][c.x] == '1' && (*map())[c.y - 1][c.x] == '1'
	&& (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y + 1][c.x + 1] == '1')
		return ((*sp()).wall35);
	else
		return (NULL);
}

void	*walls_9(t_coord c)
{
	if (c.x >= 0 && c.y > 0 && c.x <= ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y + 1][c.x] == '1' && (*map())[c.y - 1][c.x] == '1'
	&& (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x + 1] == '1')
		return ((*sp()).wall36);
	if (c.x > 0 && c.y >= 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y][c.x + 1] == '1' && (*map())[c.y][c.x - 1] == '1'
	&& (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y + 1][c.x - 1] == '1')
		return ((*sp()).wall37);
	else
		return (NULL);
}

void	*walls_10(t_coord c)
{
	if (c.x > 0 && c.y >= 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y][c.x + 1] == '1' && (*map())[c.y][c.x - 1] == '1'
	&& (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y + 1][c.x + 1] == '1')
		return ((*sp()).wall38);
	if (c.x > 0 && c.y > 0 && c.x <= ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y + 1][c.x] == '1' && (*map())[c.y - 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1')
		return ((*sp()).wall39);
	if (c.x > 0 && c.y > 0 && c.x <= ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y + 1][c.x] == '1' && (*map())[c.y - 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1'
	&& (*map())[c.y + 1][c.x - 1] == '1')
		return ((*sp()).wall40);
	else
		return (NULL);
}
