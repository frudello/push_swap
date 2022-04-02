/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:13:11 by frudello          #+#    #+#             */
/*   Updated: 2022/03/29 16:10:24 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_nbr(char **contr)
{
	int	i;
	int	j;

	j = 0;
	while (contr[++j])
	{
		i = -1;
		while (contr[j][++i])
		{
			if (!(contr[j][i] == '-' || contr[j][i] == '+' || contr[j][i] == ' '
				|| (contr[j][i] > 39 && contr[j][i] < 58)))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			else if (contr[j][i] == '-' || contr[j][i] == '+')
			{
				if (contr[j][i + 1] == '-' || contr[j][i + 1] == '+')
				{
					write(1, "Error\n", 6);
					exit(0);
				}
			}
		}
	}
}

int	fill_na_help(t_stack *stack, int i)
{
	int	o;

	o = 1;
	while (!(stack->b[i] > stack->a[o - 1] && stack->b[i] < stack->a[o]))
	{
		if (check_max(stack, i) >= 0)
		{
			o = check_max(stack, i);
			break ;
		}
		if (check_min(stack, i) >= 0)
		{
			o = check_min(stack, i);
			break ;
		}
		o++;
	}
	return (o);
}

void	fill_na(t_stack *stack)
{
	int	i;
	int	o;

	i = -1;
	while (++i < stack->size_b)
	{
		if (stack->b[i] > stack->a[stack->size_a - 1]
			&& stack->b[i] < stack->a[0])
			stack->na[i++] = 0;
		o = fill_na_help(stack, i);
		if (o > stack->size_a / 2)
			o -= stack->size_a;
		stack->na[i] = o;
	}
}

int	check_min(t_stack *stack, int i)
{
	int	o;
	int	j;

	o = 0;
	j = 0;
	while (o < stack->size_a)
	{
		if (stack->a[j] > stack->a[o])
			j = o;
		o++;
	}
	if (stack->b[i] < stack->a[j])
		return (j);
	else
		return (-1);
}

int	alcontrario(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size_a && stack->a[i - 1] > stack->a[i])
	{
		i++;
	}
	if (i == stack->size_a)
	{
		while (i > 0)
		{
			push_b(stack);
			i--;
		}
		while (i < stack->size_b)
		{
			rrb(stack, 1);
			push_a(stack);
		}
		return (1);
	}
	return (0);
}
