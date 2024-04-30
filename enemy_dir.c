/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:41:51 by gd-auria          #+#    #+#             */
/*   Updated: 2024/04/30 17:26:43 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

int enemy_random(t_first *map)
{
	sleep(1);
	srand(time(NULL));
	int numero = rand() % 4 ;
  	int playerX;
	int playerY;

	playerX = map->map.enemy.X_ax;
	playerY = map->map.enemy.Y_ax;
	if( numero == 0 && map->matrix[playerY - 1][playerX] != '1')
		but_Nu(map);
	else if (numero == 1 && map->matrix[playerY][playerX + 1] != '1' )
		but_Nr(map);
	else if (numero == 2 && map->matrix[playerY + 1][playerX] != '1')
		but_Nd(map);
	else if (numero == 3 && map->matrix[playerY][playerX - 1] != '1' )
		but_Nl(map);
	return (1);
}

int enemy_toorandom(t_first *map)
{
	sleep(1);
	srand(time(NULL));
  	int playerX;
	int playerY;

	playerX = map->map.enemy.X_ax;
	playerY = map->map.enemy.Y_ax;
	if(map->matrix[playerY - 1][playerX] != '1')
		but_Nu(map);
	else if (map->matrix[playerY][playerX + 1] != '1' )
		but_Nr(map);
	else if (map->matrix[playerY + 1][playerX] != '1')
		but_Nd(map);
	else if (map->matrix[playerY][playerX - 1] != '1' )
		but_Nl(map);
	return (1);
}
