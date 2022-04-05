/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse1Bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:56:31 by frudello          #+#    #+#             */
/*   Updated: 2022/04/05 17:29:47 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswapbonus.h"

void	ra(t_bonus *bonus, int def)
{
	int	temp;
	int	i;

	i = 0;
	temp = bonus->a[0];
	while (i < bonus->size_a -1)
	{
		bonus->a[i] = bonus->a[i + 1];
		i++;
	}
	bonus->a[i] = temp;
	if (def == 1)
		write(1, "ra\n", 3);
}

void	rb(t_bonus *bonus, int def)
{
	int	temp;
	int	i;

	i = 0;
	temp = bonus->b[0];
	while (i < bonus->size_b - 1)
	{
		bonus->b[i] = bonus->b[i + 1];
		i++;
	}
	bonus->b[i] = temp;
	if (def == 1)
		write(1, "rb\n", 3);
}

void	rra(t_bonus *bonus, int def)
{
	int	temp;
	int	i;

	i = bonus->size_a - 1;
	temp = bonus->a[i];
	while (i > 0)
	{
		bonus->a[i] = bonus->a[i - 1];
		i--;
	}
	bonus->a[0] = temp;
	if (def == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_bonus *bonus, int def)
{
	int	temp;
	int	i;

	i = bonus->size_b - 1;
	temp = bonus->b[i];
	while (i > 0)
	{
		bonus->b[i] = bonus->b[i - 1];
		i--;
	}
	bonus->b[0] = temp;
	if (def == 1)
		write(1, "rrb\n", 4);
}
