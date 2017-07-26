/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 02:23:17 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/13 17:11:52 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "validate.h"

int		c_char_check(char c)
{
	return (c == '.' || c == '#' || c == '\n');
}

int		elem_char_check(t_list *elem)
{
	return (ft_strevery((char *)elem->content, c_char_check));
}

size_t	list_len_check(t_list *lst)
{
	return (ft_lstlen(lst) <= 26);
}
