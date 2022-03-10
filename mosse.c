/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:35:58 by frudello          #+#    #+#             */
/*   Updated: 2022/03/10 12:08:25 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stack *stack)
{
    char temp;
    temp = stack->a[0];
    stack->a[0] = stack->a[1];
    stack->a[1] = temp;
}

void swap_b(t_stack *stack)
{b
    char temp;
    temp = stack->b[0];
    stack->b[0] = stack->b[1];
    stack->b[1] = temp;
}

void swap(t_stack *stack)
{
    char temp;
    temp = stack->a[0];
    stack->a[0] = stack->a[1];
    stack->a[1] = temp;
    temp = stack->b[0];
    stack->b[0] = stack->b[1];
    stack->b[1] = temp;
}

void push_a(t_stack *stack)
{
	int i;
	
	i = 0;
	while(stack->b[i])
	{
		stack->b[i + 1] = stack->b[i];
		i++;
	}
	stack->b[i] = stack->a[i];
    i = 0;
	while(stack->a[i + 1])
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i+1] = '\0';
	stack->size_a--;
	stack->size_b++;
}

void push_b(t_stack *stack)
{
	int i;
	
	i = 0;
	while(stack->a[i])
	{
		stack->a[i + 1] = stack->a[i];
		i++;
	}
	stack->a[i] = stack->b[i];
    i = 0;
	while(stack->b[i + 1])
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i+1] = '\0';
	stack->size_b--;
	stack->size_a++;
}

void ra(t_stack *stack)
{
    char temp;
    temp = stack->a[0];
    while(stack->a[i + 1])
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
    stack->a[size_a] = temp;
}

void rb(t_stack *stack)
{
    char temp;
    temp = stack->b[0];
    while(stack->b[i + 1])
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
    stack->b[size_b] = temp;
}

void rr(t_stack *stack)
{
    char temp;
    temp = stack->a[0];
    while(stack->a[i + 1])
	{a
		stack->a[i] = stack->a[i + 1];
		i++;
	}
    stack->a[size_a] = temp;
    temp = stack->b[0];
    while(stack->b[i + 1])
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
    stack->b[size_b] = temp;
}

void rra(t_stack *stack)
{
    char temp;
    temp = stack->a[size_b];
    while(stack->a[i + 1])
	{a
		stack->a[i + 1] = stack->a[i];
		i++;
	}
    stack->a[0] = temp;
}

void rrb(t_stack *stack)
{
    char temp;
    temp = stack->b[size_b];
    while(stack->b[i + 1])
	{
		stack->b[i + 1] = stack->b[i];
		i++;
	}
    stack->b[0] = temp;
}

void rrr(t_stack *stack)
{
    char temp;
    temp = stack->a[size_b];
    while(stack->a[i + 1])
	{a
		stack->a[i + 1] = stack->a[i];
		i++;
	}
    stack->a[0] = temp;
    temp = stack->b[size_b];
    while(stack->b[i + 1])
	{
		stack->b[i + 1] = stack->b[i];
		i++;
	}
    stack->b[0] = temp;
}
