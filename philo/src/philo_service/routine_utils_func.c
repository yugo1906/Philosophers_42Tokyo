/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:30:06 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/21 23:24:09 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	is_starving(t_philo *philo, t_philo_env *p_env, unsigned long now_msec)
{
	if ((now_msec - philo->last_meal_time) > p_env->time_to_die)
		return (PHILO_DEAD);
	return (PHILO_ALIVE_AND_NOT_FINISH);
}

bool	is_check_finish(t_philo_env *p_env)
{
	if (p_env->philo_finish_meal_count == p_env->max_meal_count)
		return (ALL_PHILO_FINISHED_MAX_MEAL_COUNT);
	if (p_env->is_dead)
		return (ALL_PHILO_FINISHED_MAX_MEAL_COUNT);
	return (NOT_ALL_PHILO_FINISHED_MAX_MEAL_COUNT);
}

void	set_status_dead_and_put_log(t_philo *philo, t_philo_env *p_env)
{
	struct timeval	tv_now;
	unsigned long	msec;

	pthread_mutex_lock(&(p_env->mutex_is_dead));
	if (p_env->is_dead)
	{
		pthread_mutex_unlock(&(p_env->mutex_is_dead));
		return ;
	}
	p_env->is_dead = true;
	pthread_mutex_unlock(&(philo->p_env->mutex_is_dead));
	gettimeofday(&tv_now, NULL);
	msec = tv_now.tv_sec * SEC_TO_MSEC + tv_now.tv_usec / USEC_TO_MSEC;
	put_philo_log(philo, p_env, DIED, msec);
}
