/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:14:32 by frudello          #+#    #+#             */
/*   Updated: 2022/03/24 18:01:51 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void s_nbr(char **contr)
{
	int i;
	int j;
	
	j = 1;
	while(contr[j])
	{
		i = 0;
		while(contr[j][i])
		{
			if(!(contr[j][i] == '-' || contr[j][i] == '+' || contr[j][i] == ' ' || (contr[j][i] > 39 && contr[j][i] < 58)))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			else if(contr[j][i] == '-' || contr[j][i] == '+')
			{
				if(contr[j][i+1] == '-' || contr[j][i+1] == '+')
				{
					write(1, "Error\n", 6);
					exit(0);
				}
			}
			i++;
		}
		j++;
	}
}

int has_space(char *str)
{
    int j;
	
    j = 1;
    while(str[j])
    {
        if(str[j] == ' ')
            return(1);
        j++;
    }
    return (0);
}

// int counter(char **numeri)
// {
//     int j;
//     char **count;

//     count = i
	
//     contatore = 0;
//     j = 1;
//     while(numeri[j])
//     {
//         count = ft_split(numeri[j]);
//         free(count);
//         return(0);
//     }
// }

// char *copy(char **bho)
// {
//     int i;
//     int j;
//     int o;
//     char *a;
//     char **temp;
//     t_count

//     a = malloc(count);
//     if (!a)
//         return(0);
//     i = 1;
//     while(bho[i])
//     {
//         temp = ft_split(bho[i])
		
//     }
// }

// int prova(char **test)
// {
//     int counter;
//     int *a;
	
//     counter = 0;
//     if(s_nbr(test))
//     {
		
//         a = malloc(counter - 1);
//         counter = 1;
//         while(test[counter])
//         {
//             a[counter - 1] = ft_atoi(test[counter]);
//             counter++;
//         }
//         counter = 0;
//     }
// }



/*
void parsing_argument(t_stack *stack, char **argv)
{
	int i;
	int y;
	int j;


	i = 0;
	y = 0;
	j = 0;
	s_nbr(argv);
	while (argv[i])
	{
		stack->count += ft_wordcount(argv[i], " ");
		i++;
	}
	stack->count--;
	stack->a = malloc(stack->count * sizeof(int));
	stack->b = malloc(stack->count * sizeof(int));
	stack->size_a = stack->count;
	i = 0;
	while(argv[i])
	{
		stack->temp = ft_split(argv[i], ' ');
		y = 0;
		while(stack->temp[y])
		{
			stack->a[j] = ft_atoi(stack->temp[y]);
			j++;
			y++;
		}
		i++;
	}
}
*/

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

void parsing_argument(t_stack *stack, char **argv, int argc)
{
	int i;
	int k;
	
	i = 1;
	k = 0;
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
	stack->a = malloc(stack->count * sizeof(int));
	stack->b = malloc(stack->count * sizeof(int));
	stack->size_a = stack->count;
	stack->size_b = 0;
	i = 1;
	while(i < argc)
	{
		if (has_space(argv[i]))
			k = filler_helper(stack, argv[i], k);
		else
			stack->a[k] = ft_atoi(argv[i]);
		i++;
		k++;
	}
}

int main(int argc, char **argv)
{
	int i = 0;
	(void) argc;
	t_stack stack;
	
	parsing_argument(&stack, argv, argc);
	// printf("Size: %d\n", stack.size_a);
	// while (i < stack.size_a)
	// {
	// 	printf("%d\n", stack.a[i]);
	// 	i++;
	// }
	// printf("\nfinito\n");
	//swap_a(&stack);
	i = 0;
	// while (i < stack.5size_a)
	// {
	// 	printf("%d\n", stack.a[i]);
	// 	i++;
	// }
	n_doppi(&stack);
	pusch_svap(&stack);
	// printf("usciamol'a speriamo sia giusto\n");
	// while (i < stack.size_a)
	// {
	// 	printf("%d\n", stack.a[i]);
	// 	i++;
	// }
	/*
	printf("usciamo il b\n");
	i = 0;
	while (i < stack.size_b)
	{
		printf("%d\n", stack.b[i]);
		i++;
	}
	push_a(&stack);
	push_a(&stack);
	push_a(&stack);
	i = 0;
	printf("usciamo la a\n");
	while (i < stack.size_a)
	{
		printf("%d\n", stack.a[i]);
		i++;
	}
	printf("usciamo il b\n");
	i = 0;
	while (i < stack.size_b)
	{
		printf("%d\n", stack.b[i]);
		i++;
	}*/
	free(stack.a);
	free(stack.b);
	free(stack.na);
	free(stack.nb);
	return(0);
}