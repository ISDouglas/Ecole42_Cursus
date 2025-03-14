/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:36:53 by layang            #+#    #+#             */
/*   Updated: 2025/03/11 11:31:00 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	str_len(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_w(char	*s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' 
			&& (s[i + 1] == ' ' || s[i + 1] == '\t' || s[i + 1] == '\0'))
				j++;
		i++;
	}
	return (j);
}

char	*put_word(char	*str, int	i)
{
	int		start;
	int		len;
	char	*w;
	int		j;
	
	start = i;
	len = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	len = i - start;
	w = malloc(len + 1);
	if (!w)
		return (NULL);
	j = 0;
	while (j < len)
		w[j++] = str[start++];
	w[j] = '\0';
	return (w);
}

char	**ft_split(char	*str)
{
	int		words;
	int		i;
	char	**ws;
	int		nb;

	words = count_w(str);
	ws = malloc(sizeof(char *) * (words + 1));
	if (!ws)
		return (NULL);
	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			ws[nb] = put_word(str, i);
			i = i + str_len(ws[nb]) - 1;
			nb++;
		}
		i++;
	}
	ws[nb] = 0;
	return (ws);
}

/* char	**ft_split(char	*str)
{
	int		i;
	int		j;
	int		nb;
	char	**ws;
	
	ws = malloc(sizeof(char *) * 100);
	if (!ws)
		return (NULL);
	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			ws[nb] = malloc(sizeof(char) * 100);
			if (!ws[nb])
				return (NULL);
			j = 0;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
				ws[nb][j++] = str[i++];
			ws[nb][j] = '\0';
			nb++;
		}
		else
			i++;
	}
	ws[nb] = NULL;
	return (ws);
} */

int	main(int	ac, char	**av)
{
	char	**split;
	int		i;

	if (ac > 1)
	{
		split = ft_split(av[1]);
		i = 1;
		while (split[i])
		{
			write(1, split[i], str_len(split[i]));
			write(1, " ", 1);
			i++;
		}
		write(1, split[0], str_len(split[0]));
	}
	write(1, "\n", 1);
	return (0);
}
