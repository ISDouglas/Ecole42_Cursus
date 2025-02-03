/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_multi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:21:05 by layang            #+#    #+#             */
/*   Updated: 2025/02/02 11:41:57 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int a[2], b[2];
    pid_t pid;

    pipe(a); // 父进程到子进程的管道
    pipe(b); // 子进程到父进程的管道

    pid = fork();

    if (pid == 0) // 子进程
    {
        char buffer[128];

        close(a[1]); // 关闭写入端
        close(b[0]); // 关闭读取端

        read(a[0], buffer, sizeof(buffer)); // 从父进程读取
        printf("Child received: %s\n", buffer);

        const char *reply = "Hello, parent!";
        write(b[1], reply, strlen(reply) + 1); // 写回父进程

        close(a[0]);
        close(b[1]);
    }
    else // 父进程
    {
        char buffer[128];

        close(a[0]); // 关闭读取端
        close(b[1]); // 关闭写入端

        const char *message = "Hello, child!";
        write(a[1], message, strlen(message) + 1); // 写入子进程

        read(b[0], buffer, sizeof(buffer)); // 从子进程读取
        printf("Parent received: %s\n", buffer);

        close(a[1]);
        close(b[0]);
    }

    return (0);
}
/*
$ gcc -Wall -Wextra -Werror -o pipe pipe.c
$ ./pipe
Child received: Hello, child!
Parent received: Hello, parent!

*/
