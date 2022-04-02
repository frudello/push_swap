/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:56:31 by frudello          #+#    #+#             */
/*   Updated: 2022/03/25 17:46:26 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int def)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->a[0];
	while (i < stack->size_a -1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = temp;
	if (def == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int def)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->b[0];
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = temp;
	if (def == 1)
		write(1, "rb\n", 3);
}

void	rra(t_stack *stack, int def)
{
	int	temp;
	int	i;

	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = temp;
	if (def == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int def)
{
	int	temp;
	int	i;

	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = temp;
	if (def == 1)
		write(1, "rrb\n", 4);
}
