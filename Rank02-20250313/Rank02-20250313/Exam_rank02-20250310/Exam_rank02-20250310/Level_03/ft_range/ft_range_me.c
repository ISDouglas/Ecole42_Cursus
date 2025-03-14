/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:33:59 by layang            #+#    #+#             */
/*   Updated: 2025/01/03 10:45:09 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *range;
    int size;
    int i;

    if (end >= start)
        size = end - start + 1;
    else
        size = start - end + 1;
    range = (int *)malloc(sizeof(int) * size);
    if (!range)
        return (NULL);
    i = 0;
    while (start != end)
    {
        if (end > start)
            range[i++] = start++;
        else
            range[i++] = start--;
    }
    range[i] = start;
    return (range);
}
