/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:14:00 by frudello          #+#    #+#             */
/*   Updated: 2022/04/06 00:38:16 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswapbonus.h"

int	ft_read(t_bonus *bonus, int fd)
{
	char		save[999999];
	char		buff[1];
	int			i;

	i = 0;
	if (fd < 0)
		return (0);
	save[i] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (0);
	bonus->line = malloc(i + 1);
	if (!bonus->line)
		return (0);
	ft_read_helper(bonus, save);
	return (1);
}

void	ft_read_helper(t_bonus *bonus, char *save)
{
	int	i;

	i = 0;
	while (save[i])
	{
		bonus->line[i] = save[i];
		i++;
	}
	bonus->line[i] = '\0';
}

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

int	filler_helper(t_bonus *bonus, char *argv, int k)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(argv, ' ');
	while (split[i])
	{
		bonus->a[k] = ft_atoi(split[i]);
		free(split[i]);
		i++;
		k++;
	}
	free(split);
	return (k - 1);
}

void	parsing_argument_help(t_bonus *bonus, char **argv, int argc)
{
	int	i;
	int	k;

	bonus->a = malloc(bonus->count * sizeof(int));
	if (!bonus->a)
		exit(0);
	bonus->b = malloc(bonus->count * sizeof(int));
	if (!bonus->b)
		exit(0);
	bonus->size_a = bonus->count;
	bonus->size_b = 0;
	i = 1;
	k = 0;
	while (i < argc)
	{
		if (has_space(argv[i]))
			k = filler_helper(bonus, argv[i], k);
		else
			bonus->a[k] = ft_atoi(argv[i]);
		i++;
		k++;
	}
}
