/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:02:10 by frudello          #+#    #+#             */
/*   Updated: 2022/03/10 17:54:52 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		count;
	int		size_a;
	int		size_b;
	char	**temp;
}			t_stack;

char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
int			ft_wordcount(char *str, char *charset);
void 		parsing_argument(t_stack *stack, char **argv, int argc);
void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		swap(t_stack *stack);
void		push_a(t_stack *stack);
void		push_b(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);



#endif
