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
			(pts_mtx[i][j])->ref_y = i;
			(pts_mtx[i][j])->ref_x = j;
		}
	}
	return (pts_mtx);
}

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













