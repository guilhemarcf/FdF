/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 08:44:22 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/16 08:44:23 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

/*
** Part of the plot_line function that assigns the variables and do a little
** math so the function can plot the dots.
*/

void	plot_line_assigns(t_point *p0, t_point *p1, double *coords,
															int *ctrls)
{
	coords[0] = (double)p0->var_x;
	coords[1] = (double)p1->var_x;
	coords[2] = (double)p0->var_y;
	coords[3] = (double)p1->var_y;
	coords[4] = (double)p0->var_z;
	coords[5] = (double)p1->var_z;
	ctrls[0] = coords[1] - coords[0];
	ctrls[1] = coords[3] - coords[2];
	ctrls[2] = coords[5] - coords[4];
	if (abs(ctrls[0]) > abs(ctrls[1]))
		ctrls[3] = abs(ctrls[0]);
	else
		ctrls[3] = abs(ctrls[1]);
	coords[6] = (double)ctrls[0] / (double)ctrls[3];
	coords[7] = (double)ctrls[1] / (double)ctrls[3];
	coords[8] = (double)ctrls[2] / (double)ctrls[3];
}

/*
** Part of the plot_line function that actually prints the pixel
*/

void	plot_line_action(double *coords, t_win *win)
{
	coords[0] = coords[0] + coords[6];
	coords[2] = coords[2] + coords[7];
	coords[4] = coords[4] + coords[8];
	mlx_pixel_put(win->m_p, win->w_p, round(coords[0]) + win->osx,
					round(coords[2]) + win->osy, set_color(win, coords[4]));
}

/*
** This line drawin function plots dots according to the DDA method, and
** gives the color of each individual pixel based on the z param and color
** range currently selected. It is terrible to read, since I had to use
** arrays to fit all the variables, and also had to split the funtion
** into auxiliary functions, but, if that helps, here goes a translation:
** coords[0] = x1
** coords[1] = x2
** coords[2] = y1
** coords[3] = y2
** coords[4] = z1
** coords[5] = z2
** coords[6] = x_increment
** coords[7] = y_increment
** coords[8] = z_increment
** ctrls[0] = dx
** ctrls[1] = dy
** ctrls[2] = dz
** ctrls[3] = steps
** ctrls[4] = i
*/

void	plot_line(t_win *win, t_point *p0, t_point *p1)
{
	int		ctrls[5];
	double	coords[9];

	
	plot_line_assigns(p0, p1, coords, ctrls);
	ctrls[4] = -1;
	while (++ctrls[4] < ctrls[3])
		plot_line_action(coords, win);
}
