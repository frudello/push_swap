/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:13:32 by frudello          #+#    #+#             */
/*   Updated: 2022/03/14 17:27:46 by frudello         ###   ########.fr       */
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
			if(stack->a[j] > stack->a[i] && stack->lis[j] > stack->max_int_liss)
			{
				stack->lis[j] += 1;
				if(stack->lis[j] > stack->max_int_liss)
					stack->max_int_liss = stack->lis[j];
			}
			j++;
		}
		i++;
	}
}

void set_lis_flag(t_stack *stack)
{
	int i;
	
	i = stack->size_a - 1;
	stack->lis_flag = (int *) malloc(sizeof(int) * stack->size_a);
	while(i > 0)
	{
		if(stack->lis[i] == stack->max_int_liss)
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

void max_n_int_order(t_stack *stack)
{
	int i;
	
	i = 0;
	while(i < stack->size_a)
	{
		if(stack->lis_flag[i] = 1)
			ra(stack);
		else
			push_b(stack);
		i++;
	}
	free(stack->lis_flag);
}



void fill_nb(t_stack *stack)
{
	int i;
	int ;

	i = 0;
	o = stack->size_b/-2;
	stack->nb = (int *) malloc(sizeof(int) * stack->size_b);
	if(!na)
		return(0);
	while(i <= stack->size_b/2)
	{
		stack->nb[i] = i;
		i++;
	}
	while(i >= stack->size_b)
	{
		stack->nb[i] = o;
		i++;
		o++;
	}
}

void what_a_n(t_stack *stack)
{
	
}