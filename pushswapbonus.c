/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapbonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:23:59 by frudello          #+#    #+#             */
/*   Updated: 2022/04/02 19:24:41 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswapbonus.h"

char	*ft_read(int fd)
{
	char		save[999999];
	char		buff[1];
	char		*line;
	int			i = 0;

	if (fd < 0)
		return (0);
	save[i] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if(save[i] == '\n')
			break;
		i++;
	}
	if (save[0] == '\0')
		return (0);
	line = malloc(i + 1);
	if (!line)
		return(0);
	i = 0;
	while(save[i])
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
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
	bonus->size_a = bonus->count;
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

int	main(int ac, char **av)
{
	int i;
	t_bonus bonus;

	i = -1;
	while (++i < ac)
	{
		printf("%s", ft_read(0));
	}
	parsing_argument(&bonus, av, ac);
	for(int e = 0; e < bonus.size_a; e++)
		printf("%i", bonus.a[e]);
}
