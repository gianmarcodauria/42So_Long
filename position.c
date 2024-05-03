/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:30:25 by gd-auria          #+#    #+#             */
/*   Updated: 2024/05/03 12:22:05 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void track_positions(t_first *juego, int he, int wi, char type)// int index)
{
   	if (type == 'P')
   	{
    	juego->map.spawn.name_pos = 'P';
    	juego->map.spawn.X_ax = wi;
    	juego->map.spawn.Y_ax = he;
   	}
   	else if (type == 'N')
   	{
    	juego->map.enemy.name_pos = 'N';
    	juego->map.enemy.X_ax = wi;
    	juego->map.enemy.Y_ax = he;
   	}
}

void actualPosition(t_first *juego)
{
	int he;
   	int wi;

	he = -1;
   	while (++he < juego->Ymax)
	{
		wi = -1;
		while (++wi < juego->Xmax)
		{
			if (juego->matrix[he][wi] == 'P')
            track_positions(juego, he, wi,'P');
         	if (juego->matrix[he][wi] == 'N')
            track_positions(juego, he, wi,'N');
		}
	}
}
