/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wall_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:37:41 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*walls_11(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1')
		return ((*sp()).wall12);
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y <= ft_height((*map())) - 1
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y - 1][c.x] == '1')
		return ((*sp()).wall41);
	if (c.x >= 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x + 1] == '1')
		return ((*sp()).wall42);
	if (c.x > 0 && c.y >= 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y][c.x + 1] == '1'
	&& (*map())[c.y + 1][c.x] == '1')
		return ((*sp()).wall43);
	else
		return (NULL);
}

void	*walls_12(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x <= ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y][c.x - 1] == '1')
		return ((*sp()).wall44);
	if (c.x >= 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y <= ft_height((*map())) - 1
	&& (*map())[c.y][c.x + 1] == '1' && (*map())[c.y - 1][c.x] == '1'
	&& (*map())[c.y - 1][c.x + 1] == '1')
		return ((*sp()).wall7);
	if (c.x >= 0 && c.y >= 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y][c.x + 1] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y + 1][c.x + 1] == '1')
		return ((*sp()).wall1);
	if (c.x > 0 && c.y >= 0 && c.x <= ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y + 1][c.x] == '1'
	&& (*map())[c.y + 1][c.x - 1] == '1')
		return ((*sp()).wall3);
	else
		return (NULL);
}

void	*walls_13(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x <= ft_strlen2((*map())[0]) - 2 &&
	c.y <= ft_height((*map())) - 1
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y - 1][c.x] == '1'
	&& (*map())[c.y - 1][c.x - 1] == '1')
		return ((*sp()).wall9);
	if (c.x >= 0 && c.y > 0 && c.x <= ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1 && (c.x == 0 || (*map())[c.y - 1][c.x] == '1')
	&& (c.x == ft_strlen2((*map())[0]) - 2 || (*map())[c.y + 1][c.x] == '1'))
		return ((*sp()).wall10);
	if (c.x > 0 && c.y >= 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y <= ft_height((*map())) - 1 && (c.y == 0 ||
	(*map())[c.y][c.x + 1] == '1')
	&& (c.y == ft_height(*map()) - 1 || (*map())[c.y][c.x - 1] == '1'))
		return ((*sp()).wall11);
	if (c.x >= 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y <= ft_height((*map())) - 1
	&& (*map())[c.y][c.x + 1] == '1' && ((*map())[c.y - 1][c.x] == '1'))
		return ((*sp()).wall16);
	if (c.x >= 0 && c.y >= 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y][c.x + 1] == '1' && (*map())[c.y + 1][c.x] == '1')
		return ((*sp()).wall13);
	else
		return (NULL);
}

void	*walls_14(t_coord c)
{
	if (c.x > 0 && c.y >= 0 && c.x <= ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y + 1][c.x] == '1')
		return ((*sp()).wall14);
	if (c.x > 0 && c.y > 0 && c.x <= ft_strlen2((*map())[0]) - 2 &&
	c.y <= ft_height((*map())) - 1
	&& (*map())[c.y][c.x - 1] == '1' && (*map())[c.y - 1][c.x] == '1')
		return ((*sp()).wall15);
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y + 1][c.x] == '1')
		return ((*sp()).wall29);
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y][c.x - 1] == '1')
		return ((*sp()).wall30);
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y - 1][c.x] == '1')
		return ((*sp()).wall31);
	else
		return (NULL);
}

void	*walls_15(t_coord c)
{
	if (c.x > 0 && c.y > 0 && c.x < ft_strlen2((*map())[0]) - 2 &&
	c.y < ft_height((*map())) - 1
	&& (*map())[c.y][c.x + 1] == '1')
		return ((*sp()).wall32);
	else
		return ((*sp()).wall);
}
