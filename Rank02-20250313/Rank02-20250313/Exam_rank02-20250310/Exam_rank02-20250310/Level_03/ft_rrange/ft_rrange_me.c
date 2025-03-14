/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange_me.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:46:08 by layang            #+#    #+#             */
/*   Updated: 2025/01/03 10:48:04 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_rrange(int start, int end)
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
            range[i++] = end--;
        else
            range[i++] = end++;
    }
    range[i] = end;
    return (range);
}

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *range;
    int size;
    int i;

    // 计算数组大小，包含 start 和 end
    if (end >= start)
        size = end - start + 1;
    else
        size = start - end + 1;

    // 分配内存
    range = (int *)malloc(sizeof(int) * size);
    if (!range)
        return (NULL);

    // 填充数组，从 end 到 start
    i = 0;
    while (end != start)
    {
        range[i++] = end;
        if (end > start)
            end--;
        else
            end++;
    }
    range[i] = end; // 包含最后一个值（start）

    return (range);
}

