/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_knowledge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:20:41 by layang            #+#    #+#             */
/*   Updated: 2025/02/03 17:36:41 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>

// *********************         ******************************
/* *********************check env******************************
// *********************         ******************************
int main(int argc, char **argv, char **envp)
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
    int i = 0;

    if (path)
    {
        while (path[i])
            i++;
        write(1, path, i);
        write(1, "\n", 1);
    }
    return (0);
}

/*
by command:
env
printenv
 */

// *********************         ******************************
// *********************test fork******************************
// *********************         ******************************
/*
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t i, j;

    i = fork(); // 第一次 fork()
    j = fork(); // 第二次 fork()

    if (i > 0 && j > 0)
    {
        printf("P1: 父进程 (PID=%d, i=%d, j=%d)\n", getpid(), i, j);
    }
    else if (i == 0 && j > 0)
    {
        printf("C1: 第一个子进程 (PID=%d, 父PID=%d, i=%d, j=%d)\n", getpid(), getppid(), i, j);
    }
    else if (i > 0 && j == 0)
    {
        printf("P2: 第二个子进程 (PID=%d, 父PID=%d, i=%d, j=%d)\n", getpid(), getppid(), i, j);
    }
    else if (i == 0 && j == 0)
    {
        printf("C2: 第二个子进程的子进程 (PID=%d, 父PID=%d, i=%d, j=%d)\n", getpid(), getppid(), i, j);
    }

    return 0;
} */

/* 
假设初始进程（父进程）是 P：

    i = fork();
第一次 fork()

    产生 两个进程：
    父进程（P1）
    子进程（C1）
    j = fork();
第二次 fork()

    在 P1 运行时，它会创建一个新进程 P2。
    在 C1 运行时，它也会创建一个新进程 C2。
    现在共有 4 个进程：P1、P2、C1、C2。 
*/