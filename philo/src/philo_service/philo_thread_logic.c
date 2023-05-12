/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_logic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:42:49 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/13 05:12:49 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->p_env->fork[philo->right_fork_id]);
	put_philo_log(philo, "has taken a right_fork");
	pthread_mutex_unlock(&philo->p_env->fork[philo->right_fork_id]);
	pthread_mutex_lock(&philo->p_env->fork[philo->left_fork_id]);
	put_philo_log(philo, "has taken a left_fork");
	pthread_mutex_unlock(&philo->p_env->fork[philo->left_fork_id]);
}

static void	*philo_routine(void *a_philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)a_philosopher;
	philo_take_fork(philo);
	return (NULL);
}

bool	create_philo_thread(t_philo_env *p_env)
{
	pthread_t		thread;
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_create(&thread, NULL, philo_routine, &p_env->philo[i]) != 0)
			return (put_error_and_all_free_exit(p_env, "philo_create_thread."));
		usleep(500);
		if (pthread_detach(thread))
			return (put_error_and_all_free_exit(p_env, "philo_detach_thread."));
		i++;
	}
	return (NOT_ERROR);
}
