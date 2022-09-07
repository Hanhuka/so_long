/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparations3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:19:10 by ralves-g          #+#    #+#             */
/*   Updated: 2022/09/07 16:09:45 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_anim	**bckgnd(void)
{
	static t_anim	*useless_shit;

	return (&useless_shit);
}

void	opt_2(t_win *win, int s)
{
	(*window()).opt = 1;
	((*sp()).background_1) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Fundo_2048_1.xpm", &s, &s);
	((*sp()).background_2) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"so_long_bckg.xpm", &s, &s);
	((*sp()).background_3) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan1.xpm", &s, &s);
	stackadd_back(bckgnd(), new_module((*sp()).background_1));
	stackadd_back(bckgnd(), new_module((*sp()).background_2));
	stackadd_back(bckgnd(), new_module((*sp()).background_3));
	stackadd_back(bckgnd(), new_module(NULL));
	(*sp()).background = (*bckgnd())->img;
}

void	init_opt3(t_win *win, int s)
{
	((*sp()).background_1) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan1.xpm", &s, &s);
	((*sp()).background_2) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan2.pm", &s, &s);
	((*sp()).background_3) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan3.xpm", &s, &s);
	((*sp()).background_4) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan4.xpm", &s, &s);
	((*sp()).background_5) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan5.xpm", &s, &s);
	((*sp()).background_6) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan6.xpm", &s, &s);
	((*sp()).background_7) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan7.xpm", &s, &s);
	((*sp()).background_8) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan8.xpm", &s, &s);
	((*sp()).background_9) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan9.xpm", &s, &s);
	((*sp()).background_10) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan10.xpm", &s, &s);
	((*sp()).background_11) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan11.xpm", &s, &s);
	((*sp()).background_12) = mlx_xpm_file_to_image((*win).mlx,
			SPATH"Nyan12.xpm", &s, &s);
}

void	opt_3(t_win *win, int s)
{
	(*window()).opt = 2;
	init_opt3(win, s);
	stackadd_back(bckgnd(), new_module((*sp()).background_1));
	stackadd_back(bckgnd(), new_module((*sp()).background_2));
	stackadd_back(bckgnd(), new_module((*sp()).background_3));
	stackadd_back(bckgnd(), new_module((*sp()).background_4));
	stackadd_back(bckgnd(), new_module((*sp()).background_5));
	stackadd_back(bckgnd(), new_module((*sp()).background_6));
	stackadd_back(bckgnd(), new_module((*sp()).background_7));
	stackadd_back(bckgnd(), new_module((*sp()).background_8));
	stackadd_back(bckgnd(), new_module((*sp()).background_9));
	stackadd_back(bckgnd(), new_module((*sp()).background_10));
	stackadd_back(bckgnd(), new_module((*sp()).background_11));
	stackadd_back(bckgnd(), new_module((*sp()).background_12));
	(*sp()).background = (*bckgnd())->img;
	(*window()).size = 16;
	(*window()).width = (*window()).px_size * (*window()).size;
	(*window()).height = (*window()).px_size * (*window()).size;
	mlx_destroy_window((*window()).mlx, (*window()).mlx_win);
	(*window()).mlx_win = mlx_new_window((*window()).mlx, (*window()).width
			+ (5 * 64), (*window()).height, "Honey Catcher");
}

void	change_bckgnd(int keycode)
{
	if ((keycode == LEFT || keycode == RIGHT) && (*window()).opt == 1)
	{
		(*bckgnd()) = (*bckgnd())->next;
		(*sp()).background = (*bckgnd())->img;
	}
}
