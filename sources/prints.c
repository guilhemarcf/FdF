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

void	error(void)
{
	printf("this map can't be rendered since the lines aren't consistent\n");
	//exit(0);
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
			ft_putnbr((s[i][j])->ref_z);
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
	mlx_string_put(win->m_p, win->w_p, W_WIDTH / 8, W_HEIGHT / 6, 0xFFFFFF,
					"press \"ESC\" to exit");
}

void	clear_img(t_win *win)
{
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
}

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
