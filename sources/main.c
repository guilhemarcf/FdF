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
** I don't need this function before I actually want to print anything
*/


t_win	*init_window(char *arg)
{
	t_win	*win;

	if ((win = (t_win *)malloc(sizeof(t_win))) == NULL)
		return (NULL);
	
	win->m_p = mlx_init();
	win->w_p = mlx_new_window(win->m_p, W_WIDTH, W_HEIGHT,
										"fdf 42 - gcaixeta");
	if (acquire_xyz(&win, arg) != 1)
		return (NULL);
	win->next = NULL;
	win->prev = NULL;
	win->a = 50;
	win->osx = 250;
	win->osy = 450;
	print_commands(win);
	plot_points(win);
	mlx_key_hook(win->w_p, key_hook, win);
	mlx_loop(win->m_p);
	return (win);
}

/*
** Main sets up the environment needed to make sure there's a goot plot
*/

void	error(void)
{
	printf("this map can't be rendered since the lines aren't consistent\n");
	//exit(0);
}

int		acquire_xyz(t_win **win, char *arg)
{
	t_list	*lst_store;
	char	***chr_mtx;
	int		fd;

	if ((fd = open(arg, O_RDONLY)) > 0 &&
			(lst_store = read_map_to_lst(fd)) != NULL)
	{
		(*win)->lines = count_lst(lst_store);
		chr_mtx = chr_mtx_3d(lst_store, (*win)->lines);
		if (lines_are_uniform(chr_mtx) != 1)
		{
			error();
			return (0);
		}
		(*win)->columns = count_nbrs(chr_mtx);
		(*win)->xyz_plane = pts_mtx_3d(chr_mtx, (*win)->lines,
													(*win)->columns);
		return (1);
	}
	else
		return (0);
}

int		main(int ac, char **av)
{
	int		i;
	t_win	*win;
	
	i = 0;
	while (++i < ac)
	{
		if ((win = init_window(av[i])) == NULL)
		{
			printf("argument number %d couldn't be rendered\n", i);
		}
	}
	return (0);
}


















