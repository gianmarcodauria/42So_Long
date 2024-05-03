/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:30:25 by gd-auria          #+#    #+#             */
/*   Updated: 2024/05/03 14:34:35 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "struct_slong.h"
# include <mlx.h>
# include <time.h>

int		dot_ber(char *fileber);
char	*fd2str(int fd);
char	**second_matrix(t_first *gameM);
int		letter_check(t_first *letters);
int		shapeCheck(char **shape, t_first *m);
int		wallCheck(t_first *walle);
int		last_floodcheck(char **dupMap);
int		main_check(t_first *check);
void actualPosition(t_first *juego);
int pam_maker(t_first *pam);
void	set_values(t_first *johnny);
void track_positions(t_first *juego, int he, int wi, char type);
//void	print_matrix(t_first *game);
void stamp_err(char *str);
void	free_me(t_first *dm);
int	anti_leak(char *err, int type_err, t_first *dm);
//void    stampmat(char **mtr);
void flood_fill(t_first *floodmap, int height, int width, char **dupMap);
char **filler(t_first *carta, char **doubleM);
int	my_char(t_first *str);
void	run_map(t_first *run);
int enemy_random(t_first *play);
int enemy_toorandom(t_first *map);
int	start_wg(t_first *start);
void	but_u(t_first *but);
void	but_d(t_first *but);
void	but_l(t_first *but);
void	but_r(t_first *but);
int	out_win(t_first *adieu);
void	but_Nr(t_first *but);
void	but_Nl(t_first *but);
void	but_Nu(t_first *but);
void	but_Nd(t_first *but);
int coin_count(t_first *play);

#endif
