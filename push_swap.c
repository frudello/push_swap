/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:13:32 by frudello          #+#    #+#             */
/*   Updated: 2022/03/20 21:46:18 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_lis(t_stack *stack)
{
	int i;
	int j;
	
	i = 0;
	stack->max_int_liss = 0;
	stack->lis = (int *) malloc(sizeof(int) * stack->size_a);
	// if(!stack->lis)
	// 	return(0);
	while(i < stack->size_a)
	{
		stack->lis[i] = 1;
		i++;
	}
	i = 0;
	while(i < stack->size_a)
	{
		j = i + 1;
		while(j < stack->size_a)
		{
			if(stack->a[i] < stack->a[j] && stack->lis[i] == stack->lis[j])
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
	while(i >= 0)
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
		if(stack->lis_flag[i] == 1)
		{
			ra(stack);
			write(1, "ra\n", 3);
		}
		else
		{
			push_b(stack);
			write(1, "push_b\n", 7);
		}
		i++;
	}
	printf( "stack A \n") ;
	for (int y = 0; y < stack->size_a; y++)
		printf("%d ", stack->a[y]);
	printf("\n");
	printf( "stack B \n") ;
	for (int y = 0; y < stack->size_b; y++)
		printf("%d ", stack->b[y]);
	printf("\n");
	free(stack->lis_flag);
}



void fill_nb(t_stack *stack)
{
	int i;
	int o;

	i = 0;
	o = stack->size_b/-2;
	stack->nb = (int *) malloc(sizeof(int) * stack->size_b);
	// if(!na)
	// 	return(0);
	while(i <= stack->size_b/2)
	{
		stack->nb[i] = i;
		i++;
		//printf("hai dei problemi\n");
	}
	while(i < stack->size_b)
	{
		o++;
		stack->nb[i] = o;
		i++;
		// printf("mi piace il cazzo\n");
	}
	printf("la NB é: ");
	for (int y = 0; y < stack->size_b; y++)
		printf("%d, ", stack->nb[y]);
	printf("\n");
}

void fill_na(t_stack *stack)
{
	int i;
	int o;
		
	i  = 0;
	while(i < stack->size_b)
	{
		// printf("arrivo nel primo while di fill_na\n");
		o = 0;
		while(!(stack->b[i] > stack->a[o - 1] && stack->b[i] < stack->a[o]))
		{
			if(check_max(stack, i) >= 0)
			{
				o = check_max(stack, i);
				break;
			}
			if(check_min(stack, i) >= 0)
			{
				o = check_min(stack, i );
				break;
			}
			// if(stack->b[i] > stack->a[stack->size_a - 1] && stack->b[i] < stack->a[o])
			 	// break;
			o++;
		}
		/*if(stack->b[i] > stack->a[o])
		{
			o = stack->size_a - 1;
			while(stack->b[i] < stack->a[o])
				o--;
		}
		else
			while(stack->b[i] > stack->a[o])
				o++;
		if(o > stack->size_a/2)
			o -= stack->size_a - 1;
			*/
		stack->na[i] = o;
		i++;
	}
	printf("la NA é: ");
	for (int y = 0; y < stack->size_b; y++)
		printf("%d, ", stack->na[y]);
	printf("\n");
}

int what_a_n(t_stack *stack)
{
	int i;
	int save;
	int mosse;
	int tmp;
	
	mosse = 99999;
	save = 0;
	i = 0;
	while(i < stack->size_b)
	{
		// printf("save é: %d\n", save);
		tmp = how_many(stack, i);
		if(tmp < 0)
			tmp *= -1;
		if(mosse > tmp)
			save = i;
		i++;
	}
	// printf("how_many mi restituisce %d\n", tmp);
	// printf("save é: %d\n", save);
	return(save);
}

int how_many(t_stack *stack, int i)
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
	if(stack->na[i] <= 0 && stack->nb[i] <= 0)
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
	// printf("tmp é: %d\n", tmp);
	return(tmp);
}

