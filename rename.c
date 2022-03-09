/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:14:32 by frudello          #+#    #+#             */
/*   Updated: 2022/03/09 19:08:42 by frudello         ###   ########.fr       */
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
                printf("errore\n");
                exit(1);
            }
            else if(contr[j][i] == '-' || contr[j][i] == '+')
            {
                if(contr[j][i+1] == '-' || contr[j][i+1] == '+')
                {
                    printf("errore\n");
                    exit(1);
                }
            }
            i++;
        }
        j++;
    }
}

// int e_str(char *contr)
// {
//     int j;
    
//     j = 1;
//     while(contr[j])
//     {
//         else if(contr[j] == ' ')
//         {
//             return(1);
//         }
//         j++;
//     }
//     return (0);
// }

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

int main(int argc, char **argv)
{
    int i = 0;
    (void) argc;
    t_stack stack;
    parsing_argument(&stack, argv);
    while (stack.a[i])
    {
        printf("%d\n", stack.a[i]);
    }
    
        

}