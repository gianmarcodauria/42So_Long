/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:18 by gd-auria          #+#    #+#             */
/*   Updated: 2024/04/30 14:19:50 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

void	set_values(t_first *johnny)
{
	johnny->Xmax = 0;
	johnny->Ymax = 0;
	johnny->matrix = NULL;
	johnny->mlx = NULL;
	johnny->win = NULL;
	johnny->img_height = 100;
	johnny->img_width = 100;
	johnny->floodmap = 0;
	johnny->map.P = 0;
	johnny->map.C = 0;
	johnny->map.E = 0;
	johnny->map.N = 0;
	johnny->map.map_path = NULL;
	johnny->map.heigth = 0;
	johnny->map.width = 0;
	johnny->directions_set = 0;
	johnny->map.n_c = 0;
	johnny->map.n_p = 0;
	johnny->map.n_n = 0;
	johnny->map.n_out = 0;
	johnny->map.img_wi = 0;
	johnny->map.img_he = 0;
	johnny->map.spawn.X_ax = 0;
	johnny->map.spawn.Y_ax = 0;
	johnny->map.spawn.name_pos = '0';
}

// void	aux_values(t_game *valg)
// {
// 	valg->mlx = NULL;
// 	valg->win = NULL;
// 	valg->path_P = "../png/Pfront.xpm";

// }
