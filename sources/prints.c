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

void	print_3da_chr(char ***s)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			ft_putstr(s[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_3da_pts(t_point ***s, int line, int nbr)
{
	int i;
	int j;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < nbr)
		{
			ft_putnbr((s[i][j])->z);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_list(t_list *elem)
{
	char *s;

	s = elem->content;
	ft_putendl(s);
}

void	print_commands(t_win *win)
{
	mlx_string_put(win->m_p, win->w_p, 150, 140, 0xFFFFFF,
					"press \"ESC\" to exit");
	mlx_string_put(win->m_p, win->w_p, 150, 160, 0xFFFFFF,
					"press \"SPACE\" to clear");
	mlx_string_put(win->m_p, win->w_p, 150, 180, 0xFFFFFF,
					"press \"E\" to plot lines");
	mlx_string_put(win->m_p, win->w_p, 150, 280, 0xFFFFFF,
					"param \'a\' = %d");
}

/*
** This function plots lines using the DDA algorithm. I compressed all the
** variables I needed into two arrays to make it fit the norm and
** still do it in one function. ctrls[0] = dx, ctrls[1] = dy,
** ctrls[2] = steps, ctrls[3] = i, coords[0] = x_incr, coords[1] = y_incr,
** ctrls[2] = x0, ctrls[3] = x1, ctrls[4] = y0, ctrls[5] = y1.
*/

void	plot_points(t_win *win)
{
	int		i;
	int		j;
	t_point	***mtx;

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

//---------------------------------------------------ADAPT THIS//
void	plot_line(t_win *win, t_point *p0, t_point *p1)
{
	int 	ctrls[4];
	float	coords[6];


	coords[2] = (float)p0->x;
	coords[3] = (float)p1->x;
	coords[4] = (float)p0->y;
	coords[5] = (float)p1->y;
	ctrls[0] = coords[3] - coords[2];
	ctrls[1] = coords[5] - coords[4];
	if (abs(ctrls[0]) > abs(ctrls[1]))
		ctrls[2] = abs(ctrls[0]);
	else
		ctrls[2] = abs(ctrls[1]);
	coords[0] = (float) ctrls[0] / (float) ctrls[2];
	coords[1] = (float) ctrls[1] / (float) ctrls[2];
	ctrls[3] = -1;
	while (++ctrls[3] < ctrls[2])
	{
		coords[2] = coords[2] + coords[0];
		coords[4] = coords[4] + coords[1];
		mlx_pixel_put(win->m_p, win->w_p,
						round(coords[2]),round(coords[4]), 0xFFFFFF);
	}
}
//----------------------------------------------------SIHT TPADA