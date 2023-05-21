/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:42:49 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/22 08:47:58 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *a_philosopher)
{
	t_philo		*philo;
	t_philo_env	*p_env;

	philo = (t_philo *)a_philosopher;
	p_env = philo->p_env;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (1)
	{
		if (take_right_fork_philo(philo, p_env) == PHILO_DEAD_OR_FINISH)
			break ;
		if (take_left_fork_philo(philo, p_env) == PHILO_DEAD_OR_FINISH)
			break ;
		if (eat_philo(philo, p_env) == PHILO_DEAD_OR_FINISH)
			break ;
		if (sleep_philo(philo, p_env) == PHILO_DEAD_OR_FINISH)
			break ;
		if (think_philo(philo, p_env) == PHILO_DEAD_OR_FINISH)
			break ;
	}
	return (NULL);
}

bool	create_philo_thread(t_philo_env *p_env)
{
	pthread_t		tid[p_env->num_of_philo];
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_create(&tid[i], NULL, philo_routine, &p_env->philo[i]) != 0)
			return (put_error_and_all_free_exit(p_env, "philo_create_thread."));
		i++;
	}
	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_join(tid[i], NULL) != 0)
			return (put_error_and_all_free_exit(p_env, "philo_join_thread."));
		i++;
	}
	return (NOT_ERROR);
}

// void	*monitor_routine(void *arg_p_env)
// {
// 	struct timeval	tv_now;
// 	t_philo_env		*p_env;

// 	p_env = (t_philo_env *)arg_p_env;
// 	while (1)
// 	{
// 		gettimeofday(&tv_now, NULL);
// 		if (p_env->is_dead == true)
// 			break ;
// 	}
// 	return (NULL);
// }

// bool	create_monitor_thread(pthread_t *monitor_tid, t_philo_env *p_env)
// {
// 	if (pthread_create(monitor_tid, NULL, monitor_routine, p_env) != 0)
// 		return (ERROR);
// 	return (NOT_ERROR);
// }
