/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:49:43 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_key	*keys(void)
{
	static t_key	key;

	return (&key);
}

void	zoom(int keycode, t_win *win)
{
	if (keycode == 125 || keycode == 126)
	{
		if (keycode == 125 && (*win).px_size > 16)
			(*win).px_size -= 16;
		if (keycode == 126 && (*win).px_size < 64)
			(*win).px_size += 16;
	}
}

int	key_down(int keycode, t_win *win)
{
	(void) win;
	if (keycode == 53)
		exit_game("\e[1;94mWindow closed\n\e[0m");
	if (keycode == 13)
		keys()->w = 1;
	if (keycode == 0)
		keys()->a = 1;
	if (keycode == 1)
		keys()->s = 1;
	if (keycode == 2)
		keys()->d = 1;
	zoom(keycode, win);
	move_character(keys()->d - keys()->a, keys()->s - keys()->w);
	mlx_clear_window((*win).mlx, (*win).mlx_win);
	print_to_window(win);
	mlx_hook((*win).mlx_win, 2, 1, key_down, win);
	mlx_hook((*win).mlx_win, 3, 1, key_up, win);
	return (0);
}

int	key_up(int keycode, t_win *win)
{
	if (keycode == 13)
		keys()->w = 0;
	if (keycode == 0)
		keys()->a = 0;
	if (keycode == 1)
		keys()->s = 0;
	if (keycode == 2)
		keys()->d = 0;
	move_character(keys()->d - keys()->a, keys()->s - keys()->w);
	mlx_clear_window((*win).mlx, (*win).mlx_win);
	print_to_window(win);
	mlx_hook((*win).mlx_win, 2, 1, key_down, win);
	mlx_hook((*win).mlx_win, 3, 1, key_up, win);
	return (0);
}
