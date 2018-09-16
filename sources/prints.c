/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:28:44 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/15 15:28:45 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

/*
** This function is there to make sure the line printing algorithm and the
** color setter work together to give the ilusion of deepness. This function
** call makes sure the first point has an equal or lower var_z than the second.
*/

void	plot_growing_point(t_win *win, t_point ***mtx, int i, int j)
{
	if (j + 1 < win->columns)
	{
		if ((mtx[i][j])->var_z < (mtx[i][j + 1])->var_z)
			plot_line(win, mtx[i][j], mtx[i][j + 1]);
		else
			plot_line(win, mtx[i][j + 1], mtx[i][j]);
	}
	if (i + 1 < win->lines)
	{
		if ((mtx[i][j])->var_z < (mtx[i + 1][j])->var_z)
			plot_line(win, mtx[i][j], mtx[i + 1][j]);
		else
			plot_line(win, mtx[i + 1][j], mtx[i][j]);
	}
}

/*
** This function is called whenever the window needs to be refreshed. It
** updates the values of the map according to the projections and other
** parameters, as well as rotations. Once the struct window is updated,
** it starts drawing lines between the points. It iterates the map drawing
** the lines in a simple patter, from the upper left point to it's
** neighboors to the right and down.
*/

void	plot_points(t_win *win)
{
	int		i;
	int		j;
	t_point	***mtx;

	update_pts_vars(win);
	mtx = win->xyz_plane;
	i = -1;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
			plot_growing_point(win, mtx, i, j);
	}
}

/*
** Simple function that shows the user how to interact with the program.
*/

void	print_commands(t_win *win)
{
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 15, W_HEIGHT / 15, 0xFFFFFF,
					"\"ESC\" to exit");
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 15, W_HEIGHT / 15 + 20, 0xFFFFFF,
					"\"P\" to change projection");
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 15, W_HEIGHT / 15 + 40, 0xFFFFFF,
					"\"Q\" and \"R\" to change x axis");
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 15, W_HEIGHT / 15 + 60, 0xFFFFFF,
					"\"W\" and \"T\" to change y axis");
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 15, W_HEIGHT / 15 + 80, 0xFFFFFF,
					"\"E\" and \"Y\" to change z axis");
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 15, W_HEIGHT / 15 + 100, 0xFFFFFF,
					"\"G\" and \"H\" to change zoom");
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 15, W_HEIGHT / 15 + 120, 0xFFFFFF,
					"\"SPACE\" to change reset");
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 15, W_HEIGHT / 15 + 140, 0xFFFFFF,
					"\"4\" and \"1\" (NUMPAD) to rotate on x");
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 15, W_HEIGHT / 15 + 160, 0xFFFFFF,
					"\"5\" and \"2\" (NUMPAD) to rotate on y");
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 15, W_HEIGHT / 15 + 180, 0xFFFFFF,
					"\"6\" and \"3\" (NUMPAD) to rotate on z");
}

/*
** The sixth function called by acquire_xyz, signals error if the number
** of values per line is not coherent. This type of error is the only one
** I could think of that could make the program crash. Any other type
** could make it work in an undesired way, but that would still be acceptable.
*/

void	error(void)
{
	ft_putendl("something was wrong with the input.");
	exit(0);
}
