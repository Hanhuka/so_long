/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:39:32 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	***map(void)
{
	static char	**map;

	return (&map);
}

int	map_y(char *name)
{
	char	c[2];
	int		fd;
	int		i;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, c, 1))
	{
		if (c[0] == '\n' || c[0] == '\0')
		{
			i++;
			c[1] = '\n';
		}
		else
			c[1] = '\0';
	}
	if (c[1] == '\0')
		i++;
	close(fd);
	return (i);
}
