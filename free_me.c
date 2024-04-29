/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:16:33 by gd-auria          #+#    #+#             */
/*   Updated: 2024/04/26 12:36:41 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

void stamp_err(char *str)
{
	printf ("Error: %s\n", str);
}

void	free_me(t_first *dm)
{
	int	y;

	y = -1;
	while (++y < dm->Ymax)
	{
		free (dm->matrix[y]);
	}
	free(dm);
}

int	anti_leak(char *err, int type_err, t_first *dm)
{
	if (type_err == 1)
	{
		stamp_err(err);
		return (0);
	}
	else if (type_err == 2)
	{
		free_me(dm);
		stamp_err(err);
		return (0);
	}
	else if (type_err == 3)
	{
		free_me(dm);
		printf ("%s", err);
		return (0);
		//ft_destroy(dm);
	}
	return (1);
}
// int	ft_close_x(t_game *ptr_game)
// {
// 	quit_and_free("See U <3", 3, ptr_game);
// 	return (0);
// }

// void	ft_destroy(t_game *ptr_game)
// {
// 	if (ptr_game->win)
// 		mlx_destroy_window(ptr_game->mlx, ptr_game->win);
// }
