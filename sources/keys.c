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

void	act_on_key(t_win *win)
{
	printf("%d ", win->keycode);
	if (win->keycode == 53)
		exit (0);
	//else if (win->keycode == 49)
	//{
	//	mlx_clear_window(win->m_p, win->w_p);
	//	print_commands(win);
	//}
	else if (win->keycode == 2)
		win->a = win->a - 3;
	else if (win->keycode == 0)
		win->a = win->a + 3;
	else if (win->keycode == 123)
		win->osx = win->osx - win->a;
	else if (win->keycode == 126)
		win->osy = win->osy - win->a;
	else if (win->keycode == 124)
		win->osx = win->osx + win->a;
	else if (win->keycode == 125)
		win->osy = win->osy + win->a;
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
