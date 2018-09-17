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

/*
** This function is associated with a key. Everytime we press "C" or "V", it
** changes the way the color is rendered.
*/

void	chng_color(t_win *win)
{
	if (win->keycode == 8)
	{
		if (win->color_pal < 7)
			win->color_pal++;
		else
			win->color_pal = 0;
	}
	else
	{
		if (win->color_pal > 0)
			win->color_pal--;
		else
			win->color_pal = 7;
	}
}

/*
** This functino is just there to calculate the incremental bit of color that
** every step should have.
*/

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

/*
** This function determines the color of the pixel based on the z parameter
** and the current color range.
*/

int		set_color(t_win *win, double z)
{
	double		red;
	double		green;
	double		blue;

	if (win->color_pal & 4)
		red = win->color_incr * (z - win->z_min);
	else
		red = 255;
	if (win->color_pal & 2)
		green = win->color_incr * (z - win->z_min);
	else
		green = 255;
	if (win->color_pal & 1)
		blue = win->color_incr * (z - win->z_min);
	else
		blue = 255;
	return (calc_color(red, green, blue));
}
