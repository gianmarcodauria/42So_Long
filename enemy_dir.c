/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:41:51 by gd-auria          #+#    #+#             */
/*   Updated: 2024/05/03 12:13:03 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

int enemy_random(t_first *play)
{
	usleep(900000 / 6);
	srand(time(NULL));
	int numero = rand() % 4 ;
  	int pX;
	int pY;

	pX = play->map.enemy.X_ax;
	pY = play->map.enemy.Y_ax;
	if( numero == 0 && play->matrix[pY - 1][pX] != '1')
		but_Nu(play);
	else if (numero == 1 && play->matrix[pY][pX + 1] != '1' )
		but_Nr(play);
	else if (numero == 2 && play->matrix[pY + 1][pX] != '1')
		but_Nd(play);
	else if (numero == 3 && play->matrix[pY][pX - 1] != '1' )
		but_Nl(play);
	return (1);
}

int enemy_toorandom(t_first *play)
{
	usleep(900000 / 6);
	srand(time(NULL));
  	int pX;
	int pY;

	pX = play->map.enemy.X_ax;
	pY = play->map.enemy.Y_ax;
	if(play->matrix[pY - 1][pX] != '1')
		but_Nu(play);
	else if (play->matrix[pY][pX + 1] != '1' )
		but_Nr(play);
	else if (play->matrix[pY + 1][pX] != '1')
		but_Nd(play);
	else if (play->matrix[pY][pX - 1] != '1' )
		but_Nl(play);
	return (1);
}
