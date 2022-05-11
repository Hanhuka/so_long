/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wall_utils4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:50:58 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*wall_cond(t_coord c)
{
	if (walls_1(c))
		return (walls_1(c));
	if (walls_2(c))
		return (walls_2(c));
	if (walls_3(c))
		return (walls_3(c));
	if (walls_4(c))
		return (walls_4(c));
	if (walls_5(c))
		return (walls_5(c));
	if (walls_6(c))
		return (walls_6(c));
	if (walls_7(c))
		return (walls_7(c));
	if (walls_8(c))
		return (walls_8(c));
	if (walls_9(c))
		return (walls_9(c));
	if (walls_10(c))
		return (walls_10(c));
	return (NULL);
}

void	*wall_cond2(t_coord c)
{
	if (wall_cond(c))
		return (wall_cond(c));
	if (walls_11(c))
		return (walls_11(c));
	if (walls_12(c))
		return (walls_12(c));
	if (walls_13(c))
		return (walls_13(c));
	if (walls_14(c))
		return (walls_14(c));
	return (walls_15(c));
}
