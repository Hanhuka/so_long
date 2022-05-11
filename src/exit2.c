/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:33:58 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_sprites2(void)
{
	mlx_destroy_image((*window()).mlx, (*sp()).sus_16_left);
	mlx_destroy_image((*window()).mlx, (*sp()).sus_32);
	mlx_destroy_image((*window()).mlx, (*sp()).sus_32_left);
	mlx_destroy_image((*window()).mlx, (*sp()).sus_48);
	mlx_destroy_image((*window()).mlx, (*sp()).sus_48_left);
}

int	window_close(void)
{
	exit_game("\e[1;94mWindow closed\n\e[0m");
	return (0);
}
