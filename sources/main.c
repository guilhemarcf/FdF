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

/*
** This function is used to free the matrix of 3d points after it's used.
** It only exists because one could choose edit the code to have multiple
** readings of maps sequencially. It's not really necessary.
*/

void	free_mtx_pts(t_point ***pts_mtx, double lines, double columns)
{
	int		i;
	int		j;

	i = -1;
	while (++i < lines)
	{
		j = -1;
		while (++j < columns)
			free(pts_mtx[i][j]);
		free(pts_mtx[i]);
	}
	free(pts_mtx);
}

/*
** The update function called by plot_points makes the matrix of points ready
** printing by applying all the necessary parameters for the rendering.
** it first applies the scale to the points, and then the rotations, and if
** necessary, the perspective.
*/

void	update_pts_vars(t_win *win)
{
	int		i;
	int		j;
	t_point ***mtx;

	mtx = win->xyz_plane;
	i = -1;
	while (++i < win->lines)
	{
		j = -1;
		while (++j < win->columns)
		{
			(mtx[i][j])->var_x = (mtx[i][j])->ref_x * win->ax;
			(mtx[i][j])->var_y = (mtx[i][j])->ref_y * win->ay;
			(mtx[i][j])->var_z = (mtx[i][j])->ref_z * win->az;
		}
	}
	rot_x(win);
	rot_y(win);
	rot_z(win);
	get_perspective(win);
	set_color_incr(win);
	if (win->perspective == 1)
		apply_fake_perspective(win);
}

/*
** In this function, the file passed as argument is oppened and the parsing
** starts. It will fist set the struct win (window) to the default values
** and then start parsing the input data to the approppriate struct.
** It calls support functions to inform the user how to interact with the
** program. Also, this function contains the mlx loop.
*/

t_win	*init_window(char *arg)
{
	t_win	*win;

	if ((win = (t_win *)malloc(sizeof(t_win))) == NULL)
		return (NULL);
	win->m_p = mlx_init();
	win->w_p = mlx_new_window(win->m_p, W_W, W_H,
										"fdf 42 - gcaixeta");
	clear_img(win);
	if (acquire_xyz(&win, arg) != 1)
		return (NULL);
	print_commands(win);
	plot_points(win);
	mlx_key_hook(win->w_p, key_hook, win);
	mlx_loop(win->m_p);
	return (win);
}

/*
** The main is there only to call the function that will start the plotting.
** It is very short and could support better argument management.
*/

int		main(int ac, char **av)
{
	t_win	*win;

	if (ac == 2)
		if ((win = init_window(av[1])) == NULL)
			error();
	return (0);
}
