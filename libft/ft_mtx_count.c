/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:53:26 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/08/03 14:53:28 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_mtx_count(t_mtx_lst *mlst)
{
	int		i;

	i = 0;
	while (mlst)
	{
		i++;
		mlst = mlst->next;
	}
	return (i);
}
