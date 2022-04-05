# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:36:05 by frudello          #+#    #+#              #
#    Updated: 2022/04/06 00:33:04 by frudello         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH	= push_swap
NAME_BONUS	= checker

CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror

PUSH_SRCS =	funzionilibft.c	\
			ft_split.c		\
			rename.c		\
			mosse.c			\
			mosse1.c		\
			mosse2.c		\
			push_swap.c		\
			finiamoloduro.c	\
			sistemiamolo.c	\
			sistemiamolo1.c	\
			lis_na_nb.c		\
			scit.c			\

BONUS_SRCS = pushswapbonus.c\
			bonus2.c		\
			bonus3.c		\
			ft_split.c		\
			funzionilibft.c	\
			mosseBonus.c	\
			mosse1Bonus.c	\
			mosse2Bonus.c	\

PUSH_OBJS	= ${PUSH_SRCS:.c=.o}

BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

%.o: %.c
			$(CC) ${CFLAGS} -c $< -o $@

all:		push_swap

push_swap:  ${PUSH_OBJS}
			$(CC) ${CFLAGS} -o ${NAME_PUSH} ${PUSH_OBJS}

bonus:	${BONUS_OBJS}
		$(CC) ${CFLAGS} -o ${NAME_BONUS} ${BONUS_OBJS}
clean:
			rm -f *.o
			rm -f ./*/*.o

fclean: 	clean
			rm -f $(NAME_PUSH)
			rm -f $(NAME_CHECKER)
			rm -f $(NAME_BONUS)

re: fclean all bonus

.PHONY: all clean fclean re push_swap
