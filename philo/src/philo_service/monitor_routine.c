/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:01:14 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 21:36:40 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	create_monitor_thread(pthread_t *monitor_tid, t_philo_env *p_env)
{
	if (pthread_create(monitor_tid, NULL, monitor, p_env))
		return (put_error_philo_fork_free_exit(p_env, "monitor_thread."));
	return (NOT_ERROR);
}

void	*monitor(void *arg_p_env)
{
	t_philo_env		*p_env;
	unsigned long	usec;
	unsigned int	i;

	i = 0;
	p_env = (t_philo_env *)arg_p_env;
	usleep(p_env->t_t_die * MSEC_TO_USEC - USLEEP_ONE_MSEC);
	while (true)
	{
		usec = get_now_usec();
		while (i < p_env->num_of_philo)
		{
			if (is_check_finish(p_env))
				return (NULL);
			if (is_check_death(usec, p_env, i))
				return (NULL);
			i++;
		}
		i = 0;
		usleep(8000);
	}
}

bool	is_check_death(unsigned long usec, t_philo_env *p_env, unsigned int i)
{
	pthread_mutex_lock(&(p_env->mutex_meal_time));
	if (usec - p_env->philo[i].last_meal_time > p_env->t_t_die * MSEC_TO_USEC)
	{
		pthread_mutex_unlock(&(p_env->mutex_meal_time));
		pthread_mutex_lock(&p_env->mutex_put_log);
		put_philo_log(p_env->philo, p_env, DIED, usec);
		p_env->is_dead_myself_or_other_philo = true;
		pthread_mutex_unlock(&p_env->mutex_put_log);
		return (true);
	}
	pthread_mutex_unlock(&(p_env->mutex_meal_time));
	return (false);
}
