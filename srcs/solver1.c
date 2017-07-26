/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:57:50 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/24 03:10:04 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "solver.h"
#include "fillit.h"

static void		free_graveyard(t_list **graveyard, int len)
{
	int		ii;

	ii = 0;
	while (ii < len)
	{
		ft_lstnfree(&graveyard[ii], 0);
		ii++;
	}
	free(graveyard);
}

int				next(int *arr, int pos, int len)
{
	int		ii;
	int		*min;
	
	if (len < 2)
		return (-1);
	min = ft_darrfind(arr + pos + 1, arr[pos] + 1, len);
	if (NULL != min && min < arr + len)
	{
		ft_cpyswap(arr + pos, min, sizeof(int));
		return (pos);
	}
	else
	{
		ii = pos;
		while (ii + 1 < len)
		{
			ft_cpyswap(arr + ii, arr + ii + 1, sizeof(int));
			ii++;
		}
		if (pos > 0)
		{
			min = ft_darrfind(arr + pos, arr[pos - 1] + 1, len);
			ft_cpyswap(arr + pos - 1, min, sizeof(int));
			return (pos - 1);
		}
		return (-1);
	}
}

char			*solve(t_list *tetriminos)
{
	t_text				*tx;
	t_rect				*rx;
	t_pieces			*p;
	int					ii;
	int					next_ii;
	size_t				passes;
	
	solve_setup(&tx, &rx, &p, tetriminos);
	ii = 0;
	passes = 0;
	while (p->ii < p->len)
	{
		printf("passes = %lu\n", passes);
		passes++;
		while (NULL == p->adrs && NULL != p->spot)
		{
			p->adrs = get_adrs(tx, rx, p->spot, p->pieces[p->arr[ii]]);
			if (NULL != p->adrs)
			{
				place_letter(p->adrs, p->arr[ii] + 'A');
				printf("NEWPIECE\n%s\n\n", tx->start);
				p->graveyard[p->ii] = p->adrs;
				p->adrs = NULL;
				p->ii++;
				ii++;
				p->spot = ft_rectchr(tx, rx, p->spot, '.');
				printf("NEWSPOT\n%s\n", p->spot);
			}
			else
			{
				p->spot = ft_next_in_rect(tx, rx, p->spot);
				p->spot = ft_rectchr(tx, rx, p->spot, '.');
				printf("SAMEPIECE\n%s\n\n", tx->start);
				printf("NEWSPOT\n%s\n", p->spot);
			}
			//p->spot = ft_next_in_rect(tx, rx, p->spot);
			//p->spot = ft_rectchr(tx, rx, tx->start, '.');
		}
		if (NULL != p->adrs)
		{
			//printf("%s\n\n", tx->start);
			continue ;
		}
		next_ii = next(p->arr, ii, p->len);
		if (ii > 0 && ii > next_ii)
		{
			p->ii--;
			//p->spot = p->graveyard[p->ii]->content;
			p->spot = tx->start;
			place_letter(p->graveyard[p->ii], '.');
			ft_lstnfree(&(p->graveyard[p->ii]), 0);
			printf("REMOVEDPIECE\n%s\n\n", tx->start);
			printf("NEWSPOT\n%s\n", p->spot);
			//p->graveyard[p->ii] = NULL;
			//printf("%s\n\n", tx->start);
			ii = next_ii;
		}
		else if (next_ii == -1)
		{
			printf("RECTGREW\n");
			p->spot = tx->start;
			rx->x1++;
			rx->y1++;
			ii = 0;
		}
	}
	free_graveyard(p->graveyard, p->len);
	return (text_in_rect(tx, rx));
}
