/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:25 by layang            #+#    #+#             */
/*   Updated: 2025/05/17 16:24:17 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// 在主进程
int	monitor_death(t_table	*tab, pid_t	*pids)
{
	int	status;
	pid_t	pid;

	pid = waitpid(-1, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
	{
		kill_all_philos(data);
	}
}
int	monitor_eat(t_table	*tab)
{
	int	i;
    
    i = 0;
	while (i < tab->nb_eat * tab->nb_phi && tab->nodead)
	{
		sem_wait(tab->eat_counter);
		i++;
		if (i == tab->nb_eat)
			free_all(tab);
	}
    return (NULL);
}

void philosopher(int id)
{
    while (1)
    {
        sem_wait(print_lock);
        printf("哲学家 %d 正在思考\n", id);
        sem_post(print_lock);

        sleep(1);

        sem_wait(forks);
        sem_wait(forks);

        sem_wait(print_lock);
        printf("哲学家 %d 正在吃饭\n", id);
        sem_post(print_lock);

        sleep(2);

        sem_post(forks);
        sem_post(forks);

        sem_wait(print_lock);
        printf("哲学家 %d 放下叉子\n", id);
        sem_post(print_lock);

        sleep(1);
	}
	kill_all_philos(data);
}

/* int main()
{
    pid_t pids[PHI_NUM];
    int i;

    // 创建/打开命名信号量
    forks = sem_open("/forks_sema", O_CREAT, 0644, PHI_NUM);
    print_lock = sem_open("/print_sema", O_CREAT, 0644, 1);

    if (forks == SEM_FAILED || print_lock == SEM_FAILED)
    {
        perror("sem_open 失败");
        exit(1);
    }

    // 创建哲学家进程
    for (i = 0; i < PHI_NUM; i++)
    {
        pids[i] = fork();
        if (pids[i] == 0)
        {
            philosopher(i + 1);
            exit(0);
        }
    }

    // 等待所有哲学家进程结束（这里没有主动退出逻辑，示例中按 Ctrl+C 退出）
    for (i = 0; i < PHI_NUM; i++)
        wait(NULL);

    // 关闭并删除信号量
    sem_close(forks);
    sem_unlink("/forks_sema");
    sem_close(print_lock);
    sem_unlink("/print_sema");

    return 0;
}
 */

 int    fork_eat_monitor(t_table    *tab)
 {
	pid_t	monitor;

	monitor = fork();
	if (monitor == 0)
	{
		if (monitor_eat(tab))
			exit(0);
	}
}
