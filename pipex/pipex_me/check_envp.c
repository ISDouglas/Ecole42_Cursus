/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:20:41 by layang            #+#    #+#             */
/*   Updated: 2025/02/02 12:27:38 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

/* int main(int argc, char **argv, char **envp)
{
    int i = 0;
    while (envp[i]) // 遍历环境变量
    {
        printf("%s\n", envp[i]);
        i++;
    }
    return 0;
} */

int main(void)
{
    char *path = getenv("PATH");
    if (path)
    {
        write(1, path, 0);
        write(1, "\n", 1);
    }
    return (0);
}

/* $ ./a.out
PWD=/home/user
USER=user
SHELL=/bin/bash
PATH=/usr/bin:/bin:/usr/sbin:/sbin
...
 */