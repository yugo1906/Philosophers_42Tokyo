/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:42:49 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/25 22:11:06 by yughoshi         ###   ########.fr       */
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
		if (pthread_detach(tid[i]) != 0)
			return (put_error_and_all_free_exit(p_env, "philo_detach_thread."));
		i++;
	}
	return (NOT_ERROR);
}

void	*monitoring(void *arg_philo)
{
	t_philo			*philo;
	t_philo_env		*p_env;
	unsigned long	time;

	philo = (t_philo *)arg_philo;
	p_env = philo->p_env;
	usleep(200);
	while (1)
	{
		// printf("%lu\n", get_now_msec() - philo->last_meal_time);
		if (p_env->is_dead_myself_or_other_philo)
			break ;
		if (get_now_usec() - philo->last_meal_time > p_env->t_t_die * 1000)
		{
			pthread_mutex_lock(&(p_env->mutex_is_dead));
			philo->is_dead = true;
			pthread_mutex_unlock(&(p_env->mutex_is_dead));
			break ;
		}
		if (is_check_finish(philo, p_env))
			break ;
		usleep(10000);
	}
	if (philo->is_dead)
	{
		pthread_mutex_lock(&(p_env->mutex_put_log));
		put_philo_log(philo, p_env, DIED, get_now_msec());
		p_env->is_dead_myself_or_other_philo = true;
		pthread_mutex_unlock(&(p_env->mutex_put_log));
	}
	return (NULL);
}

bool	create_monitor_thread(t_philo_env *p_env)
{
	pthread_t		moni_tid[p_env->num_of_philo];
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_create(&moni_tid[i], NULL, monitoring,
				&p_env->philo[i]) != 0)
			return (put_error_and_all_free_exit(p_env, "monit_create_thread."));
		i++;
	}
	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_join(moni_tid[i], NULL) != 0)
			return (put_error_and_all_free_exit(p_env, "monit_join_thread."));
		i++;
	}
	return (NOT_ERROR);
}
