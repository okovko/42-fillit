/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:24:25 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/24 03:41:27 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rectchr(t_text *tx, t_rect *rx, char *pos, char query)
{
	if (NULL != pos && *pos == query)
		return (pos);
	while (NULL != (pos = ft_next_in_rect(tx, rx, pos)))
		if (*pos == query)
			return (pos);
	return (NULL);
}
