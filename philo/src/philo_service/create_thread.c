/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:42:49 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 12:13:58 by yughoshi         ###   ########.fr       */
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
		usleep(100);
	philo->last_meal_time = get_now_usec();
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

void	*monitor(void *arg_p_env)
{
	t_philo			*philo;
	t_philo_env		*p_env;
	unsigned long	usec;
	unsigned int	i;

	i = 0;
	p_env = (t_philo_env *)arg_p_env;
	philo = p_env->philo;
	usleep(p_env->t_t_die * MSEC_TO_USEC - 1000);
	while (1)
	{
		while (i < p_env->num_of_philo)
		{
			if (is_check_finish(p_env))
				return (NULL);
			usec = get_now_usec();
			if (usec - philo[i].last_meal_time > p_env->t_t_die * MSEC_TO_USEC)
			{
				pthread_mutex_lock(&p_env->mutex_put_log);
				put_philo_log(philo, p_env, DIED, usec / USEC_TO_MSEC);
				p_env->is_dead_myself_or_other_philo = true;
				pthread_mutex_unlock(&p_env->mutex_put_log);
				return (NULL);
			}
			i++;
		}
		i = 0;
		usleep(8000);
	}
}

bool	create_monitor_thread(pthread_t *moni_tid, t_philo_env *p_env)
{
	if (pthread_create(moni_tid, NULL, monitor, p_env) != 0)
		return (put_error_and_all_free_exit(p_env, "monitor_create_thread."));
	return (NOT_ERROR);
}
