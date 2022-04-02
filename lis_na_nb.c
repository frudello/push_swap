/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_na_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:08:13 by frudello          #+#    #+#             */
/*   Updated: 2022/03/25 18:45:05 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_lis(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	stack->max_int_liss = 0;
	stack->lis = malloc(sizeof(int) * stack->size_a);
	if (!stack->lis)
		exit(0);
	while (++i < stack->size_a)
		stack->lis[i] = 1;
	i = -1;
	while (++i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->a[i] < stack->a[j] && stack->lis[i] == stack->lis[j])
			{
				stack->lis[j] += 1;
				if (stack->lis[j] > stack->max_int_liss)
					stack->max_int_liss = stack->lis[j];
			}
			j++;
		}
	}
}

void	set_lis_flag(t_stack *stack)
{
	int	i;

	i = stack->size_a - 1;
	stack->lis_flag = (int *) malloc(sizeof(int) * stack->size_a);
	if (!stack->lis_flag)
		exit(0);
	while (i >= 0)
	{
		if (stack->lis[i] == stack->max_int_liss)
		{
			stack->lis_flag[i] = 1;
			stack->max_int_liss--;
		}
		else
			stack->lis_flag[i] = 0;
		i--;
	}
	free(stack->lis);
}

void	max_n_int_order(t_stack *stack)
{
	int	i;
	int	size;

	size = stack->size_a;
	i = 0;
	while (i < size)
	{
		if (stack->lis_flag[i] == 1)
			ra(stack, 1);
		else
			push_b(stack);
		i++;
	}
	free(stack->lis_flag);
}

void	fill_nb(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_b)
	{
		if (i > stack->size_b / 2)
			stack->nb[i] = i - stack->size_b;
		else
			stack->nb[i] = i;
		i++;
	}
}
