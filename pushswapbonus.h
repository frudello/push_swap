/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapbonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:59:39 by frudello          #+#    #+#             */
/*   Updated: 2022/04/02 19:25:13 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAPBONUS_H
# define PUSHSWAPBONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_bonus
{
	int	*a;
	int	count;
	int	size_a;
}			t_bonus;

char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
int			ft_wordcount(char *str, char *charset);
void		parsing_argument(t_bonus *stack, char **argv, int argc);
char		*ft_read(int fd);
void		s_nbr(char **contr);

#endif
