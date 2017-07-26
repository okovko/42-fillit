# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olkovale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 19:35:21 by olkovale          #+#    #+#              #
#    Updated: 2017/07/22 07:03:09 by olkovale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FILES = tetread validate1 validate2 solver1 solver2 fillit tetriminos
SRCS = $(patsubst %, srcs/%.c, $(FILES))
BINS = $(patsubst %, %.o, $(FILES))
FLAGS = -g -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

.PHONY: all clean fclean

%.o : srcs/%.c
	gcc -Iincludes -Ilibft/includes $(FLAGS) -c $<

all: libft $(NAME)

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT) $(BINS)
	gcc -Iincludes -Ilibft/includes $(FLAGS) $(LIBFT) $(BINS) main.c -o $(NAME)

clean:
	make clean -C ./libft
	/bin/rm -f $(BINS)

fclean: clean
	make fclean -C ./libft
	/bin/rm -f $(NAME)

re: fclean all
