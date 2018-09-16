/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 04:15:15 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/16 04:15:16 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

/*
** Simple function that extends the reach of the keyboard.
** This one changes the parameters for zooming.
*/

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
}

/*
** Simple function that extends the reach of the keyboard.
** This one changes the parameters for altering and individual axis.
*/

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

/*
** Simple function that extends the reach of the keyboard.
** This one changes the parameters for position in the screen.
*/

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

/*
** Simple function that extends the reach of the keyboard.
** This one changes the parameters for rotation.
*/

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

/*
** Simple function that extends the reach of the keyboard.
** This one changes the parameter for perspective.
*/

void	chng_persp(t_win *win)
{
	if (win->perspective == 1)
		win->perspective = 0;
	else
		win->perspective = 1;
}
