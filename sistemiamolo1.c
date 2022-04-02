/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sistemiamolo1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:01:23 by frudello          #+#    #+#             */
/*   Updated: 2022/03/25 17:48:38 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	siatemiamolo_rra_rb(t_stack *stack)
{
	int	i;

	i = what_a_n(stack);
	stack->na[i] *= -1;
	while (stack->nb[i] > 0)
	{
		rb(stack, 1);
		stack->nb[i]--;
	}
	while (stack->na[i] > 0)
	{
		rra(stack, 1);
		stack->na[i]--;
	}
	push_a(stack);
}

void	siatemiamolo_ra_rrb(t_stack *stack)
{
	int	i;

	i = what_a_n(stack);
	stack->nb[i] *= -1;
	while (stack->na[i] > 0)
	{
		ra(stack, 1);
		stack->na[i]--;
	}
	while (stack->nb[i] > 0)
	{
		rrb(stack, 1);
		stack->nb[i]--;
	}
	push_a(stack);
}
