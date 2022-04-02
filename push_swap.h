/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:02:10 by frudello          #+#    #+#             */
/*   Updated: 2022/03/29 13:38:51 by frudello         ###   ########.fr       */
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
	int		*na;
	int		*nb;
	int		*a;
	int		*b;
	int		count;
	int		size_a;
	int		size_b;
	int		max_int_liss;
	int		*lis;
	int		*lis_flag;
}			t_stack;

char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
int			ft_wordcount(char *str, char *charset);
void		parsing_argument(t_stack *stack, char **argv, int argc);
void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		swap(t_stack *stack);
void		push_a(t_stack *stack);
void		push_b(t_stack *stack);
void		ra(t_stack *stack, int def);
void		rb(t_stack *stack, int def);
void		rr(t_stack *stack);
void		rra(t_stack *stack, int def);
void		rrb(t_stack *stack, int def);
void		rrr(t_stack *stack);
void		fill_lis(t_stack *stack);
void		set_lis_flag(t_stack *stack);
void		max_n_int_order(t_stack *stack);
void		fill_nb(t_stack *stack);
void		fill_na(t_stack *stack);
int			what_a_n(t_stack *stack);
int			how_many(t_stack *stack, int i);
void		pusch_svap(t_stack *stack);
int			check_max(t_stack *stack, int i);
int			check_min(t_stack *stack, int i);
void		sistemiamolo(t_stack *stack);
void		sistemiamolo_rr_ra(t_stack *stack);
void		sistemiamolo_rr_rb(t_stack *stack);
void		siatemiamolo_rrr_rra(t_stack *stack);
void		sistemiamolo_rrr_rrb(t_stack *stack);
void		siatemiamolo_rra_rb(t_stack *stack);
void		siatemiamolo_ra_rrb(t_stack *stack);
void		lastmuve(t_stack *stack);
void		tre_numeri(t_stack *stack);
void		cinque_numeri(t_stack *stack);
int			n_min(t_stack *stack);
void		n_doppi(t_stack *stack);
void		parsing_argument_help(t_stack *stack, char **argv, int argc);
void		s_nbr(char **contr);
int			fill_na_help(t_stack *stack, int i);
int			alcontrario(t_stack *stack);

#endif
