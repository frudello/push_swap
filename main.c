

static int	ft_is_charset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	ft_wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_charset(str[i], charset) == 0)
		i++;
	return (i);
}

static int	ft_wordcount(char *str, char *charset)
{
	int		i;
	int		j;
		
	j = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, charset) == 1)
			str++;
		i = ft_wordlen(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

int main (int ac, char **av)
{
    
    int i = 0;
    int count = 0;
    while (av[i])
    {
        int result = ft_wordcount(av[i], " ");
        count += result;
        i++;
    }

    printf("il numero di argomenti é %d\n", count);
    return 0;

    
}