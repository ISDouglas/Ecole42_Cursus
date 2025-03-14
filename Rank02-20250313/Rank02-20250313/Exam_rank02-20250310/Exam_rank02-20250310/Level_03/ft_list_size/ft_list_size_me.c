/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size_me.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:37:42 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 19:40:33 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_list.h"

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
    t_list  *cur;
    int     i;

    cur = begin_list;
    i = 0;
    while (cur)
    {
        i++;
        cur = cur->next;
    }
    return (i);
}
