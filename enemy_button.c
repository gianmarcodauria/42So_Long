/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:47:20 by gd-auria          #+#    #+#             */
/*   Updated: 2024/04/30 17:31:33 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

void	but_Nu(t_first *but)
{
	int	Px;
	int	Py;

	Px = but->map.enemy.X_ax;
	Py = but->map.enemy.Y_ax;
	if (but->matrix[Py - 1][Px] != '1')
	{
		but->matrix[Py][Px] = '0';
		but->matrix[Py - 1][Px] = 'N';
		but->map.enemy.X_ax = Px;
		but->map.enemy.Y_ax = Py - 1;
		run_map(but);
	}
}

void	but_Nd(t_first *but)
{
	int	Px;
	int	Py;

	Px = but->map.enemy.X_ax;
	Py = but->map.enemy.Y_ax;
	if (but->matrix[Py + 1][Px] != '1')
	{
		but->matrix[Py][Px] = '0';
		but->matrix[Py + 1][Px] = 'N';
		but->map.enemy.X_ax = Px;
		but->map.enemy.Y_ax = Py + 1;
		run_map(but);
	}
}

void	but_Nl(t_first *but)
{
	int	Px;
	int	Py;

	Px = but->map.enemy.X_ax;
	Py = but->map.enemy.Y_ax;
	if (but->matrix[Py][Px - 1] != '1')
	{
		but->matrix[Py][Px] = '0';
		but->matrix[Py][Px - 1] = 'N';
		but->map.enemy.X_ax = Px - 1;
		but->map.enemy.Y_ax = Py;
		run_map(but);
	}
}

void	but_Nr(t_first *but)
{
	int	Px;
	int	Py;

	Px = but->map.enemy.X_ax;
	Py = but->map.enemy.Y_ax;
	if (but->matrix[Py][Px + 1] != '1')
	{
		but->matrix[Py][Px] = '0';
		but->matrix[Py][Px + 1] = 'N';
		but->map.enemy.X_ax = Px + 1;
		but->map.enemy.Y_ax = Py;
		run_map(but);
	}
}
