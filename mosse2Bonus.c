/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosse2Bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:59:11 by frudello          #+#    #+#             */
/*   Updated: 2022/04/05 18:53:25 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswapbonus.h"

void	swap(t_bonus *bonus)
{
	int	temp;

	temp = bonus->a[0];
	bonus->a[0] = bonus->a[1];
	bonus->a[1] = temp;
	temp = bonus->b[0];
	bonus->b[0] = bonus->b[1];
	bonus->b[1] = temp;
}

void	rr(t_bonus *bonus)
{
	ra(bonus, -1);
	rb(bonus, -1);
}

void	rrr(t_bonus *bonus)
{
	rra(bonus, -1);
	rrb(bonus, -1);
}
