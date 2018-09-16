/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:28:55 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/15 15:28:55 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

int		lines_are_uniform(char ***mtx)
{
	int i;
	int j;
	int cmp;

	i = 0;
	while (mtx[i])
	{
		j = 0;
		while (mtx[i][j])
			j++;
		if (i == 0)
			cmp = j;
		else if (cmp != j)
			return (0);
		i++;
	}
	return (1);
}

int		count_nbrs(char ***mtx)
{
	int i;

	i = 0;
	while (mtx[0][i])
		i++;
	return (i);
}

int		count_lst(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
