/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm_me.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:13:59 by layang            #+#    #+#             */
/*   Updated: 2025/03/12 20:23:16 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int lcm(unsigned int a, unsigned int b)
{
	int	gcd;
	int	oa;
	int	ob;

	gcd = 0;
	oa = a;
	ob = b;
	while (1)
	{
		if (a == 0)
			break;
		b %= a;
		if (b == 0)
			break;
		a %= b;
	}
	if (b == 0)
		gcd = a;
	if (gcd != 0)
		return (oa / gcd * ob);
	else
		return (0);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int gcd;
    unsigned int oa;
    unsigned int ob;

    if (a == 0 || b == 0)
        return (0);

    oa = a;
    ob = b;
	// 确保 a 大于或等于 b计算 GCD
    // 使用辗转相除法
    while (b != 0)
    {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;

    // 计算 LCM
    return (oa / gcd * ob);
}
