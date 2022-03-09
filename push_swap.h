/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello < frudello@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:02:10 by frudello          #+#    #+#             */
/*   Updated: 2022/03/09 19:16:23 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		count;
	int		size_a;
	int		size_b;
	char	**temp;
}			t_stack;

char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
int	ft_wordcount(char *str, char *charset);

#endif
