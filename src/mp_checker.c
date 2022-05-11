/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:25:04 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_len(char ***mp)
{
	size_t	linelen;
	int		i;

	if (!(*mp))
		return (ERROR);
	i = 1;
	linelen = ft_mplen((*mp)[0]);
	while ((*mp)[i] && linelen == ft_mplen((*mp)[i]))
		i++;
	if (!(*mp)[i])
		return (0);
	return (ERROR);
}

int	check_first(char *line)
{
	int	i;
	int	max;

	i = 0;
	max = ft_strlen(line) - 1;
	while (i < max)
	{
		if (line[i++] != '1')
			return (ERROR);
	}
	if (line[max] != '\n' && line[max] != '1')
		return (ERROR);
	return (0);
}

int	check_vertical(char *line)
{
	int	max;

	max = ft_strlen(line) - 1;
	if (line[0] != '1' || line[max - 1] != '1')
		return (ERROR);
	if (line[max] != '\n')
		return (ERROR);
	return (0);
}

int	check_walls(char ***mp, int y)
{
	int	i;

	i = 1;
	if (check_first((*mp)[0]) || check_first((*mp)[y]))
		return (ERROR);
	while (i < y)
	{
		if (check_vertical((*mp)[i++]))
			return (ERROR);
	}
	return (0);
}

int	check_assets(char **mp)
{
	if (find_char(mp, 'P') || find_char(mp, 'E') || find_char(mp, 'C'))
		return (ERROR);
	return (0);
}
