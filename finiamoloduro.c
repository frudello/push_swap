/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finiamoloduro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:18:17 by frudello          #+#    #+#             */
/*   Updated: 2022/04/05 20:52:19 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lastmuve(t_stack *stack)
{
	int	i;
	int	save;

	i = -1;
	save = 0;
	while (++i < stack->size_a)
		if (stack->a[save] > stack->a[i])
			save = i;
	if (save > stack->size_a / 2)
	{
		while (save - stack->size_a < 0)
		{
			rra(stack, 1);
			save++;
		}
	}
	else
	{
		while (save > 0)
		{
			ra(stack, 1);
			save--;
		}
	}
}

void	tre_numeri(t_stack *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[0] < stack->a[2])
	{
		swap_a(stack);
		ra(stack, 1);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[0] > stack->a[2])
	{
		swap_a(stack);
		rra(stack, 1);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[0] > stack->a[2])
		rra(stack, 1);
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[0] < stack->a[2])
		swap_a(stack);
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[0] > stack->a[2])
		ra(stack, 1);
}

void	cinque_numeri(t_stack *stack)
{
	int	i;

	while (stack->size_a > 3)
	{
		i = n_min(stack);
		if (i > stack->size_a / 2)
		{
			while (i - stack->size_a < 0)
			{
				rra(stack, 1);
				i++;
			}
			push_b(stack);
		}
		else
		{
			while (i > 0)
			{
				ra(stack, 1);
				i--;
			}
			push_b(stack);
		}
	}
}

int	n_min(t_stack *stack)
{
	int	i;
	int	save;

	save = 0;
	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[save] > stack->a[i])
			save = i;
		i++;
	}
	return (save);
}

void	n_doppi(t_stack *stack)
{
	int	i;
	int	e;

	i = 0;
	if (stack->size_a == 1)
		exit(0);
	while (i < stack->size_a)
	{
		e = i + 1;
		while (e < stack->size_a)
		{
			if (stack->a[i] == stack->a[e])
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			e++;
		}
		i++;
	}
}
