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
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct	s_map
{
	t_point	**xy_plane;
}				t_map;

typedef struct	s_win
{
	void		*m_p;
	void		*w_p;
	struct s_w	*next;
	struct s_w	*prev;
	t_map		*map;
}				t_win;

int				ft_atoi_arr(char *str, int *i);
//void			prt_dbl_arr(double *nbrs, int qnbr);
int				*get_nbrs(char *s, int qnbr);
t_list			*read_map_to_lst(int fd);
char			***chr_mtx_3d(t_list *lst, int lst_count);
int				***int_mtx_3d(char ***chr_mtx, int line_count, int nbr_count);
int				lines_are_uniform(char ***mtx);

#endif