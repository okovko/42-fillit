/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 04:48:28 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 21:45:49 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tetriminos.h"
#include "libft.h"

t_list		*map_tetriminos(t_list *tetriminos)
{
	t_list	*pt_pass;
	t_list	*relative_pass;

	pt_pass = ft_lstmap(tetriminos, tetrimino_str_to_points);
	relative_pass = ft_lstmap(pt_pass, tetrimino_relative_points);
	return (relative_pass);
}

t_list		*tetrimino_str_to_points(t_list *elem)
{
	char	*str;
	char	*f;
	t_point	*origin;
	t_point	*pt;
	t_list	*points;

	NULLCHECK(elem);
	str = elem->content;
	f = ft_strchr(str, '#');
	origin = ft_ptnew((f - str) % 5, (f - str) / 5);
	points = NULL;
	ft_lstadd(&points, ft_lstnode((void *)ft_ptnew(0, 0), sizeof(t_point)));
	while ((f = ft_strchr(f + 1, '#')))
	{
		pt = ft_ptnew((f - str) % 5, (f - str) / 5);
		ft_ptless(pt, origin);
		ft_lstadd(&points, ft_lstnode((void *)pt, sizeof(t_point)));
	}
	free(origin);
	ft_lstsrev(&points);
	return (ft_lstnew((void *)points, sizeof(t_list)));
}

t_list		*tetrimino_relative_points(t_list *elem)
{
	t_list	*map;
	t_list	*points;
	t_point	*pt_last;
	t_point	*pt_curr;
	t_point	*pt;
	
	NULLCHECK(elem);
	map = NULL;
	ft_lstadd(&map, ft_lstnode((void *)ft_ptnew(0, 0), sizeof(t_point)));
	points = (t_list *)elem->content;
	pt_last = NULL;
	pt_curr = (t_point *)points->content;
	while (points->next)
	{
		points = points->next;
		pt_last = pt_curr;
		pt_curr = (t_point *)points->content;
		pt = ft_ptsub(pt_curr, pt_last);
		ft_lstadd(&map, ft_lstnode((void *)pt, sizeof(t_point)));
	}
	ft_lstsrev(&map);
	return (ft_lstnew((void *)map, sizeof(t_list)));
}
