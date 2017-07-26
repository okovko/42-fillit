/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 21:09:41 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 17:50:52 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "tetread.h"
#include "validate.h"
#include "solver.h"
#include "tetriminos.h"

void	print_tetriminos(t_list	*tetriminos)
{
	while (tetriminos)
	{
		ft_putendl(tetriminos->content);
		tetriminos = tetriminos->next;
	}
}

void	print_map(t_list *map)
{
	t_list	*points;
	t_point	*pt;
	int		x;
	int		y;

	while (map)
	{
		points = (t_list *)map->content;
		ft_putstr("new node\n");
		while (points)
		{
			pt = (t_point *)points->content;
			x = pt->x;
			y = pt->y;
			ft_putstr("(");
			ft_putnbr(x);
			ft_putstr(", ");
			ft_putnbr(y);
			ft_putstr(")\n");
			points = points->next;
		}
		map = map->next;
	}
}

int		main(int argc, char **argv)
{
	/*
	// testing next
	int	*arri;
	int	ii;
	int jj;
	
	ii = 0;
	arri = ft_newdarri(5);
	while (ii > -1)
	{
		ii = next(arri, ii, 5);
		jj = 0;
		while (jj < 5)
		{
			printf("%d\n", arri[jj]);
			jj++;
		}
		printf("\n");
	}
	*/
	t_list	*tetriminos;
	t_list	*map;
	char	*solution;
	
	tetriminos = read_file(argc, argv);
	RETIF(0, NULL == tetriminos);
	ft_putstr("read and validated file successfully\n");
	print_tetriminos(tetriminos);
	map = map_tetriminos(tetriminos);
	print_map(map);
	solution = solve(map);
	ft_putstr(solution);
	free(solution);
	ft_lstnfree(&map, 2);
	ft_lstnfree(&tetriminos, 1);

	return (0);
}
