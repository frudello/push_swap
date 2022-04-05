/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:27:13 by frudello          #+#    #+#             */
/*   Updated: 2022/04/06 00:30:57 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswapbonus.h"

void	which_move(t_bonus *bonus, char *s)
{
	if (strcmp(s, "ra\n") == 0)
		ra(bonus, -1);
	else if (strcmp(s, "rb\n") == 0)
		rb(bonus, -1);
	else if (strcmp(s, "pa\n") == 0)
		push_a(bonus);
	else if (strcmp(s, "pb\n") == 0)
		push_b(bonus);
	else if (strcmp(s, "rra\n") == 0)
		rra(bonus, -1);
	else if (strcmp(s, "rrb\n") == 0)
		rrb(bonus, -1);
	else if (strcmp(s, "sa\n") == 0)
		swap_a(bonus);
	else if (strcmp(s, "sb\n") == 0)
		swap_b(bonus);
	else if (strcmp(s, "ss\n") == 0)
		swap(bonus);
	else
		which_move_helper(bonus, s);
}

void	which_move_helper(t_bonus *bonus, char *s)
{
	if (strcmp(s, "rr\n") == 0)
		rr(bonus);
	else if (strcmp(s, "rrr\n") == 0)
		rrr(bonus);
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}
