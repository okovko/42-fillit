/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 02:23:26 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/13 17:11:48 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "validate.h"

int		validate_tetriminos(t_list *tetriminos)
{
	if (!ft_lstevery(tetriminos, elem_char_check))
		ft_putstr("elem_char_check is failing\n");
	if (!ft_lstevery(tetriminos, elem_line_check))
		ft_putstr("elem_line_check is failing\n");
	if (!ft_lstevery(tetriminos, elem_len_check))
		ft_putstr("elem_len_check is failing\n");
	if (!ft_lstevery(tetriminos, elem_neighbor_check))
		ft_putstr("elem_neighbor_check is failing\n");
	if (!ft_lstevery(tetriminos, elem_hashtag_check))
		ft_putstr("elem_hashtag_check is failing\n");
	if (!list_len_check(tetriminos))
		ft_putstr("list_len_check is failing\n");
	return (ft_lstevery(tetriminos, elem_char_check) &&
			ft_lstevery(tetriminos, elem_line_check) &&
			ft_lstevery(tetriminos, elem_len_check) &&
			ft_lstevery(tetriminos, elem_neighbor_check) &&
			ft_lstevery(tetriminos, elem_hashtag_check) &&
			list_len_check(tetriminos));
}

int		elem_line_check(t_list *elem)
{
	char const	*s;
	unsigned	len;

	s = (char const *)(elem->content);
	len = ft_word_length(s, '\n');
	while (len == 4)
	{
		s = ft_next_word(s, '\n');
		len = ft_word_length(s, '\n');
	}
	return (*s == '\0');
}

int		elem_len_check(t_list *elem)
{
	int		i;
	char	c;
	char	*s;

	i = 0;
	s = (char *)(elem->content);
	while ((c = *s++))
	{
		i++;
		if (i > 20)
			return (0);
	}
	return (i == 20);
}

int		elem_neighbor_check(t_list *elem)
{
	int		i;
	int		cond;
	char	c;
	char	*s;

	cond = 0;
	i = 0;
	s = (char *)(elem->content);
	while ((c = s[i]))
	{
		if (c == '#')
		{
			cond = i - 5 > 0 && s[i - 5] == '#';
			cond = cond || (i - 1 > 0 && s[i - 1] == '#');
			cond = cond || (i + 1 > 0 && s[i + 1] == '#');
			cond = cond || (i + 5 > 0 && s[i + 5] == '#');
			if (!cond)
				return (0);
		}
		i++;
	}
	return (1);
}

int		elem_hashtag_check(t_list *elem)
{
	int		i;
	int		hashtags;
	char	c;
	char	*s;

	hashtags = 0;
	i = 0;
	s = (char *)(elem->content);
	while ((c = s[i]))
	{
		hashtags += c == '#';
		if (hashtags > 4)
			return (0);
		i++;
	}
	return (hashtags == 4);
}
