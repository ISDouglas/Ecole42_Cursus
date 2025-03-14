/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm_me_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:26:47 by layang            #+#    #+#             */
/*   Updated: 2025/03/12 21:17:57 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	gcd;
	unsigned int	oa;
	unsigned int	ob;

	gcd = 0;
	oa = a;
	ob = b;
	while (1)
	{
		if (a == 0)
			break ;
		b %= a;
		if (b == 0)
			break ;
		a %= b;
	}
	if (b == 0)
		gcd = a;
	else
		gcd = b;
	if (gcd != 0)
		return (oa / gcd * ob);
	else
		return (0);
}
//cc -Werror -Wall -Wextra