/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:23:03 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 12:38:22 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char	*str)
{
	int		i;
	int		end;
	char	tmp;

	end = 0;
	while (str[end])
		end++;
	end--;
	i = 0;
	while (i < end)
	{
		tmp = str[i];
		str[i] = str[end];
		str[end] = tmp;
		i++;
		end--;
	}
	return (str);
}
