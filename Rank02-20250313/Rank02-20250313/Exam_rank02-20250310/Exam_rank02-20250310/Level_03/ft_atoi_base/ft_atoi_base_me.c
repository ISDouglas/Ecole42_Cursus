/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_me.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:15:51 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 19:06:58 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
    int sign;
    int nb;
    int i;

    if (str_base <= 16 && str_base > 1)
	{
		i = 0;
		sign = 1;
		nb = 0;
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		while ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'a' && str[i] <= 'f')
				|| (str[i] >= 'A' && str[i] <= 'F'))
		{
			nb = nb * str_base;
			if (str[i] >= '0' && str[i] <= '9')
				nb += str[i] - 48;
			else if (str[i] >= 'a' && str[i] <= 'f')
				nb += str[i] - 87;
			else if (str[i] >= 'A' && str[i] <= 'F')
				nb += str[i] - 55;
			i++;
		}
		return (sign * nb);
	}
	return (0);
}

/* static int	return_i(char n, int base)
{
	char	*b_str;
	int		i;

	b_str = "0123456789abcdef";
	i = 0;
	if (n >= 'A' && n <= 'Z') // 转小写
		n = n + 32;
	while (i < base)
	{
		if (n == b_str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	sign;
	int	nb;
	int	i;
	int	num;

	if (str_base <= 16 && str_base > 1)
	{
		i = 0;
		sign = 1;
		nb = 0;
		// 跳过空格
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		// 处理符号
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		// 转换数字
		while ((num = return_i(str[i], str_base)) != -1)
		{
			nb = nb * str_base + num;
			i++;
		}
		return (sign * nb);
	}
	return (0);
}
 */
