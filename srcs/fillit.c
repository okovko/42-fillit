/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 12:59:01 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 21:45:26 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "fillit.h"
#include "libft.h"

char		*check_fit(t_text *tx, t_rect *rx, char *spot, t_point *pt)
{
	t_point	*offset;
	char	*pos;
	int		x;
	int		y;

	pos = ft_xy_in_str(tx, spot, pt->x, pt->y);
	RETIF(NULL, NULL == pos || *pos != '.');
	offset = ft_xy_from_str(tx, rx, pos);
	RETIF(NULL, NULL == offset);
	x = offset->x;
	y = offset->y;
	free(offset);
	RETIF(NULL, (size_t)x > rx->x1 || (size_t)y > rx->y1);
	return (pos);
}

t_list		*get_adrs(t_text *tx, t_rect *rx, char *spot, t_list *points)
{
	t_list			*adrs;
	t_point			*pt;
	char			*pos;

	NULLCHECK(tx, rx, spot, points);
	pos = spot;
	//pos = ft_rectchr(tx, rx, spot, '.');
	//RETIF(NULL, NULL == pos);
	adrs = NULL;
	ft_lstadd(&adrs, ft_lstnode((void *)pos, sizeof(char)));
	points = points->next;
	while (points)
	{
		pt = (t_point *)(points->content);
		pos = check_fit(tx, rx, pos, pt);
		IF(NULL == pos, ft_lstnfree(&adrs, 0), return (NULL));
		ft_lstadd(&adrs, ft_lstnode((void *)pos, sizeof(char)));
		points = points->next;
	}
	ft_lstsrev(&adrs);
	return (adrs);
}

void		place_letter(t_list *adrs, char letter)
{
	while (adrs)
	{
		*((char *)adrs->content) = letter;
		adrs = adrs->next;
	}
}

char		*text_in_rect(t_text *tx, t_rect *rx)
{
	char	*str;
	char	*line;
	size_t	width;
	size_t	length;
	size_t	i;

	width = (rx->x1 - rx->x0 + 2);
	length = (rx->y1 - rx->y0 + 1);
	str = malloc(width * length + 1);
	i = 0;
	line = tx->start;
	while (i < length)
	{
		ft_strncpy(str + i * width, line, width - 1);
		*(str + (i + 1) * (width) - 1) = '\n';
		i++;
		line = ft_xy_in_str(tx, line, 0, 1);
	}
	str[width * length] = '\0';
	return (str);
}
