/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:03:35 by layang            #+#    #+#             */
/*   Updated: 2025/01/18 14:56:06 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* static char **free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int ft_count_words(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char *ft_putword(char *word, char const *s, int i, int word_len)
{
	int j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char **split_words(char const *s, char c, char **s2, int num)
{
	int i;
	int word;
	int word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2[word])
			return (free_array(s2, word));
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char **ft_split(char const *s, char c)
{
	char **s2;
	unsigned int num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	s2 = split_words(s, c, s2, num_words);
	return (s2);
} */

int ft_atoi_ctl(const char *str)
{
	int sign;
	long num;
	int i;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > (2147483647 - (str[i] - '0')) / 10)
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

static int check_repeat(char **av, int nb)
{
	int i;
	int j;

	i = 0;
	while (i < nb)
	{
		j = i + 1;
		while (j < nb)
		{
			if (ft_atoi_ctl(av[i]) == ft_atoi_ctl(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	//write(1, "Ok\n", 3);
	return (0);
}

void	push_swap(char	**av,int nb)
{
	t_stack	*tab;

	tab = NULL;
	tab->a = put_a(av);
	if (tab->a == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	tab->b = NULL;
	tab->size_a = nb;
	tab->size_a = ft_lstsize(tab->b);
	if (is_sorted(&tab->a))
	{
		free_stacks(&tab);
		return ;
	}
	index_a(tab->a, tab->size_a);
	if (nb == 2 || nb == 3)
		sort_2_or_3_nbr(tab, nb);
	else if (nb == 5)
		sort_5_nbr(tab, nb);
	else
		quick_sort(&tab->a, &tab->b, nb);
	free_stacks(&tab);
}

int main(int ac, char **av)
{
	int	nb;

	nb = 0;
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			av = ft_split(*av, ' ');
		}
		nb = 0;
		while (av[nb])
		{
			if (ft_atoi_ctl(av[nb]) == 0 && av[nb][0] != '0')
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			nb++;
		}
	}
	if (check_repeat(av, nb))
		ft_putstr_fd("Error\n", 2);
	else
		push_swap(av, nb);
	return (0);
}
/*
//write(1, "Ok\n", 3);

for test:
cc main.c
cc main.c 01_ft_printf/ft_printf.c 01_ft_printf/ft_put_num.c \
01_ft_printf/ft_put_ptr.c 01_ft_printf/ft_put_str.c

./a.out 06 0 -9
./a.out 06 0 2147483648    $Error

check: one number, doubles
 */
