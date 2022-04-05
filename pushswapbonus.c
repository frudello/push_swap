/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapbonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:23:59 by frudello          #+#    #+#             */
/*   Updated: 2022/04/06 00:03:13 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswapbonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

int	ft_read(t_bonus *bonus, int fd)
{
	char		save[999999];
	char		buff[1];
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
	bonus->line = malloc(i + 1);
	if (!bonus->line)
		return(0);
	i = 0;
	while(save[i])
	{
		bonus->line[i] = save[i];
		i++;
	}
	bonus->line[i] = '\0';
	return (1);
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
	{
		ft_putstr_fd("entro nel primo if\n", 1);
		return (1);
	}
	else if (sm2[i] == sm1[i])
	{
		ft_putstr_fd("entro nel primo if\n", 1);
		return (0);
	}
	else
	{
		ft_putstr_fd("entro nel primo if\n", 1);
		return (-1);
	}
}

void	which_move(t_bonus *bonus, char *s)
{
	if (strcmp(s, "ra\n") == 0)
		ra(bonus, -1);
	else if (strcmp(s, "rb\n") == 0)
		rb(bonus, -1);
	else if (strcmp(s, "pa\n") == 0)
		push_a(bonus);
	else if (strcmp(s, "pb\n") == 0)
		push_b(bonus);
	else if (strcmp(s, "rra\n") == 0)
		rra(bonus, -1);
	else if (strcmp(s, "rrb\n") == 0)
		rrb(bonus, -1);
	else if (strcmp(s, "sa\n") == 0)
		swap_a(bonus);
	else if (strcmp(s, "sb\n") == 0)
		swap_b(bonus);
	else if (strcmp(s, "ss\n") == 0)
		swap(bonus);
	else if (strcmp(s, "rr\n") == 0)
		rr(bonus);
	else if (strcmp(s, "rrr\n") == 0)
		rrr(bonus);
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	ordinato(t_bonus *bonus)
{
	int	i;

	i = 1;
	while (i < bonus->size_a && bonus->a[i - 1] < bonus->a[i])
		i++;
	// printf("la I é: %i\n", i);
	// printf("la SIZE_A é: %i\n", bonus->size_a);
	if (i == bonus->size_a)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int i;
	t_bonus bonus;

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
