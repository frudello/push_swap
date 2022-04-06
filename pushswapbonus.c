/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapbonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:23:59 by frudello          #+#    #+#             */
/*   Updated: 2022/04/06 00:31:06 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswapbonus.h"

void	parsing_argument(t_bonus *bonus, char **argv, int argc)
{
	int	i;

	i = 1;
	bonus->count = 0;
	s_nbr(argv);
	while (i < argc)
	{
		if (has_space(argv[i]))
			bonus->count += ft_wordcount(argv[i], " ");
		else
			bonus->count++;
		i++;
	}
	parsing_argument_help(bonus, argv, argc);
}

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

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*sm1;
	unsigned char	*sm2;
	size_t			i;

	i = 0;
	sm1 = (unsigned char *)s1;
	sm2 = (unsigned char *)s2;
	while (sm1[i] == sm2[i] && sm1[i] && sm2[i])
	{
		i++;
	}
	if (sm2[i] < sm1[i])
		return (1);
	else if (sm2[i] == sm1[i])
		return (0);
	else
		return (-1);
}

void	ordinato(t_bonus *bonus)
{
	int	i;

	i = 1;
	while (i < bonus->size_a && bonus->a[i - 1] < bonus->a[i])
		i++;
	if (i == bonus->size_a)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		i;
	t_bonus	bonus;

	i = -1;
	parsing_argument(&bonus, av, ac);
	while (ft_read(&bonus, 0) == 1)
	{
		which_move(&bonus, bonus.line);
		free(bonus.line);
	}
	ordinato(&bonus);
	free(bonus.a);
	free(bonus.b);
}
