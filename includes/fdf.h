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

# include "./../minilibx_macos/mlx.h"
# include "./../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define W_WIDTH 2000
# define W_HEIGHT 1250

typedef struct	s_point
{
	int	ref_x;
	int ref_y;
	int	ref_z;
	int var_x;
	int var_y;
	int var_z;
}				t_point;

/*
typedef struct	s_map
{
	t_point	***xy_plane;
}				t_map;
*/

typedef struct	s_win
{
	void		*m_p;
	void		*w_p;
	struct s_w	*next;
	struct s_w	*prev;
	int			lines;
	int			columns;
	int			keycode;
	int			ax;
	int			ay;
	int			az;
	int			osx;
	int			osy;
	t_point		***xyz_plane;
}				t_win;

t_list			*read_map_to_lst(int fd);
char			***chr_mtx_3d(t_list *lst, int lst_count);
t_point			***pts_mtx_3d(char ***chr_mtx, int line_count, int nbr_count);
int				lines_are_uniform(char ***mtx);
void			print_3da_chr(char ***s);
void			print_3da_pts(t_point ***s, int line, int nbr);
void			print_list(t_list *elem);
int				count_nbrs(char ***mtx);
int				count_lst(t_list *lst);
int				acquire_xyz(t_win **win, char *arg);
void			error(void);
t_win			*init_window(char *arg);
void			act_on_key(t_win *win);
int				key_hook(int keycode, t_win *param);
void			print_commands(t_win *win);
void			plot_line(t_win *win, t_point *p0, t_point *p1);
void			plot_points(t_win *win);

#endif