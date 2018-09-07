/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 01:55:57 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/07 01:55:58 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void	plot_line(t_win *win)
{
	int 	dx, dy, steps, i;
	float	xincr, yincr, x1, x2, y1, y2;

	x1 = (float)win->x1;
	x2 = (float)win->x2;
	y1 = (float)win->y1;
	y2 = (float)win->y2;
	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xincr = (float) dx / (float)steps;
	yincr = (float) dy / (float)steps;

	i = -1;
	while (++i < steps)
	{
		x1 = x1 + xincr;
		y1 = y1 + yincr;
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, round(x1), round(y1), 0xFFFFFF);
	}
}

int		deal_mouse(int button, int x, int y, t_win *param)
{
	ft_putnbr(button);
	ft_putchar('\n');
	if (param->turn == '1')
	{
		param->x1 = x;
		param->y1 = y;
		param->turn = '2';
		ft_putendl("click again to complete segment");
	}
	else
	{
		param->x2 = x;
		param->y2 = y;
		param->turn = '1';
		plot_line(param);
		ft_putendl("click to start segment");
	}
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_win	*win;

	win = NULL;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf 42");


	if ((win = (t_win *)malloc(sizeof(t_win))) == NULL)
		return (0);
	win->win_ptr = win_ptr;
	win->mlx_ptr = mlx_ptr;
	win->turn = '1';

	mlx_mouse_hook(win_ptr, deal_mouse, win);
	mlx_loop(mlx_ptr);
	return (0);
}
