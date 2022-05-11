/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:03:42 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	enemys(t_win *win)
{
	static int	i;

	if (i < 1000)
	{
		i++;
		return (0);
	}
	i = 0;
	move_every_enemy();
	mlx_clear_window((*win).mlx, (*win).mlx_win);
	print_to_window(win);
	return (0);
}

void	print_image(t_objt **tmp)
{
	mlx_put_image_to_window((*window()).mlx, (*window()).mlx_win, (*tmp)->img,
		(*tmp)->x - (*objects((*window()).px_size))->x
		+ (*window()).height / 2, (*tmp)->y - (*objects((*window()).px_size))->y
		+ (*window()).height / 2);
	*tmp = (*tmp)->next;
}

void	print_enemies(t_win *win, t_objt *tmp)
{
	tmp = tmp->next;
	while (tmp && ((tmp->type >= 'a' && tmp->type <= 'z') || tmp->type == 'P'))
	{
		mlx_put_image_to_window((*win).mlx, (*win).mlx_win, tmp->img,
			tmp->x - (*objects((*win).px_size))->x
			+ (*win).height / 2, tmp->y - (*objects((*win).px_size))->y
			+ (*win).height / 2);
		tmp = tmp->next;
	}
}

void	print_to_window(t_win *win)
{
	t_objt	*tmp;
	int		x;
	int		y;

	x = (-(*objects((*win).px_size))->x + (*init_p()).x) / 8 - 50;
	y = (-(*objects((*win).px_size))->y + (*init_p()).y) / 8 - 50;
	if ((*sp()).background)
		mlx_put_image_to_window((*window()).mlx, (*window()).mlx_win,
			(*sp()).background, x, y);
	tmp = (*objects((*win).px_size))->next;
	while (tmp && tmp->type <= 'z' && tmp->type >= 'a')
		tmp = tmp->next;
	while (tmp)
		print_image(&tmp);
	tmp = (*objects((*win).px_size));
	mlx_put_image_to_window((*win).mlx, (*win).mlx_win, tmp->img,
		(*win).width / 2, (*win).height / 2);
	print_enemies(win, tmp);
	printf_side_info(window());
}

int	ft_height(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
