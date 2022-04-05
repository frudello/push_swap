/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosseBonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:35:58 by frudello          #+#    #+#             */
/*   Updated: 2022/04/05 17:27:03 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswapbonus.h"

void	swap_a(t_bonus *bonus)
{
	int	temp;

	temp = bonus->a[0];
	bonus->a[0] = bonus->a[1];
	bonus->a[1] = temp;
}

void	swap_b(t_bonus *bonus)
{
	int	temp;

	temp = bonus->b[0];
	bonus->b[0] = bonus->b[1];
	bonus->b[1] = temp;
}

void	push_a(t_bonus *bonus)
{
	int	i;

	i = bonus->size_a;
	while (i > 0)
	{
		bonus->a[i] = bonus->a[i - 1];
		i--;
	}
	bonus->size_a++;
	bonus->a[0] = bonus->b[0];
	i = 0;
	while (i + 1 < bonus->size_b)
	{
		bonus->b[i] = bonus->b[i + 1];
		i++;
	}
	bonus->size_b--;
}

void	push_b(t_bonus *bonus)
{
	int	i;

	i = bonus->size_b;
	while (i > 0)
	{
		bonus->b[i] = bonus->b[i - 1];
		i--;
	}
	bonus->size_b++;
	bonus->b[0] = bonus->a[0];
	i = 0;
	while (i + 1 < bonus->size_a)
	{
		bonus->a[i] = bonus->a[i + 1];
		i++;
	}
	bonus->size_a--;
}
