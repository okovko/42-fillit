/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 03:09:17 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/24 06:53:29 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "libft.h"
# include "fillit.h"

typedef struct	s_pieces
{
	t_list		**pieces;
	t_list		**graveyard;
	int			*arr;
	int			ii;
	int			len;
	t_list		*adrs;
	char		*spot;
}				t_pieces;

int				next(int *arr, int pos, int len);
char			*solve(t_list *tetriminos);
t_text			*gen_text(size_t sz);
t_rect			*gen_rect(size_t sz);
t_pieces		*gen_pieces(t_list *tetriminos);
void			solve_setup(t_text **tx, t_rect **rx,
							t_pieces **p, t_list *tetriminos);

#endif
