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

/*
int		init_window(t_win *win)
{
	void	*m_ptr;
	void	*w_ptr;

	win = NULL;
	m_ptr = mlx_init();
	w_ptr = mlx_new_window(m_ptr, W_WIDTH, W_HEIGHT, "fdf 42 - gcaixeta");
	
	win->w_ptr = w_ptr;
	win->m_ptr = m_ptr;
	return (0);
}
*/


/*
** Main sets up the environment needed to make sure there's a goot plot
*/

void	print_3da_chr(char ***s)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			ft_putstr(s[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_3da_int(int ***s, int line, int nbr)
{
	int i;
	int j;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < nbr)
		{
			ft_putnbr(*s[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

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
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	print_list(t_list *elem)
{
	char *s;

	s = elem->content;
	ft_putendl(s);
}

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	t_list	*lst_store;
	char	***chr_mtx;
	int		line_count;
	int		***int_mtx;
	int		nbr_count;

	i = 0;
	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) > 0 &&
				(lst_store = read_map_to_lst(fd)) != NULL)
		{
			line_count = count_lst(lst_store);
			ft_lstiter(lst_store, &print_list);
			printf("there are %d lines\n", line_count);
			ft_putendl("and that's all!!!!!!");
			chr_mtx = chr_mtx_3d(lst_store, line_count);
			print_3da_chr(chr_mtx);
			if (lines_are_uniform(chr_mtx))
				printf("the lines are uniform\n");
			else
			{
				printf("can't be rendered\n");
				return (0);
			}
			nbr_count = count_nbrs(chr_mtx);
			int_mtx = int_mtx_3d(chr_mtx, line_count, nbr_count);
			print_3da_int(int_mtx, line_count, nbr_count);
		}
		else
		{
			ft_putendl("yep, didn't work");
		}
	}
	return (0);
}


















