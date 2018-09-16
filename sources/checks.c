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

/*
** Seventh function called by acquire_xyz, gets the number of numericc values
** in the map. It does it this way because we already made sure the nubmer of
** values is coherent with another function called previously.
*/

int		count_nbrs(char ***mtx)
{
	int i;

	i = 0;
	while (mtx[0][i])
		i++;
	return (i);
}

/*
** Fourth function called by acquire_xyz, this function makes sure that the
** number of values in every line is the same. If they diverge, returns 0,
** other wise, return 1, and the caller function can carry on with it's work.
*/

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

/*
** Second function called by acquire_xyz, it counts how many lines are there
** in the map, so that the program can build the struct that will hold all the
** data in the form of a matrix of points.
*/

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
