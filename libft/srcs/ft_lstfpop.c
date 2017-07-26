/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:45:10 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/02 00:12:31 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfpop(t_list **alst)
{
	t_list	*pop;
	
	if (!alst)
		return (NULL);
	pop = *alst;
	pop->next = NULL;
	*alst = (*alst)->next;
	return (pop);
}
