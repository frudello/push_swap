/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:14:32 by frudello          #+#    #+#             */
/*   Updated: 2022/04/06 18:07:11 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_space(char *str)
{
	int	j;

	j = 1;
	while (str[j])
	{
		if (str[j] == ' ')
			return (1);
		j++;
	}
	return (0);
}

int	filler_helper(t_stack *stack, char *argv, int k)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(argv, ' ');
	while (split[i])
	{
		stack->a[k] = ft_atoi(split[i]);
		free(split[i]);
		i++;
		k++;
	}
	free(split);
	return (k - 1);
}

void	parsing_argument_help(t_stack *stack, char **argv, int argc)
{
	int	i;
	int	k;

	stack->a = malloc(stack->count * sizeof(int));
	if (!stack->a)
		exit(0);
	stack->b = malloc(stack->count * sizeof(int));
	if (!stack->b)
		exit(0);
	stack->size_a = stack->count;
	stack->size_b = 0;
	i = 1;
	k = 0;
	while (i < argc)
	{
		if (has_space(argv[i]))
			k = filler_helper(stack, argv[i], k);
		else
			stack->a[k] = ft_atoi(argv[i]);
		i++;
		k++;
	}
}

void	parsing_argument(t_stack *stack, char **argv, int argc)
{
	int	i;

	i = 1;
	stack->count = 0;
	s_nbr(argv);
	while (i < argc)
	{
		if (has_space(argv[i]))
			stack->count += ft_wordcount(argv[i], " ");
		else
			stack->count++;
		i++;
	}
	parsing_argument_help(stack, argv, argc);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		i;

	i = 0;
	(void) argc;
	parsing_argument(&stack, argv, argc);
	n_doppi(&stack);
	pusch_svap(&stack);
	free(stack.a);
	stack.a = NULL;
	free(stack.b);
	stack.b = NULL;
	return (0);
}
