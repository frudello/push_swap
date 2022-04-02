/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:59:11 by frudello          #+#    #+#             */
/*   Updated: 2022/03/25 17:46:31 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	write(1, "ss\n", 3);
}

void	rr(t_stack *stack)
{
	ra(stack, -1);
	rb(stack, -1);
	write(1, "rr\n", 3);
}

void	rrr(t_stack *stack)
{
	rra(stack, -1);
	rrb(stack, -1);
	write(1, "rrr\n", 4);
}
