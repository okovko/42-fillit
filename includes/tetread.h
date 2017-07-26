/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetread.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:24:56 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 03:50:36 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETREAD_H
# define TETREAD_H

# include "libft.h"

typedef enum	e_err_read_tetriminos
{
	ERR_READ_TETRIMINOS_SUCCESS, ERR_READ_TETRIMINOS_FAILURE
}				t_err_read_tetriminos;

struct								s_read_tetriminos
{
	t_list							*tetriminos;
	t_err_read_tetriminos			err;
};

typedef struct s_read_tetriminos	t_read_tetriminos;

t_read_tetriminos					*read_tetriminos(int fd);
t_list								*read_file(int argc, char **argv);

#endif
