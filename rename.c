/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:14:32 by frudello          #+#    #+#             */
/*   Updated: 2022/03/08 17:15:26 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int s_nbr(char **contr)
{
    int i;
    int j;
    
    j = 1;
    while(contr[j])
    {
        i = 0;
        while(contr[j][i])
        {
            if(!(contr[j][i] == '-' || contr[j][i] == '+' || contr[j][i] == ' ' || contr[j][i] == 34 || (contr[j][i] > 39 && contr[j][i] < 58)))
            {
                ft_printf("errore sei un bastardo");
                return(0);
            }
            else if(contr[j][i] == '-' || contr[j][i] == '+')
            {
                if(contr[j][i+1] == '-' || contr[j][i+1] == '+')
                {
                    ft_printf("errore coglione");
                    return(0);
                }
            }
            i++;
        }
    }
    return (1);
}

char *e_str(char **contr)
{
    int i;
    int j;
    
    j = 1;
    while(contr[j])
    {
        i = 0;
        while(contr[j][i])
        {
            else if(contr[j][i] == " ")
            {
                return(contr[j]);
            }
            i++;
        }
    }
    return (0);
}

int counter(char **numeri)
{
    int j;
    int count;

    j = 0;
    count = 0;
    while(numeri[j])
    {
        if(!e_str(numeri[j]))
            count++;
        else
        {
            while (numeri[j][i] && numeri[j][i] == " ")
            {
                
                count++;
            }
        }
    }
}

int prova(char **test)
{
    int counter;
    int *a;
    
    counter = 0;
    if(s_nbr(test))
    {
        
        a = malloc(counter - 1);
        counter = 1;
        while(test[counter])
        {
            a[counter - 1] = ft_atoi(test[counter]);
            counter++;
        }
        counter = 0;
    }
}

int main(int argc, char **argv)
{
    int i;
    
    i = prova(argv);
    return(0);
}