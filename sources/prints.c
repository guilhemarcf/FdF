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
** This function plots lines using the DDA algorithm. I compressed all the
** variables I needed into two arrays to make it fit the norm and
** still do it in one function. ctrls[0] = dx, ctrls[1] = dy,
** ctrls[2] = steps, ctrls[3] = i, coords[0] = x_incr, coords[1] = y_incr,
** ctrls[2] = x0, ctrls[3] = x1, ctrls[4] = y0, ctrls[5] = y1.
*/

void	plot_line(t_win *win, t_point *p0, t_point *p1)
{
	int 	ctrls[4];
	double	coords[6];


	coords[2] = (double)p0->var_x;
	coords[3] = (double)p1->var_x;
	coords[4] = (double)p0->var_y;
	coords[5] = (double)p1->var_y;
	ctrls[0] = coords[3] - coords[2];
	ctrls[1] = coords[5] - coords[4];
	if (abs(ctrls[0]) > abs(ctrls[1]))
		ctrls[2] = abs(ctrls[0]);
	else
		ctrls[2] = abs(ctrls[1]);
	coords[0] = (double) ctrls[0] / (double) ctrls[2];
	coords[1] = (double) ctrls[1] / (double) ctrls[2];
	ctrls[3] = -1;
	while (++ctrls[3] < ctrls[2])
	{
		coords[2] = coords[2] + coords[0];
		coords[4] = coords[4] + coords[1];
		mlx_pixel_put(win->m_p, win->w_p, round(coords[2]) + win->osx,
								round(coords[4]) + win->osy, 0xFFFFFF);
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
		{
			if (j + 1 < win->columns)
				plot_line(win, mtx[i][j], mtx[i][j + 1]);
			if (i + 1 < win->lines)
				plot_line(win, mtx[i][j], mtx[i + 1][j]);
		}
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
	ft_putendl("something went wrong with the rendering.");
	exit(0);
}
