/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:26:09 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 03:55:08 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "tetread.h"
#include "validate.h"

static int				print_err()
{
	ft_putstr("error\n");
	return (0);
}

static int				print_use()
{
	ft_putstr("Usage: ./fillit [filepath]\n");
	return (0);
}

t_list					*read_file(int argc, char **argv)
{
	t_read_tetriminos	*ret;
	t_list				*tetriminos;
	int					fd;

	IF(argc != 2, print_use(), return (NULL));
	IF(OR((fd = open(argv[1], O_RDONLY)) < 0,
	NULL == (ret = read_tetriminos(fd))),
		print_err();
		return (NULL));
	IF(OR(ERR_READ_TETRIMINOS_FAILURE == ret->err,
	false == validate_tetriminos(ret->tetriminos)),
		free(ret->tetriminos),
		free(ret),
		print_err(),
		close(fd),
		return (NULL));
	tetriminos = ret->tetriminos;
	free(ret);
	close(fd);
	return (tetriminos);
}

t_read_tetriminos		*read_tetriminos(int fd)
{
	char				buf[21];
	char				sep;
	t_read_tetriminos	*ret;
	int					read_ret;
	int					sep_ret;

	if (!(ret = malloc(sizeof(t_read_tetriminos))))
		return (NULL);
	ret->tetriminos = NULL;
	while (((read_ret = read(fd, buf, 20))) > 0)
	{
		buf[20] = '\0';
		ft_lstadd(&(ret->tetriminos), ft_lstnew(buf, 21));
		if ((sep_ret = (read(fd, &sep, 1))) <= 0)
			break ;
	}
	ret->err = read_ret <= 0 || sep_ret < 0;
	ft_lstsrev(&(ret->tetriminos));
	return (ret);
}
