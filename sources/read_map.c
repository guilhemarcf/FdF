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
void		prt_dbl_arr(double *nbrs, int qnbr)
{
	int i;

	i = 0;
	while (i < qnbr)
	{
		printf(" %lf ", nbrs[i]);
		i++;
	}
	printf("\n");
}
*/
/*
int		ft_atoi_arr(char *str, int *i)
{
	int negative;
	int result;

	result = 0;
	negative = 1;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n' ||
		str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
	{
		negative = -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = (result * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (result * negative);
}
*/



/*
int		*get_nbrs(char *s, int qnbr)
{
	int		*i;
	int		j;
	double	*nbrs;

	if ((nbrs = (double *)malloc(sizeof(*nbrs) * (qnbr + 1))) == NULL)
		return (NULL);
	if ((i = (int *)malloc(sizeof(*i))) == NULL)
		return (NULL);
	*i = 0;
	j = 0;
	while (j < qnbr && s[*i] != 0)
	{
		nbrs[j] = ft_atod_arr(s, i);
		(*i)++;
		j++;
	}
	return (nbrs);
}
*/

int			***int_mtx_3d(char ***chr_mtx, int line_count, int nbr_count)
{
	int		i;
	int		j;
	int		***int_mtx;

	i = -1;
	if ((int_mtx = (int ***)malloc(sizeof(*int_mtx) *
								line_count)) == NULL)
		return (NULL);
	while (++i < line_count)
	{
		if ((int_mtx[i] = (int **)malloc(sizeof(**int_mtx) *
										nbr_count)) == NULL)
			return (NULL);
		j = -1;
		while (++j < nbr_count)
		{
			if ((int_mtx[i][j] = (int *)malloc(sizeof(***int_mtx))) == NULL)
				return (NULL);
			*int_mtx[i][j] = ft_atoi(chr_mtx[i][j]);
		}
	}
	return (int_mtx);
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










//t_win		*win;
//if ((win = (t_win *)malloc(sizeof(t_win))) == NULL)
		//return (0);























