/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:27:59 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/15 16:28:00 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void	chng_ang_all(t_win *win)
{
	if (win->keycode == 4)
	{
		win->ax = win->ax * 1.05;
		win->ay = win->ay * 1.05;
		win->az = win->az * 1.05;	
	}
	else if (win->keycode == 5)
	{
		win->ax = win->ax * 0.95238;
		win->ay = win->ay * 0.95238;
		win->az = win->az * 0.95238;
	}
	else
		ft_putstr("this feature still has to be implemented");
}

void	chng_axs_par(t_win *win)
{
	if (win->keycode == 12)
		win->ax = win->ax * 1.05;
	else if (win->keycode == 13)
		win->ay = win->ay * 1.05;
	else if (win->keycode == 14)
		win->az = win->az * 1.05;
	else if (win->keycode == 15)
		win->ax = win->ax * 0.95238;
	else if (win->keycode == 17)
		win->ay = win->ay * 0.95238;
	else if (win->keycode == 16)
		win->az = win->az * 0.95238;
}

void	chng_pos_lin(t_win *win)
{
	if (win->keycode == 123)
		win->osx = win->osx - win->ax;
	else if (win->keycode == 126)
		win->osy = win->osy - win->ay;
	else if (win->keycode == 124)
		win->osx = win->osx + win->ax;
	else if (win->keycode == 125)
		win->osy = win->osy + win->ay;
}

void	chng_pos_ang(t_win *win)
{
	if (win->keycode == 86)
		win->rotx = win->rotx + ANG_INCR;
	else if (win->keycode == 87)
		win->roty = win->roty + ANG_INCR;
	else if (win->keycode == 88)
		win->rotz = win->rotz + ANG_INCR;
	else if (win->keycode == 83)
		win->rotx = win->rotx - ANG_INCR;
	else if (win->keycode == 84)
		win->roty = win->roty - ANG_INCR;
	else if (win->keycode == 85)
		win->rotz = win->rotz - ANG_INCR;
}

void	chng_img(t_win *win)
{
	(void)win->ax;
	ft_putstr("this feature still has to be implemented");
}

void	act_on_key(t_win *win)
{
	ft_putnbr(win->keycode);
	ft_putchar(' ');
	if (win->keycode == 53)
		exit (0);
	else if (win->keycode == 49)
		clear_img(win);
	else if (win->keycode >= 0 && win->keycode <= 5)
		chng_ang_all(win);
	else if (win->keycode >= 12 && win->keycode <= 17)
		chng_axs_par(win);
	else if (win->keycode == 45 && win->keycode == 46)
		chng_img(win);
	else if (win->keycode >= 123 && win->keycode <= 126)
		chng_pos_lin(win);
	else if (win->keycode >= 83 && win->keycode <= 88)
		chng_pos_ang(win);
	mlx_clear_window(win->m_p, win->w_p);
	print_commands(win);
	plot_points(win);
}

int		key_hook(int keycode, t_win *win)
{
	win->keycode = keycode;
	act_on_key(win);
	return (keycode);
}
