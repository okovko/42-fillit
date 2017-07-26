/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 21:07:46 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 04:46:54 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

t_list		*map_tetriminos(t_list *tetriminos);
t_list		*tetrimino_str_to_points(t_list *elem);
t_list		*tetrimino_relative_points(t_list *elem);

#endif
