/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapbonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:59:39 by frudello          #+#    #+#             */
/*   Updated: 2022/04/05 18:38:54 by frudello         ###   ########.fr       */
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
	int		*b;
	int		*a;
	int		count;
	int		size_b;
	int		size_a;
	char	*line;
}			t_bonus;

char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
int			ft_wordcount(char *str, char *charset);
void		parsing_argument(t_bonus *bonus, char **argv, int argc);
int			ft_read(t_bonus *bonus, int fd);
void		s_nbr(char **contr);
int			ft_strcmp(const char *s1, const char *s2);
void		which_move(t_bonus *bonus, char *s);
void		swap_a(t_bonus *bonus);
void		swap_b(t_bonus *bonus);
void		swap(t_bonus *bonus);
void		push_a(t_bonus *bonus);
void		push_b(t_bonus *bonus);
void		ra(t_bonus *bonus, int def);
void		rb(t_bonus *bonus, int def);
void		rr(t_bonus *bonus);
void		rra(t_bonus *bonus, int def);
void		rrb(t_bonus *bonus, int def);
void		rrr(t_bonus *bonus);

#endif
