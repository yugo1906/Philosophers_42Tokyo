/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:15:15 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/24 09:25:37 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// todo: テストコード_課題提出前に削除
void	test_philo(t_philo_env *p_env);
// ### memo
// 1st arg : number of philosophers
// 2nd arg : time to die
// 3rd arg : time to eat
// 4th arg : time to sleep
// 5th arg : [number_of_times_each_philosopher_must_eat]

// todo: メモリーリークテスト_課題提出前に削除
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q philo");
// }

int	main(int argc, char **argv)
{
	t_philo_env	p_env;

	if (is_validate_arg(argc, argv) == ERROR)
		return (put_error_end_exit("Invalid argument."));
	if (init_philo_env(argc, argv, &p_env) == ERROR)
		return (put_error_end_exit("Failed to initialize philo_env."));
	init_philosophers(&p_env);
	if (create_philo_thread(&p_env) == ERROR)
		return (EXIT_FAILURE);
	if (create_monitor_thread(&p_env) == ERROR)
		return (put_error_end_exit("Failed to create monitor_thread."));
	// test_philo(&p_env);
	free(p_env.philo);
	free(p_env.fork);
	// todo: テスト実行関数_課題提出前に削除
	return (EXIT_SUCCESS);
}

// todo: テストコード_課題提出前に削除

void	test_put_philo(t_philo_env *p_env);
void	*start_routine(void *arg);
void	test_pthread_create(void);

void	test_philo(t_philo_env *p_env)
{
	struct timeval	time;
	unsigned long	tmp_time;

	gettimeofday(&time, NULL);
	tmp_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%lu\n", tmp_time);
	// test_put_philo(p_env);
	// test_pthread_create();
}

void	test_put_philo(t_philo_env *p_env)
{
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		printf("philo[%d]: %d\n", i, p_env->philo[i].id);
		i++;
	}
}

void	*start_routine(void *arg)
{
	(void)arg;
	printf("New thread created!\n");
	pthread_exit(NULL);
}

void	test_pthread_create(void)
{
	pthread_t	thread;
	int			ret;

	ret = pthread_create(&thread, NULL, start_routine, NULL);
	if (ret != 0)
	{
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	// pthread_join(thread, NULL);
	pthread_detach(thread);
}
