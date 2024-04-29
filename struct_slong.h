#ifndef STRUCT_SLONG_H
#define STRUCT_SLONG_H

#define COLLECTABLES 6
#define XPM_MAX 6

typedef struct s_third
{
	char	name_pos;
	int		X_ax;
	int		Y_ax;
	void	*img;
} t_third;

typedef struct s_second
{
	int		clear;
    int     P;
    int     C;
    int     E;
    int     N;
	char	*map_path;
	int		heigth;
	int		width;
	t_third	spawn;
	t_third wall;
	t_third	out;
	t_third	ground;
	t_third	points;
	t_third enemy;
	t_third	coll[COLLECTABLES];
	int		n_c;
    int     n_p;
    int     n_out;
	int		n_n;
	int		img_wi;
	int		img_he;

} t_second;

typedef struct s_first
{
    char    **matrix;
	void		*mlx;
	void		*win;
    char    *floodmap;
	int		img_height;
	int		img_width;
    int     Xmax;
    int     Ymax;
	t_second	map;

} t_first;

// typedef struct s_game
// {
// 	//void		*mlx;
// 	//void		*win;
// 	char		*path_P;
// 	int			img_w;
// 	int			img_h;
// } t_game;

# endif
