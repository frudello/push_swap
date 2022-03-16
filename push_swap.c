/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:13:32 by frudello          #+#    #+#             */
/*   Updated: 2022/03/16 19:24:41 by frudello         ###   ########.fr       */
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

void fill_na(t_stack *stack)
{
	int i;
	int o;
	
	o = 0;	
	i  = 0;
	while(i < stack->size_b)
	{
		while(stack->b[i] > stack->a[o]) //sbagliato da rivedere, se non parto a vedere al numero piu piccolo non posso considerarla corretta
			if(check(stack, i))
			{
				
			}
			o++;
		if(o > stack->size_a/2)
			o -= stack->size_a - 1;
		stack->na[i] = o;
		i++;
	}
}

int what_a_n(t_stack *stack)
{
	int i;
	int save;
	int tmp;
	
	save = 0;
	i = 0;
	while(stack->na[i])
	{
		monentaneo = how_many(stack, i);
		if(tmp < 0)
			tmp *= -1;
		if(save > tmp)
			save = i;
		i++;
	}
	return(save);
}

void how_many(t_stack *stack, int i)
{
	int tmp;
	
	tmp = 0;
	if(stack->na[i] > 0 && stack->nb[i] > 0)
		{
			if(stack->na[i] > stack->nb[i])
				tmp = stack->na[i];
			else
				tmp = stack->nb[i];
		}
		if(stack->na[i] < 0 && stack->nb[i] < 0)
		{
			if(stack->na[i] < stack->nb[i])
				tmp = stack->na[i];
			else
				tmp = stack->nb[i];
		}
		if(stack->na[i] < 0 && stack->nb[i] > 0)
			tmp = (stack->na[i] * -1) + stack->nb[i];
		if(stack->na[i] > 0 && stack->nb[i] < 0)
			tmp = stack->na[i] + (stack->nb[i] * -1);
		return(tmp);
}

void pusch_svap(t_stack *stack)
{
	int i;
	
	i = 0;
	while(stack->size_b > 0)
		sistemiamolo(stack);
		
}

int check(t_stack *stack, int i)
{
	int o;
	
	o = 0;
	while(o < stack->size_a)
	{
		if(stack->b[i] > stack->a[o])
			return(0);
		o++;
	}
}

void sistemiamolo(t_stack *stack)
{
	int i;
	
	i = what_a_n(stack);
	if(stack->na[i] > 0 && stack->nb[i] > 0)
	{
		if(stack->na[i] < stack->nb[i])
			sistemiamolo_rr_ra(stack);
		else
			sistemiamolo_rr_rb(stack);
	}
	if(stack->na[i] < 0 && stack->nb[i] < 0)
	{
		if(stack->na[i] < stack->nb[i])
			sistemiamolo_rrr_rrb(stack);
		else
			siatemiamolo_rrr_rra(stack);
	}
	if(stack->na[i] < 0 && stack->nb[i] > 0)
		siatemiamolo_rra_rb(stack);
	if(stack->na[i] > 0 && stack->nb[i] < 0)
		siatemiamolo_ra_rrb(stack);
}

void sistemiamolo_rr_ra(t_stack *stack)
{
	int i;

	i = what_a_n(stack);
	while(stack->nb[i] >= 0)
	{
		rr(stack);
		stack->na[i]--; 
		stack->nb[i]--;
	}
	while(stack->na[i] >= 0)
	{
		ra(stack);
		stack->na[i]--;
	}
	push_a(stack);
	}

}

void sistemiamolo_rr_rb(t_stack *stack)
{
	int i;

	i = what_a_n(stack);
	while(stack->na[i] >= 0)
	{
		rr(stack);
		stack->na[i]--;
		stack->nb[i]--;
	}
	while(stack->nb[i] >= 0)
	{
		rb(stack);
		stack->nb[i]--;
	}
	push_a(stack);
}

void siatemiamolo_rrr_rra(t_stack *stack)
{
	int i;
	
	i = what_a_n(stack);
	stack->na[i] *= -1;
	stack->nb[i] *= -1;
	while(stack->nb[i] >= 0)
	{
		rrr(stack);
		stack->na[i]--;
		stack->nb[i]--;
	}
	while(stack->na[i] >= 0)
	{
		rrb(stack);
		stack->na[i]--;
	}
	push_a(stack);
}

void sistemiamolo_rrr_rrb(t_stack *stack)
{
	int i;

	i = what_a_n(stack);
	stack->na[i] *= -1;
	stack->nb[i] *= -1;
	while(stack->na[i] >= 0)
	{
		rrr(stack);
		stack->na[i]--;
		stack->nb[i]--;
	}
	while(stack->nb[i] >= 0)
	{
		rrb(stack);
		stack->nb[i]--;
	}
	push_a(stack);
}

	if(stack->na[i] < 0 && stack->nb[i] > 0)

void siatemiamolo_rra_rb(t_stack *stack)
{
	int i;
	
	i = what_a_n(stack);
	stack->na[i] *= -1;
	while(stack->nb[i] >= 0)
	{
		rb(stack);
		stack->nb[i]--;
	}
	while(stack->na[i] >= 0)
	{
		rra(stack);
		stack->na[i]--;
	}
	push_a(stack);
}
	if(stack->na[i] > 0 && stack->nb[i] < 0)

void siatemiamolo_ra_rrb(t_stack *stack)
{
	int i;
	
	i = what_a_n(stack);
	stack->nb[i] *= -1;
	while(stack->na[i] >= 0)
	{
		ra(stack);
		stack->na[i]--;
	}
	while(stack->nb[i] >= 0)
	{
		rrb(stack);
		stack->nb[i]--;
	}
	push_a(stack);
}