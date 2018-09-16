/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 01:55:57 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/07 01:55:58 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

t_win	*init_window(char *arg)
{
	t_win	*win;

	if ((win = (t_win *)malloc(sizeof(t_win))) == NULL)
		return (NULL);
	
	win->m_p = mlx_init();
	win->w_p = mlx_new_window(win->m_p, W_WIDTH, W_HEIGHT,
										"fdf 42 - gcaixeta");
	win->next = NULL;
	win->prev = NULL;
	win->ax = 20;
	win->ay = 20;
	win->az = 10;
	win->osx = W_WIDTH / 2;
	win->osy = W_HEIGHT / 2;
	win->rotx = 3 * ANG_INCR;
	win->roty = ANG_INCR;
	win->rotz = -ANG_INCR;
	if (acquire_xyz(&win, arg) != 1)
		return (NULL);
	print_commands(win);
	plot_points(win);
	mlx_key_hook(win->w_p, key_hook, win);
	mlx_loop(win->m_p);
	return (win);
}

void	rot_x(t_win *win)
{
	int		i;
	int		j;
	double	y;
	double	z;
	t_point ***mtx;

	mtx = win->xyz_plane;
	i = -1;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
		{
			y = (mtx[i][j])->var_y;
			z = (mtx[i][j])->var_z;
			(mtx[i][j])->var_y = y * cos(win->rotx) - z * sin(win->rotx);
			(mtx[i][j])->var_z = y * sin(win->rotx) + z * cos(win->rotx);
		}
	}
}

void	rot_y(t_win *win)
{
	int		i;
	int		j;
	double	x;
	double	z;
	t_point ***mtx;

	mtx = win->xyz_plane;
	i = -1;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
		{
			x = (mtx[i][j])->var_x;
			z = (mtx[i][j])->var_z;
			(mtx[i][j])->var_x = x * cos(win->roty) + z * sin(win->roty);
			(mtx[i][j])->var_z = z * cos(win->roty) - x * sin(win->roty);
		}
	}
}

void	rot_z(t_win *win)
{
	int		i;
	int		j;
	double	x;
	double	y;
	t_point ***mtx;

	mtx = win->xyz_plane;
	i = -1;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
		{
			x = (mtx[i][j])->var_x;
			y = (mtx[i][j])->var_y;
			(mtx[i][j])->var_x = x * cos(win->rotz) - y * sin(win->rotz);
			(mtx[i][j])->var_y = x * sin(win->rotz) + y * cos(win->rotz);
		}
	}
}

void	update_pts_vars(t_win *win)
{
	int		i;
	int		j;
	t_point ***mtx;

	mtx = win->xyz_plane;
	i = -1;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
		{
			(mtx[i][j])->var_x = (mtx[i][j])->ref_x * win->ax;
			(mtx[i][j])->var_y = (mtx[i][j])->ref_y * win->ay;
			(mtx[i][j])->var_z = (mtx[i][j])->ref_z * win->az;
		}
	}
	rot_x(win);
	rot_y(win);
	rot_z(win);
}

int		main(int ac, char **av)
{
	int		i;
	t_win	*win;
	
	i = 0;
	while (++i < ac)
	{
		if ((win = init_window(av[i])) == NULL)
		{
			printf("argument number %d couldn't be rendered\n", i);
		}
	}
	return (0);
}


















