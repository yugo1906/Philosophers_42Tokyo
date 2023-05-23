/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:42:49 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/23 09:55:32 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *a_philosopher)
{
	t_philo		*philo;
	t_philo_env	*p_env;

	philo = (t_philo *)a_philosopher;
	p_env = philo->p_env;
	p_env->last_meal_time = get_now_msec();
	while (1)
	{
		if (philo->id % 2 != 0)
		{
			if (take_fork_right_start(philo, p_env) == PHILO_DEAD_OR_FINISH)
				break ;
		}
		else
		{
			if (take_fork_left_start(philo, p_env) == PHILO_DEAD_OR_FINISH)
				break ;
		}
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
		if (pthread_detach(tid[i]) != 0)
			return (put_error_and_all_free_exit(p_env, "philo_detach_thread."));
		i++;
	}
	return (NOT_ERROR);
}

void	*monitor_routine(void *arg_p_env)
{
	t_philo_env		*p_env;
	unsigned long	time;

	p_env = (t_philo_env *)arg_p_env;
	while (1)
	{
		pthread_mutex_lock(&p_env->mutex_meal_time);
		if (get_now_msec() - p_env->last_meal_time > p_env->t_t_die)
		{
			p_env->is_dead = true;
			pthread_mutex_unlock(&p_env->mutex_meal_time);
			break ;
		}
		if (is_check_finish(p_env) == true)
		{
			pthread_mutex_unlock(&p_env->mutex_meal_time);
			break ;
		}
		pthread_mutex_unlock(&p_env->mutex_meal_time);
		usleep(5000);
	}
	return (NULL);
}

bool	create_monitor_thread(pthread_t *monitor_tid, t_philo_env *p_env)
{
	if (pthread_create(monitor_tid, NULL, monitor_routine, p_env) != 0)
		return (ERROR);
	return (NOT_ERROR);
}
