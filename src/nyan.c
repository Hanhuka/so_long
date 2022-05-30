/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nyan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:58:29 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/30 15:04:18 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nyan(t_win *win)
{
	static int	i;

	if ((*window()).opt != 2)
		return (0);
	if (i < 800)
	{
		i++;
		return (0);
	}
	i = 0;
	(*bckgnd()) = (*bckgnd())->next;
	if (!(*bckgnd())->img)
		(*bckgnd()) = (*bckgnd())->next;
	(*sp()).background = (*bckgnd())->img;
	mlx_clear_window((*win).mlx, (*win).mlx_win);
	print_to_window(win);
	return (0);
}

void	print_backgroud(t_win *win)
{
	int	x;
	int	y;

	if ((*window()).opt != 2)
	{
		x = (-(*objects((*win).px_size))->x + (*init_p()).x) / 8 - 50;
		y = (-(*objects((*win).px_size))->y + (*init_p()).y) / 8 - 50;
	}
	else
	{
		x = 0;
		y = 144;
	}
	if ((*sp()).background)
		mlx_put_image_to_window((*window()).mlx, (*window()).mlx_win,
			(*sp()).background, x, y);
}

void	cenas(t_win *win, int ac, char **av)
{
	int	s;

	if (ac == 2)
		((*sp()).background) = mlx_xpm_file_to_image((*win).mlx,
				SPATH"Fundo_2048_1.xpm", &s, &s);
	if (ac == 3)
	{
		if (ft_strlen(av[2]) == 1 && av[2][0] == '0')
			;
		else if (ft_strlen(av[2]) == 1 && av[2][0] == '1')
			((*sp()).background) = mlx_xpm_file_to_image((*win).mlx,
					SPATH"so_long_bckg.xpm", &s, &s);
		else if (ft_strlen(av[2]) == 1 && av[2][0] == '2')
			opt_2(win, s);
		else if (ft_strlen(av[2]) == 1 && av[2][0] == '3')
			opt_3(win, s);
		else
			errors("\e[1;91mError\nWrong arguments\n\e[0m");
	}
}
