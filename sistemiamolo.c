/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sistemiamolo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:21 by frudello          #+#    #+#             */
/*   Updated: 2022/03/25 17:50:06 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sistemiamolo(t_stack *stack)
{
	int	i;

	i = what_a_n(stack);
	if (stack->na[i] > 0 && stack->nb[i] > 0)
	{
		if (stack->na[i] > stack->nb[i])
			sistemiamolo_rr_ra(stack);
		else
			sistemiamolo_rr_rb(stack);
	}
	else if (stack->na[i] < 0 && stack->nb[i] < 0)
	{
		if (stack->na[i] > stack->nb[i])
			sistemiamolo_rrr_rrb(stack);
		else
			siatemiamolo_rrr_rra(stack);
	}
	else if (stack->na[i] <= 0 && stack->nb[i] >= 0)
		siatemiamolo_rra_rb(stack);
	else if (stack->na[i] >= 0 && stack->nb[i] <= 0)
		siatemiamolo_ra_rrb(stack);
	else if (stack->na[i] == 0 && stack->nb[i] == 0)
		push_a(stack);
}

void	sistemiamolo_rr_ra(t_stack *stack)
{
	int	i;

	i = what_a_n(stack);
	while (stack->nb[i] > 0)
	{
		rr(stack);
		stack->na[i]--;
		stack->nb[i]--;
	}
	while (stack->na[i] > 0)
	{
		ra(stack, 1);
		stack->na[i]--;
	}
	push_a(stack);
}

void	sistemiamolo_rr_rb(t_stack *stack)
{
	int	i;

	i = what_a_n(stack);
	while (stack->na[i] > 0)
	{
		rr(stack);
		stack->na[i]--;
		stack->nb[i]--;
	}
	while (stack->nb[i] > 0)
	{
		rb(stack, 1);
		stack->nb[i]--;
	}
	push_a(stack);
}

void	siatemiamolo_rrr_rra(t_stack *stack)
{
	int	i;

	i = what_a_n(stack);
	while (stack->nb[i] < 0)
	{
		rrr(stack);
		stack->na[i]++;
		stack->nb[i]++;
	}
	while (stack->na[i] < 0)
	{
		rra(stack, 1);
		stack->na[i]++;
	}
	push_a(stack);
}

void	sistemiamolo_rrr_rrb(t_stack *stack)
{
	int	i;

	i = what_a_n(stack);
	stack->na[i] *= -1;
	stack->nb[i] *= -1;
	while (stack->na[i] > 0)
	{
		rrr(stack);
		stack->na[i]--;
		stack->nb[i]--;
	}
	while (stack->nb[i] > 0)
	{
		rrb(stack, 1);
		stack->nb[i]--;
	}
	push_a(stack);
}
