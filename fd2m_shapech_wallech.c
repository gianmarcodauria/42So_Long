/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd2m_shapech_wallech.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:12:05 by gd-auria          #+#    #+#             */
/*   Updated: 2024/05/03 16:06:28 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

char	*fd2str(int fd)
{
	char	*result;
	char	buffer[6];
	char	*temp_free;
	int		rdr;

	rdr = 1;
	result = ft_calloc(sizeof(char), 1);
	if (fd < 0)
		return (NULL);
	else
	{
		while (rdr > 0)
		{
			rdr = read(fd, buffer, 5);
			buffer[rdr] = 0;
			temp_free = result;
			result = ft_strjoin(temp_free, buffer);
			free(temp_free);
			temp_free = NULL;
		}
	}
	if (ft_strlen(result) == 0)
		return (NULL);
	return (result);
}

int	shapeCheck(char **shape, t_first *m)
{
	int Y;

	Y = -1;
	m->Xmax = ft_strlen(shape[0]);
	while (shape[++Y])
	{
		if (ft_strlen(shape[Y]) != (size_t) m->Xmax)
		{
			return (0);
			//exit (0);
		}
	}
	m->Ymax = Y;
	m->matrix = shape;
	return (1);
}

int	wallCheck(t_first *walle)
{
	int height;
	int width;

	height = -1;
	while (walle->matrix[++height])
	{
		//printf ("ARRIVA QUI y - %d  \n", height);
		width = 0;
		while (walle->matrix[height][width])
		{
			if (height == 0 && height == walle->Ymax - 1)
			{
				if (walle->matrix[height][width] != '1')
					return (0);
			}
			if (walle->matrix[height][0] == '1' && walle->matrix[height][walle->Xmax - 1] != '1')
				return (0);
			width++;
		}
	}
	return (1);
}
