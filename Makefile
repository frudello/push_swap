# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:36:05 by frudello          #+#    #+#              #
#    Updated: 2022/03/10 10:41:39 by frudello         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH	= push_swap

CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

PUSH_SRCS =	funzionilibft.c								\
			ft_split.c									\
			rename.c									\

PUSH_OBJS	= ${PUSH_SRCS:.c=.o}

%.o: %.c
			$(CC) ${CFLAGS} -c $< -o $@ 

all:		push_swap

push_swap:  ${PUSH_OBJS}
			$(CC) ${CFLAGS} -o ${NAME_PUSH} ${PUSH_OBJS}

clean:
			rm -f *.o
			rm -f ./*/*.o

fclean: 	clean
			rm -f $(NAME_PUSH)
			rm -f $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re push_swap