void pusch_svap(t_stack *stack)
{
	int i;
	
	i = 0;
	fill_lis(stack);
	set_lis_flag(stack);
	max_n_int_order(stack);
	// for (int i = 0; i < stack->size_a; i++)
	// 	printf("%d, ", stack->a[i]);
	// printf("\n");
	// for (int i = 0; i < stack->size_b; i++)
	// 	printf("%d, ", stack->b[i]);
	// printf("\n");
	sleep(1);
	while(stack->size_b > 0)
	{
		// printf("sono arrivato nel ciclo di pusch_svap\n");
		fill_nb(stack);
		fill_na(stack);
		sistemiamolo(stack);
		sleep(1);
		// printf("faccio tutto ma non fa qullo che deve\n");
		printf("la A é : ");
		for(int y = 0; y < stack->size_a; y++)
			printf("%d, ", stack->a[y]);
		printf("\n");
		printf("la B é : ");
		for(int o = 0; o < stack->size_b; o++)
			printf("%d, ", stack->b[o]);
		printf("\n");
		// for (int y = 0; y < stack->size_b; y++)
		// printf("%d\n", stack->na[y]);
	}
	printf("sono uscito dal ciclo di pusch svap\n");
}

int check_max(t_stack *stack, int i)
{
	int o;
	int j;
	
	o = 1;
	j = 0;
	while(stack->a[j] > stack->a[j + 1]) //calcolo errato del numero massimo
	{
		if(stack->a[j] > stack->a[o])
			j = o;
		o++;
	}
	if(stack->b[i] > stack->a[j])
		return(j);
	else
		return(-1);
}

int check_min(t_stack *stack, int i)
{
	int o;
	int j;
	
	o = 0;
	j = 0;
	while(o < stack->size_a - 1)
	{
		if(stack->a[j] < stack->a[o])
			j = o;
		o++;
	}
	if(stack->b[i] < stack->a[j])
		return(j);
	else
		return(-1);
}

void sistemiamolo(t_stack *stack)
{
	int i;
	
	i = what_a_n(stack);
	// if(na[i] == 0)
	// {
	// 	push_a(stack);
	// 	write(1, "push_a\n", 7);
	// }
	if(stack->na[i] >= 0 && stack->nb[i] >= 0)
	{
		if(stack->na[i] > stack->nb[i])
			sistemiamolo_rr_ra(stack);
		else
			sistemiamolo_rr_rb(stack);
	}
	else if(stack->na[i] <= 0 && stack->nb[i] <= 0)
	{
		if(stack->na[i] < stack->nb[i])
			sistemiamolo_rrr_rrb(stack);
		else
			siatemiamolo_rrr_rra(stack);
	}
	else if(stack->na[i] < 0 && stack->nb[i] > 0)
		siatemiamolo_rra_rb(stack);
	else if(stack->na[i] > 0 && stack->nb[i] < 0)
		siatemiamolo_ra_rrb(stack);
	//printf("non penso che chi arrivi");
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
		write(1, "rr\n", 3);
	}
	while(stack->na[i] > 0)
	{
		ra(stack);
		stack->na[i]--;
		write(1, "ra\n", 3);
	}
	push_a(stack);
	write(1, "push_a\n", 7);
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
		write(1, "rr\n", 3);
		
	}
	while(stack->nb[i] > 0)
	{
		rb(stack);
		stack->nb[i]--;
		write(1, "rb\n", 3);
	}
	push_a(stack);
	write(1, "push_a\n", 7);
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
		write(1, "rrr\n", 4);
	}
	while(stack->na[i] > 0)
	{
		rrb(stack);
		stack->na[i]--;
		write(1, "rra\n", 4);
	}
	push_a(stack);
	write(1, "push_a\n", 7);
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
		write(1, "rrr\n", 4);
	}
	while(stack->nb[i] > 0)
	{
		rrb(stack);
		stack->nb[i]--;
		write(1, "rrb\n", 4);
	}
	push_a(stack);
	write(1, "push_a\n", 7);
}

	// if(stack->na[i] < 0 && stack->nb[i] > 0)

void siatemiamolo_rra_rb(t_stack *stack)
{
	int i;
	
	i = what_a_n(stack);
	stack->na[i] *= -1;
	while(stack->nb[i] > 0)
	{
		rb(stack);
		stack->nb[i]--;
		write(1, "rb\n", 3);
	}
	while(stack->na[i] > 0)
	{
		rra(stack);
		stack->na[i]--;
		write(1, "rra\n", 4);
	}
	push_a(stack);
	write(1, "push_a\n", 7);
}
	// if(stack->na[i] > 0 && stack->nb[i] < 0)

void siatemiamolo_ra_rrb(t_stack *stack)
{
	int i;
	
	i = what_a_n(stack);
	stack->nb[i] *= -1;
	while(stack->na[i] > 0)
	{
		ra(stack);
		stack->na[i]--;
		write(1, "ra\n", 3);
	}
	while(stack->nb[i] > 0)
	{
		rrb(stack);
		stack->nb[i]--;
		write(1, "rrb\n", 4);
	}
	push_a(stack);
	write(1, "push_a\n", 7);
}