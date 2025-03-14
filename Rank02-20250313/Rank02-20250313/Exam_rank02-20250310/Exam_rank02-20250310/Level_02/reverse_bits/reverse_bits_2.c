/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:39:22 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 14:09:52 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* unsigned char	reverse_bits(unsigned char	octet)
{
	return(((octet >> 0) & 1) << 7) | (((octet >> 1) & 1) << 6)
		| (((octet >> 2) & 1) << 5) | (((octet >> 3) & 1) << 4)
		| (((octet >> 4) & 1) << 3) | (((octet >> 5) & 1) << 2)
		| (((octet >> 6) & 1) << 1) | (((octet >> 7) & 1) << 0);
} */

unsigned char	reverse_bits(unsigned char	octet)
{
	int	i;
	unsigned char	rev;

	i = 8;
	rev = 0;
	
	while (i > 0)
	{
		rev = rev * 2 + (octet % 2);
		octet /= 2;
		i--;
	}
	return(rev);
}
