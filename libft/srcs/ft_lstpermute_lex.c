/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpermute_lex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 05:37:32 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/20 02:06:22 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdlib.h>

#include "libft.h"

t_list	*ft_lstpermute_lex(t_list *lst, int len, int sz)
{
	t_drange		*rng;
	t_list			*per;
	t_list			*node;
	int				*arr;
	int				i;

	per = NULL;
	arr = ft_lstsarr(lst);
	rng = ft_newdrng(0, len, ft_dinc);
	ft_lstadd(&node, ft_lstnew((void *)arr[*(rng + i)], sizeof(void *)));
	while (ft_dpermute(rng->start, rng->end))
	{
		node = NULL;
		i = 0;
		while (i < MIN(len, sz))
		{
			ft_lstadd(&node, ft_lstnew((void *)arr[*(rng + i)], sizeof(void *)));
			i++;
		}
		ft_lstadd(&per, ft_lstnode((void *)node, sizeof(t_list *)));
	}
	return (per);
	return (NULL);
}
*/
