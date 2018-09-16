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
void	plot_line_assigns(t_point *p0, t_point *p1, double *coords,
															int *ctrls)
{
	x1 = (double)win->x1;
	x2 = (double)win->x2;
	y1 = (double)win->y1;
	y2 = (double)win->y2;
	z1 = (double)win->z1;
	z2 = (double)win->z2;
	dx = x2 - x1;
	dy = y2 - y1;
	dz = z2 - z1;
	xincr = (double)dx / (double)steps;
	yincr = (double)dy / (double)steps;
	zincr = (double)dz / (double)steps;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
}

void	plot_line_action(double *coords, int ctrls, t_win *win)
{
	x1 = x1 + xincr;
	y1 = y1 + yincr;
	mlx_pixel_put(win->mlx_ptr, win->win_ptr, round(x1), round(y1), MISTERIO);
}
*/
void	plot_line(t_win *win, t_point *p0, t_point *p1)
{
	int 	dx, dy, dz, steps, i;
	double	xincr, yincr, zincr, x1, x2, y1, y2, z1, z2;

	x1 = (double)p0->var_x;
	x2 = (double)p1->var_x;
	y1 = (double)p0->var_y;
	y2 = (double)p1->var_y;
	z1 = (double)p0->var_z;
	z2 = (double)p1->var_z;
	dx = x2 - x1;
	dy = y2 - y1;
	dz = z2 - z1;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xincr = (double)dx / (double)steps;
	yincr = (double)dy / (double)steps;
	zincr = (double)dz / (double)steps;
	//plot_line_assigns(p0, p1, coords, ctrls);
	i = -1;
	while (++i < steps)
	{
		x1 = x1 + xincr;
		y1 = y1 + yincr;
		z1 = z1 + zincr;
		mlx_pixel_put(win->m_p, win->w_p, round(x1) + win->osx,
					round(y1) + win->osy, set_color(win, z1));
		//plot_line_action(coords, ctrls, win);
	}
}
