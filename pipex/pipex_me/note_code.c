/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:15:14 by layang            #+#    #+#             */
/*   Updated: 2025/02/03 17:15:40 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* void	exec_cmd(char *cmd, char **envp)
{
	char *args[] = {"/bin/sh", "-c", cmd, NULL};
	execve("/bin/sh", args, envp);
	perror("execve");
	exit(1);
} */

void exec_cmd(char *cmd, char **envp)
{
	char *args[] = {"/bin/sh", "-c", cmd, NULL};
	execve("/bin/sh", args, envp);
	perror("execve");
	exit(1);
}

void	child_process(int infile, int pipefd[2], char *cmd, char **envp)
{
	dup2(infile, STDIN_FILENO);   // 标准输入重定向到 infile
	dup2(pipefd[1], STDOUT_FILENO); // 标准输出重定向到管道写端
	close(pipefd[0]); // 关闭管道读端
	exec_cmd(cmd, envp);
}

void	parent_process(int outfile, int pipefd[2], char *cmd, char **envp)
{
	dup2(pipefd[0], STDIN_FILENO); // 标准输入重定向到管道读端
	dup2(outfile, STDOUT_FILENO); // 标准输出重定向到 outfile
	close(pipefd[1]); // 关闭管道写端
	exec_cmd(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		fprintf(stderr, "Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return (1);
	}

	int infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror("open infile");
		return (1);
	}

	int outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("open outfile");
		close(infile);
		return (1);
	}

	int pipefd[2];
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		close(infile);
		close(outfile);
		return (1);
	}

	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(infile);
		close(outfile);
		return (1);
	}

	if (pid == 0) // 子进程
	{
		child_process(infile, pipefd, argv[2], envp);
	}
	else // 父进程
	{
		wait(NULL); // 等待子进程完成
		parent_process(outfile, pipefd, argv[3], envp);
	}

	close(infile);
	close(outfile);
	return (0);
}

/*
< input.txt ls -l | wc -l > output.txt
*/