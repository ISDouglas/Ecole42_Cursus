/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:53:20 by layang            #+#    #+#             */
/*   Updated: 2025/05/19 08:32:51 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

void	philo_pass_time(t_table	*tab, time_t	delay)
{
	time_t	wait_until;

	wait_until = ft_get_time() + delay;
	while (ft_get_time() < wait_until)
	{
		if (stop_arrived(tab))
			break ;
		usleep(100);
	}
}

void	print_action(t_philo *philo, char *message)
{
	char	buffer[128];
	char	*time_str;
	int		len;

	sem_wait(philo->sems->print_sem);
	time_str = ft_ltoa(get_timestamp()); // 把 long 转成字符串
	ft_strcpy(buffer, "[");
	ft_strcat(buffer, time_str);
	ft_strcat(buffer, "] ");
	ft_strcat(buffer, ft_itoa(philo->id));
	ft_strcat(buffer, " ");
	ft_strcat(buffer, message);
	ft_strcat(buffer, "\n");
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(time_str);
	sem_post(philo->sems->print_sem);
}

void print_action(t_philo *philo, char *message)
{
	long	timestamp;

	timestamp = get_time_since_start(); // 例如毫秒数
	sem_wait(philo->sems->print_sem);
	printf("[%ld] %d %s\n", timestamp, philo->id, message);
	sem_post(philo->sems->print_sem);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	len = ft_strlen(s);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_utoa(unsigned int n)
{
	char	tmp[12];
	int		i;
	int		j;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	while (n > 0)
	{
		tmp[i++] = (n % 10) + '0';
		n /= 10;
	}
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	res[i] = '\0';
	j = 0;
	while (i-- > 0)
		res[j++] = tmp[i];
	return (res);
}
/* 
void	set_sem_name(char *dest, const char *prefix, unsigned int id)
{
	unsigned int	i;
	char			id_str[12]; // 足够容纳32位无符号整型的字符串

	i = 0;
	while (prefix[i])
	{
		dest[i] = prefix[i];
		i++;
	}
	dest[i] = '\0';
	ft_utoa_into(id, id_str); // 你需要实现这个函数，把id转成字符串存进id_str
	ft_strcat(dest, id_str);
} */

/* 

set_sem_name(name, "/die_sem_", id);
sem_t *sem = sem_open(name, O_CREAT, 0644, 1); */

char	*strjoin_free(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		dest[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2))
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	free((void *)s2);
	return (dest);
}
