/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 05:02:42 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 21:11:20 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "solver.h"
#include "libft.h"

t_text		*gen_text(size_t sz)
{
	char			*start;
	char			*end;
	t_text			*tx;
	size_t			i;
	const size_t	bound = ft_ceilsqrt(sz) * 4;

	tx = malloc(sizeof(t_text));
	start = malloc(bound * (bound + 1) + 1);
	CHKALLOC(tx, start);
	i = 0;
	while (i < bound)
	{
		ft_memset(start + i * (bound + 1), '.', bound);
		*(start + (i + 1) * (bound + 1) - 1) = '\n';
		i++;
	}
	end = start + bound * (bound + 1);
	*end = '\0';
	tx->start = start;
	tx->end = end;
	tx->delim = '\n';
	return (tx);
}

t_rect		*gen_rect(size_t sz)
{
	t_rect	*rx;

	NULLIF((rx = malloc(sizeof(t_rect))) == NULL);
	rx->x0 = 0;
	rx->y0 = 0;
	rx->x1 = ft_ceilsqrt(sz) * 2 - 1;
	rx->y1 = ft_ceilsqrt(sz) * 2 - 1;
	return (rx);
}

t_pieces	*gen_pieces(t_list *tetriminos)
{
	t_pieces	*p;

	p = malloc(sizeof(t_pieces));
	CHKALLOC(p);
	p->len = ft_lstlen(tetriminos);
	p->arr = ft_newdarri(p->len);
	p->pieces = (t_list **)ft_lstsarr(tetriminos);
	p->graveyard = malloc(sizeof(t_list *) * p->len);
	p->adrs = NULL;
	p->ii = 0;
	return (p);
}

void		solve_setup(t_text **tx, t_rect **rx, t_pieces **p, t_list *tetriminos)
{
	const size_t	sz = ft_lstlen(tetriminos);

	*tx = gen_text(sz);
	*rx = gen_rect(sz);
	*p = gen_pieces(tetriminos);
	(*p)->spot = (*tx)->start;
}
