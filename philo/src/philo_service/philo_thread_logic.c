/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_logic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:42:49 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/15 09:45:13 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philo_take_fork(t_philo *philo)
{
	static int	i = 0;

	pthread_mutex_lock(&philo->p_env->fork[philo->right_fork_id]);
	usleep(100000);
	put_philo_log(philo, "has taken a right_fork");
	pthread_mutex_unlock(&philo->p_env->fork[philo->right_fork_id]);
	pthread_mutex_lock(&philo->p_env->fork[philo->left_fork_id]);
	put_philo_log(philo, "has taken a left_fork");
	pthread_mutex_unlock(&philo->p_env->fork[philo->left_fork_id]);
	i++;
	printf("i = %d\n", i);
	return (i);
}

static void	*philo_routine(void *a_philosopher)
{
	t_philo	*philo;
	int		end_flag;

	end_flag = 0;
	philo = (t_philo *)a_philosopher;
	while (1)
	{
		end_flag = philo_take_fork(philo);
		if (end_flag == 10 || end_flag == 20)
		{
			printf("きた?\n");
			break ;
		}
	}
	return (NULL);
}

bool	create_philo_thread(t_philo_env *p_env)
{
	pthread_t		thread[p_env->num_of_philo];
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_create(&thread[i], NULL, philo_routine,
				&p_env->philo[i]) != 0)
			return (put_error_and_all_free_exit(p_env, "philo_create_thread."));
		i++;
	}
	i = 0;
	while (i < p_env->num_of_philo)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	return (NOT_ERROR);
}
