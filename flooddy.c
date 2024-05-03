/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooddy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:18 by gd-auria          #+#    #+#             */
/*   Updated: 2024/05/03 12:19:16 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

void flood_fill(t_first *floodmap, int height, int width, char **dupMap)
{
	int Ymax;
	int Xmax;

	Ymax = floodmap->Ymax;
	Xmax = floodmap->Xmax;
	if(dupMap[height][width])
	{
		if (height >= 0 && height < Ymax - 1 && width >= 0 && width < Xmax - 1
		&& (dupMap[height][width] == '0' || dupMap[height][width] == 'C'
		|| dupMap[height][width] == 'E' || dupMap[height][width] == 'P' || dupMap[height][width] == 'N') && dupMap[height][width] != '1')
		//&& dupMap[height][width] != 'N')
		if (dupMap[height][width] == 'E')
		{
			dupMap[height][width] = '1';
			return ;
		}
		dupMap[height][width] = '1';
		if ((dupMap[height + 1][width] != '1'))
			flood_fill(floodmap, height + 1, width, dupMap);
		if ((dupMap[height][width + 1] != '1'))
			flood_fill(floodmap, height, width + 1, dupMap);
		if ((dupMap[height - 1][width] != '1'))
			flood_fill(floodmap, height - 1, width, dupMap);
		if ((dupMap[height][width - 1] != '1'))
			flood_fill(floodmap, height, width -1, dupMap);
		}
}

char **filler(t_first *carta, char **doubleM)
{
	int he;
	int wi;

	he = carta->map.spawn.Y_ax;
	wi =  carta->map.spawn.X_ax;
	flood_fill(carta, he, wi, doubleM);
	return (doubleM);

}

char	**second_matrix(t_first *gameM)
{
	char	 **secMap;
	int	  n;
	int lenmax;

	n = -1;
	lenmax = gameM->Ymax;
	secMap = ft_calloc(sizeof(char **), lenmax + 1);
	while (++n < lenmax)
	{
		secMap[n] = ft_strdup(gameM->matrix[n]);
	}
	return (secMap);
}

int last_floodcheck(char **dupMap)
{
	int Y;
	int X;

	Y = -1;
	 while (dupMap[++Y])
	{
		X = 0;
		while (dupMap[Y][X])
		{
			if (dupMap[Y][X] == 'P' || dupMap[Y][X] == 'C' || dupMap[Y][X] == 'E' || dupMap[Y][X] == 'N')
			{

				printf("siamo qui something went wrong\n");
				return(0);
			}
			X++;
		}
	}
	return (1);
}

// void	 stampmat(char **mtr)
// {
// 	int i;

//	  i = 0;
// 	while (mtr[i])
// 	{
// 		printf("%s \n", mtr[i]);
// 		i++;
// 	}
// 	printf("\n\n");
// }

int pam_maker(t_first *pam)
{
	char **doubleMat;

	doubleMat = second_matrix(pam);
	actualPosition(pam);
	filler(pam, doubleMat);
	//stampmat(doubleMat);
	if(last_floodcheck(doubleMat))
	{
		free(doubleMat);
		return(1);
	}
	exit (0);
}
