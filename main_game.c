/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:18 by gd-auria          #+#    #+#             */
/*   Updated: 2024/05/03 16:41:00 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main_check(t_first *check)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = shapeCheck(check->matrix, check);
	b = wallCheck(check);
	c = letter_check(check);
	d = dot_ber(check->floodmap);
	e = pam_maker(check);
	if (a == 0 || b == 0 || c == 0
		|| d == 0 || e == 0)
	{
		write (1, "MAIN CHECK ERROR\n", 17);
		free_me(check);
		exit (0);
	}
	write(1, "GIUSTO: SUPERA I CONTROLLI\n", 27);
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char	**map;
	t_first	file;
	if (argc == 2)
	{
		set_values(&file);
		fd = open(argv[1], O_RDONLY);
		str = fd2str(fd);
		close(fd);
		if (str == NULL)
			return (0);
		map = ft_split(str, '\n');
		free(str);
		file.floodmap = argv[1];
		file.matrix = map;
		if(main_check(&file) == 0)
		{
			free(file.floodmap);
			exit (0);
		}
	}
		start_wg(&file);
		return(1);
}
