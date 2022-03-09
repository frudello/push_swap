# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:36:05 by frudello          #+#    #+#              #
#    Updated: 2022/03/09 19:01:15 by frudello         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = ft_split.c 	\
		rename.c	\
		funzionilibft.c
		

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .
.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}
$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)
all: $(NAME)

fclean: clean
	$(RM) $(NAME)
clean:
	$(RM) -f $(OBJS)
re: fclean all
