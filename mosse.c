/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:35:58 by frudello          #+#    #+#             */
/*   Updated: 2022/03/20 20:58:27 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stack *stack)
{
    int temp;
	
    temp = stack->a[0];
    stack->a[0] = stack->a[1];
    stack->a[1] = temp;
}

void swap_b(t_stack *stack)
{
    int temp;
	
    temp = stack->b[0];
    stack->b[0] = stack->b[1];
    stack->b[1] = temp;
}

void swap(t_stack *stack)
{
    int temp;
	
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

	i = stack->size_a;
	while(i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->size_a++;
	stack->a[0] = stack->b[0];
	i = 0;
	while(i + 1 < stack->size_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	// stack->b[stack->size_b - 1] = '\0';
	stack->size_b--;
	// printf("la grandezza di b é %d\n", stack->size_b);
}

void push_b(t_stack *stack)
{
	int i;
	// printf( "stack A PRIMA PB \n") ;
	// for (int y = 0; y < stack->size_a; y++)
	// 	printf("%d ", stack->a[y]);
	// printf( "\nstack B PRIMA PB \n") ;
	// for (int y = 0; y < stack->size_b; y++)
	// 	printf("%d ", stack->b[y]);
	i = stack->size_b;
	while(i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->size_b++;
	stack->b[0] = stack->a[0];
	//printf("ho messo il numero %d in B -> %d\n", stack->a[0], stack->b[0]);
	i = 0;
	while(i + 1 < stack->size_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->size_a--;
	//stack->a[stack->size_a - 1] = '\0';
	// printf( "stack A DOPO PB \n") ;
	// for (int y = 0; y < stack->size_a; y++)
	// 	printf("%d ", stack->a[y]);
	// printf( "\nstack B DOPO PB \n") ;
	// for (int y = 0; y < stack->size_b; y++)
	// 	printf("%d\n", stack->b[y]);
	// printf("\n");
	// sleep(2);

}

void ra(t_stack *stack)
{
    int temp;
	int i;
	
	i = 0;
	// printf( "stack A PRIMA RA \n") ;
	// for (int y = 0; y < stack->size_a; y++)
	// 	printf("%d ", stack->a[y]);
    temp = stack->a[0];
    while(i < stack->size_a -1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
    stack->a[i] = temp;
	// printf( "\nstack A dopo RA \n") ;
	// for (int y = 0; y < stack->size_a; y++)
	// 	printf("%d ", stack->a[y]);
	// printf("\n");
}

void rb(t_stack *stack)
{
    int temp;
	int i;
	
	i = 0;
    temp = stack->b[0];
    while(i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
    stack->b[i] = temp;
}

void rr(t_stack *stack)
{
   ra(stack);
   rb(stack);
}

void rra(t_stack *stack)
{
    int temp;
	int i;
	
    i = stack->size_a - 1;
    temp = stack->a[i];
	while(i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
    stack->a[0] = temp;
}

void rrb(t_stack *stack)
{
    int temp;
	int i;
	
    i = stack->size_b - 1;
    temp = stack->b[i];
	// printf("il temp di rrb é: %d", temp);
	while(i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	// printf("il temp di rrb é: %d", temp);
    stack->b[0] = temp;
}

void rrr(t_stack *stack)
{
   rra(stack);
   rrb(stack);
}
