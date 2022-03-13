/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:13:32 by frudello          #+#    #+#             */
/*   Updated: 2022/03/13 18:57:58 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_h"

void fill_lis(t_stack *stack)
{
	int i;
	int j;
	
	i = 0;
	stack->max_int_liss = 0;
	stack->lis = (int *) malloc(sizeof(int) * stack->size_a);
	if(!stack->lis)
		return(0);
	while(stack->lis[i])
	{
		stack->lis[i] = 1;
		i++;
	}
	i = 0;
	while(stack->lis[i])
	{
		j = i + 1;
		while(stack->lis[j])
		{
			if(stack->lis[j] > stack->lis[i] && stack->lis[j] > stack->max_int_liss)
				stack->lis[j] += 1;
			j++;
		}
		stack->max_int_liss += 1;
		i++;
	}
}

void set_lis_fleg(t_stack *stack)
{
	int i;
	
	i = stack->size_a;
	stack->lis_fleg = (int *) malloc(sizeof(int) * stack->size_a);
	while(i > 0)
	{
		if(stack->lis[i] == stack->max_int_liss)
		{
			stack->lis_fleg[i] = 1;
			stack->max_int_liss--;
		}
		else
			stack->lis_fleg[i] = 0;
		i--;
	}
	free(stack->lis);
}

void max_n_int_order(t_stack *stack)
{
	
}