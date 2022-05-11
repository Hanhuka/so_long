/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_checker3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:34:55 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	find_char(char **mp, char c)
{
	int	y;
	int	x;

	y = -1;
	while (mp[++y])
	{
		x = -1;
		while (mp[y][++x])
		{
			if (mp[y][x] == c)
				return (0);
		}
	}
	return (ERROR);
}

void	free_map(char ***mp)
{
	int	i;

	i = 0;
	if (*mp)
	{
		while ((*mp)[i])
		{
			free((*mp)[i++]);
		}
		free(*mp);
	}
}
