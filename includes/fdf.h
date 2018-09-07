/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 01:47:11 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/07 01:47:38 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./../minilibx_macos/mlx.h"
# include "./../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	turn;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
}				t_win;

#endif