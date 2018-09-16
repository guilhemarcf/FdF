/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 08:37:49 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/16 08:37:50 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void	set_color_incr(t_win *win)
{
	win->color_incr = (255 / (win->z_max - win->z_min));
}

/*
** This function is there to give color to the lines that connect points that
** are in different z values, giving a better sense of deepeness.
*/

int		calc_color(int red, int green, int blue)
{
	int color;

	color = red << 16 | green << 8 | blue;
	return (color);
}

int		set_color(t_win *win, double z)
{
	double		red;
	double		green;
	double		blue;

	red = 255;
	green = 255;
	blue = win->color_incr * (z - win->z_min);
	return (calc_color(red, green, blue));
}
