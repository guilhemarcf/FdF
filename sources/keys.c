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

/*
** This function is not exactly a print one, but is is called both in the
** beginning of the program and by a key, so here it is. It just sets the
** window's variables to the default, restoring the primitive state of all
** renderings.
*/

void	clear_img(t_win *win)
{
	win->perspective = 0;
	win->ax = 20;
	win->ay = 20;
	win->az = 10;
	win->osx = W_WIDTH / 2;
	win->osy = W_HEIGHT / 2;
	win->rotx = 3 * ANG_INCR;
	win->roty = ANG_INCR;
	win->rotz = -ANG_INCR;
}

/*
** Function that gives action to the keyboard hook functionality of the mlx
** library. It splits the reach of the keyboard to manage each specific task
** in a separate function.
*/

void	act_on_key(t_win *win)
{
	ft_putnbr(win->keycode);
	ft_putchar(' ');
	if (win->keycode == 53)
		exit (0);
	else if (win->keycode == 49)
		clear_img(win);
	else if (win->keycode == 35)
		chng_persp(win);
	else if (win->keycode >= 4 && win->keycode <= 5)
		chng_ang_all(win);
	else if (win->keycode >= 12 && win->keycode <= 17)
		chng_axs_par(win);
	else if (win->keycode >= 123 && win->keycode <= 126)
		chng_pos_lin(win);
	else if (win->keycode >= 83 && win->keycode <= 88)
		chng_pos_ang(win);
	mlx_clear_window(win->m_p, win->w_p);
	print_commands(win);
	plot_points(win);
}

/*
** Functionality of the mlx that allows me to use he keyboard as input for
** interacting with the program. It calls the act_on_key function and
** provides the value corresponding to the key pressed.
*/

int		key_hook(int keycode, t_win *win)
{
	win->keycode = keycode;
	act_on_key(win);
	return (keycode);
}
