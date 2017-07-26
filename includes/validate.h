/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 02:02:29 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/29 01:48:56 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "libft.h"
# include "tetread.h"

int					validate_tetriminos(t_list *tetriminos);
size_t				list_len_check(t_list *lst);
int					elem_line_check(t_list *elem);
int					elem_len_check(t_list *elem);
int					elem_neighbor_check(t_list *elem);
int					elem_hashtag_check(t_list *elem);
int					elem_char_check(t_list *elem);
int					c_char_check(char c);

#endif
