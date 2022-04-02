/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:13:32 by frudello          #+#    #+#             */
/*   Updated: 2022/03/29 13:39:21 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	what_a_n(t_stack *stack)
{
	int	i;
	int	save;
	int	mosse;
	int	tmp;

	mosse = 99999;
	save = 0;
	i = 0;
	while (i < stack->size_b)
	{
		tmp = how_many(stack, i);
		if (tmp < 0)
			tmp *= -1;
		if (mosse > tmp)
		{
			save = i;
			mosse = tmp;
		}
		i++;
	}
	return (save);
}

int	how_many(t_stack *stack, int i)
{
	int	tmp;

	tmp = 0;
	if (stack->na[i] > 0 && stack->nb[i] > 0)
	{
		if (stack->na[i] > stack->nb[i])
			tmp = stack->na[i];
		else
			tmp = stack->nb[i];
	}
	if (stack->na[i] <= 0 && stack->nb[i] <= 0)
	{
		if (stack->na[i] < stack->nb[i])
			tmp = stack->na[i];
		else
			tmp = stack->nb[i];
	}
	if (stack->na[i] <= 0 && stack->nb[i] >= 0)
		tmp = (stack->na[i] * -1) + stack->nb[i];
	if (stack->na[i] >= 0 && stack->nb[i] <= 0)
		tmp = stack->na[i] + (stack->nb[i] * -1);
	return (tmp);
}

void	pusch_svap2(t_stack *stack)
{
	fill_lis(stack);
	set_lis_flag(stack);
	max_n_int_order(stack);
	stack->na = malloc(stack->size_b * sizeof(int));
	if (!stack->na)
		exit(0);
	stack->nb = malloc(sizeof(int) * stack->size_b);
	if (!stack->nb)
		exit(0);
	while (stack->size_b > 0)
	{
		fill_nb(stack);
		fill_na(stack);
		sistemiamolo(stack);
	}
	lastmuve(stack);
	free(stack->na);
	stack->na = NULL;
	free(stack->nb);
	stack->nb = NULL;
}

void	pusch_svap(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size_a == 3)
	{
		tre_numeri(stack);
		return ;
	}
	if (stack->size_a == 5)
	{
		cinque_numeri(stack);
		tre_numeri(stack);
		push_a(stack);
		push_a(stack);
		write(1, "pa\npa\n", 6);
		return ;
	}
	if (alcontrario(stack) == 0)
		pusch_svap2(stack);
}

int	check_max(t_stack *stack, int i)
{
	int	o;
	int	j;

	o = 1;
	j = 0;
	while (stack->a[j] < stack->a[o] && o < stack->size_a)
	{
		j = o;
		o++;
	}
	if (stack->b[i] > stack->a[j])
		return (j + 1);
	else
		return (-1);
}
