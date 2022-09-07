/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:49:43 by ralves-g          #+#    #+#             */
/*   Updated: 2022/09/07 16:53:20 by ralves-g         ###   ########.fr       */
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
	if (keycode == UP || keycode == DOWN)
	{
		if (keycode == UP && (*win).px_size > 16)
			(*win).px_size -= 16;
		if (keycode == DOWN && (*win).px_size < 64)
			(*win).px_size += 16;
	}
}

int	key_down(int keycode, t_win *win)
{
	(void) win;
	keys()->w = 0;
	keys()->a = 0;
	keys()->s = 0;
	keys()->d = 0;
	if (keycode == ESC)
		exit_game("\e[1;94mWindow closed\n\e[0m");
	if (keycode == KEY_W)
		keys()->w = 1;
	if (keycode == KEY_A)
		keys()->a = 1;
	if (keycode == KEY_S)
		keys()->s = 1;
	if (keycode == KEY_D)
		keys()->d = 1;
	zoom(keycode, win);
	change_bckgnd(keycode);
	move_character(keys()->d - keys()->a, keys()->s - keys()->w);
	mlx_clear_window((*win).mlx, (*win).mlx_win);
	print_to_window(win);
	return (0);
}

int	key_up(int keycode, t_win *win)
{
	printf("key up\n");
	if (keycode == KEY_W)
		keys()->w = 0;
	if (keycode == KEY_A)
		keys()->a = 0;
	if (keycode == KEY_S)
		keys()->s = 0;
	if (keycode == KEY_D)
		keys()->d = 0;
	move_character(keys()->d - keys()->a, keys()->s - keys()->w);
	mlx_clear_window((*win).mlx, (*win).mlx_win);
	print_to_window(win);
	return (0);
}
