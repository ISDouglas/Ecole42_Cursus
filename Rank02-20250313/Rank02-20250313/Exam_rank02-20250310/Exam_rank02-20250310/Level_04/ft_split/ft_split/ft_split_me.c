/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:41:57 by layang            #+#    #+#             */
/*   Updated: 2025/03/14 13:27:23 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/* int	count_words(char	*str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] != ' ' || str[i] != '\t' || str[i] != '\n'))
			j++;
		if (str[i-1] && (str[i-1] == ' ' || str[i-1] == '\t' ||
			str[i-1] == '\n') && (str[i] != ' ' || str[i] != '\t' 
				|| str[i] != '\n'))
			j++;
		i++;
	}
	return (j);
} */

int	count_words(char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			&& (str[i + 1] == '\0' || str[i + 1] == ' ' || str[i + 1] == '\t'
				|| str[i + 1] == '\n'))
				j++;
		i++;
	}
	return (j);
}

int	ft_strlen(char	*str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*write_word(char	*str, int i)
{
	int		start;
	int		len;
	char	*word;
	int		sit;
	
	start = i;
	while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		i++;
	len = i - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	sit = 0;
	while (sit < len)
		word[sit++] = str[start++];
	word[len] = '\0';
	return (word);
}

char	**ft_split(char	*str)
{
	int		i;
	char	**strs;
	int		nb;

	nb = count_words(str);
	strs = malloc(sizeof(char *) * (nb + 1));
	if (!strs)
		return (NULL);
	i = 0;
	nb = 0;
	while (i < ft_strlen(str))
	{	
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			strs[nb] = write_word(str, i);
			i = i + ft_strlen(strs[nb]) - 1;
			nb++;
		}
		i++;
	}
	strs[nb] = NULL;
	return (strs);
}

// start, ' ', '\t', '\n'



/* int	main(int ac, char	**av)
{
	int		re;

	if (ac == 1 || ac != 2)
	{
		printf("Put 1 string as parameters\n");
		return (0);
	}
	re = count_words(av[1]);
	printf("word nbr = %d\n", re);
	return (0);
} */


// ./a.out ":a:..dfh df-gg" ". " | cat -e
// cc -Werror -Wall -Wextra