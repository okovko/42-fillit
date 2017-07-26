/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 02:03:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 23:48:53 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

char		*check_fit(t_text *tx, t_rect *rx, char *spot, t_point *pt);
t_list		*get_adrs(t_text *tx, t_rect *rx, char *spot, t_list *points);
char		*text_in_rect(t_text *tx, t_rect *rx);
void		place_letter(t_list *adrs, char letter);
char		*text_in_rect(t_text *tx, t_rect *rx);

#endif
