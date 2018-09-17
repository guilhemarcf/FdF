/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 01:47:11 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/07 01:47:38 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** There are the libraries I used.
*/

# include "./../minilibx_macos/mlx.h"
# include "./../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

/*
** I avoided too many macros, and I was able to use just these 3.
*/

# define W_WIDTH 1250
# define W_HEIGHT 780
# define ANG_INCR 0.20944

/*
** this is the structure that receives the parsed data from the map. the
** ref_ values are based on the file directly, and the var_ values are
** obtained after applying the win-> parrameters on the ref_ values.
*/

typedef struct	s_point
{
	double		ref_x;
	double		ref_y;
	double		ref_z;
	double		var_x;
	double		var_y;
	double		var_z;
}				t_point;

/*
** That's the data structure that makes possible the rendering. It contains
** all the parameters that can be applied to the map and also conserve
** information for manipulating the rendering. Every window is a win.
*/

typedef struct	s_win
{
	void		*m_p;
	void		*w_p;
	double		lines;
	double		columns;
	double		keycode;
	double		ax;
	double		ay;
	double		az;
	double		osx;
	double		osy;
	double		rotx;
	double		roty;
	double		rotz;
	double		z_max;
	double		z_min;
	double		z_ave;
	double		color_incr;
	int			color_pal;
	int			perspective;
	t_point		***xyz_plane;
}				t_win;

/*
** Functions of the main.c file
*/

int				main(int ac, char **av);
t_win			*init_window(char *arg);
void			update_pts_vars(t_win *win);

/*
** Functions of the keys.c file
*/

int				key_hook(int keycode, t_win *win);
void			act_on_key(t_win *win);
void			clear_img(t_win *win);

/*
** Functions of the ext_keys.c file
*/

void			chng_ang_all(t_win *win);
void			chng_axs_par(t_win *win);
void			chng_pos_lin(t_win *win);
void			chng_pos_ang(t_win *win);
void			chng_persp(t_win *win);

/*
** Functions of the matrix.c file
*/

void			rot_x(t_win *win);
void			rot_y(t_win *win);
void			rot_z(t_win *win);
void			get_perspective(t_win *win);
void			apply_fake_perspective(t_win *win);

/*
** Functions of the read_map.c file
*/

t_list			*read_map_to_lst(int fd);
char			***chr_mtx_3d(t_list *lst, int lst_count);
t_point			***pts_mtx_3d(char ***chr_mtx, int line_count,
													int nbr_count);
int				acquire_xyz(t_win **win, char *arg);

/*
** Functions of the checks.c file
*/

int				count_lst(t_list *lst);
int				count_nbrs(char ***mtx);
int				lines_are_uniform(char ***mtx);

/*
** Functions of the prints.c file
*/

void			error(void);
void			plot_points(t_win *win);
void			print_commands(t_win *win);

/*
** Functions of the colors.c file
*/

void			set_color_incr(t_win *win);
int				set_color(t_win *win, double z);
void			chng_color(t_win *win);

/*
** Functions of the plot_line.c file
*/

void			plot_line(t_win *win, t_point *p0, t_point *p1);
void			plot_line_action(double *coords, int ctrls, t_win *win);
void			plot_line_assigns(t_point *p0, t_point *p1, double *coords,
																int *ctrls);

#endif