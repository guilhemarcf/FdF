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

int		deal_mouse(int button, int x, int y, t_win *param)
{
	ft_putstr("the button pressed was: ");
	ft_putnbr(button);
	ft_putchar('\n');

	ft_putstr("the pixel selected was: ");
	ft_putnbr(x);
	ft_putstr(" posX and ");
	ft_putnbr(y);
	ft_putendl(" posY.");

	mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
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

	mlx_mouse_hook(win_ptr, deal_mouse, win);
	mlx_loop(mlx_ptr);
	return (0);
}
