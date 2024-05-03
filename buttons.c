/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:55:54 by gd-auria          #+#    #+#             */
/*   Updated: 2024/05/03 14:50:36 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

void	but_u(t_first *but)
{
	int	Px;
	int	Py;

	Px = but->map.spawn.X_ax;
	Py = but->map.spawn.Y_ax;
	if (but->matrix[Py - 1][Px] != '1')
	{
		if (but->matrix[Py - 1][Px] == 'N')
		{
			exit(1);
			free (but);
		}
		if (but->matrix[Py - 1][Px] == 'E' && (coin_count(but) == 1) )
				exit (1);
		if (but->matrix[Py - 1][Px] == 'E' && coin_count(but) == 0)
			return;
		but->matrix[Py][Px] = '0';
		but->matrix[Py - 1][Px] = 'P';
		but->map.spawn.X_ax = Px;
		but->map.spawn.Y_ax = Py - 1;
		but->directions_set++;
		run_map(but);
	}
}

void	but_d(t_first *but)
{
	int	Px;
	int	Py;

	Px = but->map.spawn.X_ax;
	Py = but->map.spawn.Y_ax;
	if (but->matrix[Py + 1][Px] != '1')
	{
		if (but->matrix[Py + 1][Px] == 'N')
		{
			exit(1);
			free (but);
		}
		if (but->matrix[Py + 1][Px] == 'E' && (coin_count(but) == 1) )
				exit (1);
		if (but->matrix[Py + 1][Px] == 'E' && coin_count(but) == 0)
			return;
		but->matrix[Py][Px] = '0';
		but->matrix[Py + 1][Px] = 'P';
		but->map.spawn.X_ax = Px;
		but->map.spawn.Y_ax = Py + 1;
		but->directions_set++;
		run_map(but);
	}
}

void	but_l(t_first *but)
{
	int	Px;
	int	Py;

	Px = but->map.spawn.X_ax;
	Py = but->map.spawn.Y_ax;
	if (but->matrix[Py][Px - 1] != '1')
	{
		if (but->matrix[Py][Px - 1] == 'N')
		{
			exit(1);
			free (but);
		}
		if (but->matrix[Py][Px - 1] == 'E' && (coin_count(but) == 1) )
				exit (1);
		if (but->matrix[Py][Px - 1] == 'E' && coin_count(but) == 0)
			return;
		but->matrix[Py][Px] = '0';
		but->matrix[Py][Px - 1] = 'P';
		but->map.spawn.X_ax = Px - 1;
		but->map.spawn.Y_ax = Py;
		but->directions_set++;
		run_map(but);
	}
}

void	but_r(t_first *but)
{
	int	Px;
	int	Py;

	Px = but->map.spawn.X_ax;
	Py = but->map.spawn.Y_ax;
	if (but->matrix[Py][Px + 1] != '1' )
	{
		if (but->matrix[Py][Px + 1] == 'N')
		{
			exit(1);
			free (but);
		}
		if (but->matrix[Py][Px + 1] == 'E' && (coin_count(but) == 1) )
				exit (1);
		if (but->matrix[Py][Px + 1] == 'E' && coin_count(but) == 0)
			return;
		but->matrix[Py][Px] = '0';
		but->matrix[Py][Px + 1] = 'P';
		but->map.spawn.X_ax = Px + 1;
		but->map.spawn.Y_ax = Py;
		but->directions_set++;
		run_map(but);
	}
}

int	out_win(t_first *adieu)
{
	mlx_destroy_window(adieu->mlx, adieu->win);
	exit (1);
	return (1);
}


