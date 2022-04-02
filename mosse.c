/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:35:58 by frudello          #+#    #+#             */
/*   Updated: 2022/03/25 17:46:05 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int	temp;

	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	int	temp;

	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	write(1, "sb\n", 3);
}

void	push_a(t_stack *stack)
{
	int	i;

	i = stack->size_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->size_a++;
	stack->a[0] = stack->b[0];
	i = 0;
	while (i + 1 < stack->size_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->size_b--;
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack)
{
	int	i;

	i = stack->size_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->size_b++;
	stack->b[0] = stack->a[0];
	i = 0;
	while (i + 1 < stack->size_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->size_a--;
	write(1, "pb\n", 3);
}
