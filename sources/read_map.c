/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:31:52 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/07 08:31:55 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

/*
** Eight function called by acquire_xyz, actually sets the struct of the points
** with the values that it should have. It allocates all the necessary space
** in memory, and assigns it in a way that helps keeping the geometry
** centralized in the window. It currently uses atoi to parse the values, but
** could use other functions to get values of types other than integer.
*/

t_point		***pts_mtx_3d(char ***chr_mtx, int line_count,
													int nbr_count)
{
	int		i;
	int		j;
	t_point	***pts_mtx;

	i = -1;
	if ((pts_mtx = (t_point ***)malloc(sizeof(*pts_mtx) *
								line_count)) == NULL)
		return (NULL);
	while (++i < line_count)
	{
		if ((pts_mtx[i] = (t_point **)malloc(sizeof(**pts_mtx) *
										nbr_count)) == NULL)
			return (NULL);
		j = -1;
		while (++j < nbr_count)
		{
			if ((pts_mtx[i][j] = (t_point *)malloc(sizeof(***pts_mtx))) == NULL)
				return (NULL);
			(pts_mtx[i][j])->ref_z = ft_atoi(chr_mtx[i][j]);
			(pts_mtx[i][j])->ref_y = i - line_count / 2;
			(pts_mtx[i][j])->ref_x = j - nbr_count / 2;
		}
	}
	return (pts_mtx);
}

/*
** Third function called by acquire_xyz, it splits the lines acquired into
** matrix elements of text, since there could be many ways of parsing the
** text into numeric values.
*/

char		***chr_mtx_3d(t_list *lst, int lst_count)
{
	char	***mtx;
	int		i;

	if ((mtx = (char ***)malloc((sizeof(*mtx) * (lst_count + 1)))) == NULL)
		return (NULL);
	i = 0;
	while (i < lst_count)
	{
		mtx[i] = ft_strsplit(lst->content, ' ');
		i++;
		lst = lst->next;
	}
	mtx[i] = NULL;
	return (mtx);
}

/*
** First function called by acquire_xyz, it reads the lines of the map file
** and stores them in a linked list, since we can't know how many lines the
** file has beforehand. It builds the list stacking nodes and them reverts
** it. I do it this way in the hope of saving some time not having to run
** the whole list everytime I need to add a new node.
*/

t_list		*read_map_to_lst(int fd)
{
	char		*nbr_line;
	t_list		*lst_store;
	int			qlines;

	qlines = 0;
	lst_store = NULL;
	while (get_next_line(fd, &nbr_line) > 0)
	{
		ft_lstadd(&lst_store, ft_lstnew2(nbr_line));
		qlines++;
		ft_strdel(&nbr_line);
	}
	lst_store = ft_lstrev(&lst_store);
	return (lst_store);
}

/*
** This is the first function called to parse the data to the program.
** It starts opening the map file, then call the function that reads it
** into a list of strings (containing the lines). Then, it splits the
** lines into strings containing the values of z on the map, but in
** text format. Then it checks if the map is a rectangle. If not, it
** displays error and exits. If yes, continues, to parse the info into
** useful data, transforming the number strings into actual numeric
** values. Along the way, it sets the atributes of the window accordingly
** to ensure the program can do a lot using just the window struct.
*/

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
			error();
		(*win)->columns = count_nbrs(chr_mtx);
		(*win)->xyz_plane = pts_mtx_3d(chr_mtx, (*win)->lines,
													(*win)->columns);
		return (1);
	}
	else
		return (0);
}












