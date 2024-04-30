/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:11:27 by gd-auria          #+#    #+#             */
/*   Updated: 2024/04/30 17:23:39 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

void	printImg(t_first *print, int y, int x)
{
	int	i;

	printf("%c \n",print->matrix[y][x]);
	printf("%p %p %p  \n", print->mlx, print->win, print->map.wall.img);
	if (print->matrix[y][x] == '1')
	{

		i = mlx_put_image_to_window(print->mlx, print->win, print->map.wall.img,  x * 100, y * 100);
		printf ("%i" , i);

	}
	else if (print->matrix[y][x] == 'E')
		mlx_put_image_to_window(print->mlx, print->win, print->map.out.img,  x * 100, y * 100);
	else if (print->matrix[y][x] == 'C')
		mlx_put_image_to_window(print->mlx, print->win, print->map.points.img,  x * 100, y * 100);
	else if (print->matrix[y][x] == 'N')
		mlx_put_image_to_window(print->mlx, print->win, print->map.enemy.img,  x * 100, y * 100);
	else if (print->matrix[y][x] == 'P')
		mlx_put_image_to_window(print->mlx, print->win, print->map.spawn.img,  x * 100, y * 100);
	else
		mlx_put_image_to_window(print->mlx, print->win, print->map.ground.img,  x * 100, y * 100);
}
void	run_map(t_first *run)
{
	int	h;
	int	w;
	char	*directions;

	h = 0;
	while (h < run->Ymax)
	{


		w = 0;
		while (w < run->Xmax)
		{
			printf("ARRIVA QUI %i %i \n", h, w);
			printImg(run, h, w);
			w++;
		}
		++h;
	}
	directions = ft_itoa(run->directions_set);
	mlx_string_put(run->mlx, run->win, 5, 95, 0x000000, "STEPS : ");
	mlx_string_put(run->mlx, run->win, 95, 95, 0x000000, directions);
	free (directions);
}
void	img_val(t_first *img)
{
	img->map.spawn.img = mlx_xpm_file_to_image(img->mlx, "maps/png/CH_FRONT.xpm", &(img->img_width), &(img->img_height));
	img->map.enemy.img = mlx_xpm_file_to_image(img->mlx, "maps/png/N_FRONT.xpm", &(img->img_width), &(img->img_height));
	img->map.points.img = mlx_xpm_file_to_image(img->mlx, "maps/png/CD.xpm", &(img->img_width), &(img->img_height));
	img->map.out.img = mlx_xpm_file_to_image(img->mlx, "maps/png/PC1.xpm", &(img->img_width), &(img->img_height));
	img->map.ground.img = mlx_xpm_file_to_image(img->mlx, "maps/png/FLOOR.xpm", &(img->img_width), &(img->img_height));
	img->map.wall.img = mlx_xpm_file_to_image(img->mlx, "maps/png/MURO.xpm", &(img->img_width), &(img->img_height));
}

int	hook_my_but(int	button, t_first *hooker)
{
	if (button == BUTTON_UP || button == BUTTON_W)
		but_u(hooker);
	else if (button == BUTTON_DOWN || button == BUTTON_S)
		but_d(hooker);
	else if (button == BUTTON_LEFT || button == BUTTON_A)
		but_l(hooker);
	else if (button == BUTTON_RIGHT || button == BUTTON_D)
		but_r(hooker);
	else if (button == BUTTON_ESC)
		out_win(hooker);
	return (1);
}

int start_wg(t_first *start)
{
	start->mlx = mlx_init();
	start->win = mlx_new_window(start->mlx, start->Xmax * 100, start->
	Ymax * 100, "Scary Things");
	img_val(start);
	run_map(start);
	mlx_key_hook(start->win, hook_my_but, start);
	mlx_hook(start->win, 17, 0, out_win, start);
	mlx_loop_hook(start->mlx, enemy_random, start);
	mlx_loop_hook(start->mlx, enemy_toorandom, start);
	mlx_loop(start->mlx);
	//img = mlx_xpm_file_to_image(start->mlx, relative_path, st, &img_height);
	return (1);
}



