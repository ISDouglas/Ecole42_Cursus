/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:04:14 by layang            #+#    #+#             */
/*   Updated: 2025/01/13 22:08:44 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./00_Libft/libft.h"
# include "./01_ft_printf/ft_printf.h"

typedef struct s_stack
{
	t_list *a;
	t_list *b;
	int size_a;
	int size_b;
} t_stack;

typedef struct s_push
{
	int next;
	int max;
	int mid;
	int flag;
} t_push;

void index(char **av, int nb);

# include <unistd.h>
# include <stdlib.h>

#endif