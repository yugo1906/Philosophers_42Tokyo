/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:30:06 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 12:45:50 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	get_now_msec(void)
{
	struct timeval	tv_now;
	unsigned long	msec;

	gettimeofday(&tv_now, NULL);
	msec = tv_now.tv_sec * SEC_TO_MSEC + tv_now.tv_usec / USEC_TO_MSEC;
	return (msec);
}

unsigned long	get_now_usec(void)
{
	struct timeval	tv_now;
	unsigned long	usec;

	gettimeofday(&tv_now, NULL);
	usec = tv_now.tv_sec * SEC_TO_USEC + tv_now.tv_usec;
	return (usec);
}

bool	is_starving(t_philo *philo, t_philo_env *p_env, unsigned long now_usec)
{
	unsigned long	msec;
	unsigned long	usec;

	if (p_env->is_dead_myself_or_other_philo == true)
		return (PHILO_DEAD);
	if (now_usec - philo->last_meal_time > p_env->t_t_die * MSEC_TO_USEC)
	{
		msec = get_now_msec();
		put_philo_log(philo, p_env, DIED, msec);
		p_env->is_dead_myself_or_other_philo = true;
		return (PHILO_DEAD);
	}
	return (PHILO_ALIVE_AND_NOT_FINISH);
}

bool	is_check_finish(t_philo_env *p_env)
{
	if (p_env->philo_finish_meal_count == p_env->num_of_philo)
		return (ALL_PHILO_FINISHED_MAX_MEAL_COUNT);
	return (NOT_ALL_PHILO_FINISHED_MAX_MEAL_COUNT);
}

void	philo_usleep(long start_time_us, long wait_time_us, t_philo_env *p_env)
{
	unsigned long	usec_now;
	unsigned long	end_time_usec;

	end_time_usec = start_time_us + wait_time_us - p_env->usleep_adjustment_us;
	usleep(wait_time_us - wait_time_us / 10);
	while (1)
	{
		usec_now = get_now_usec();
		if (end_time_usec <= usec_now)
			break ;
		usleep(2);
	}
	return ;
}
