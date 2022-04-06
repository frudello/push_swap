/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:38:59 by frudello          #+#    #+#             */
/*   Updated: 2022/04/06 19:29:58 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ordinato(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size_a && stack->a[i - 1] < stack->a[i])
		i++;
	if (i == stack->size_a)
		exit(0);
}

void	duenumeri(t_stack *stack, int i)
{
	if (stack->size_a == 2 && i == 2)
	{
		swap_a(stack);
		exit(0);
	}
}
