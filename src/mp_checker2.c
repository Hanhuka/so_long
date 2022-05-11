/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_checker2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:25:43 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_anomalies(char **mp)
{
	int	x;
	int	y;

	y = 0;
	while (mp[y])
	{	
		x = 0;
		while (mp[y][x])
		{
			if (mp[y][x] != 'C' && mp[y][x] != 'P' && mp[y][x] != 'E'
				&& mp[y][x] != 'X' && mp[y][x] != '0' && mp[y][x] != '1'
				&& mp[y][x] != '\n')
				return (ERROR);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_file(char *name)
{
	int	max;

	max = ft_strlen(name) - 1;
	if (name[max] != 'r' || name[max - 1] != 'e'
		|| name[max - 2] != 'b' || name[max - 3] != '.')
	{
		write(1, "\e[1;91mError\nInvalid file type\n\e[0m", 35);
		exit(1);
	}
}

int	checker(char *map, char ***mp)
{
	int	y;
	int	fd;
	int	i;

	i = 0;
	y = map_y(map);
	if (y < 3)
		errors("\e[1;91mError\nMap is too small\n");
	*mp = malloc((y + 1) * sizeof(char *));
	fd = open(map, O_RDONLY);
	if (!(*mp) || fd == -1)
		errors(strerror(errno));
	(*mp)[i] = get_next_line(fd);
	while ((*mp)[i])
		(*mp)[++i] = get_next_line(fd);
	if (check_len(mp))
		errors("\e[1;91mError\nMap is not rectangular\n\e[0m");
	if (check_walls(mp, y - 1))
		errors("\e[1;91mError\nMap is not closed\n\e[0m");
	if (check_assets(*mp))
		errors("\e[1;91mError\nThere is not enough assets\n\e[0m");
	if (check_anomalies(*mp))
		errors("\e[1;91mError\nThere is an anomaly in your map\n\e[0m");
	return (0);
}

void	errors(char *message)
{
	if (*map())
		free_map(map());
	write(1, message, ft_strlen(message));
	exit(1);
}

size_t	ft_mplen(const char	*str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0' && str[n] != '\n')
		n++;
	return (n);
}
