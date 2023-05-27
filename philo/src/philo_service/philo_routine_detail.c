/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_detail.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:10:09 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 20:32:43 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// フォークの持ち手を気にする
// bool	take_fork_right_start(t_philo *philo, t_philo_env *p_env)
// {
// 	unsigned long	usec;

// 	if (philo->id % 2 == 0)
// 	{
// 		pthread_mutex_lock(&(p_env->fork[philo->right_fork_id]));
// 		pthread_mutex_lock(&(p_env->mutex_put_log));
// 		usec = get_now_usec();
// 		put_philo_log(philo, p_env, TAKE_FORK, usec);
// 		pthread_mutex_unlock(&(p_env->mutex_put_log));
// 		pthread_mutex_lock(&(p_env->fork[philo->left_fork_id]));
// 		pthread_mutex_lock(&(p_env->mutex_put_log));
// 		usec = get_now_usec();
// 		put_philo_log(philo, p_env, TAKE_FORK, usec);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&(p_env->fork[philo->left_fork_id]));
// 		pthread_mutex_lock(&(p_env->mutex_put_log));
// 		usec = get_now_usec();
// 		put_philo_log(philo, p_env, TAKE_FORK, usec);
// 		pthread_mutex_unlock(&(p_env->mutex_put_log));
// 		pthread_mutex_lock(&(p_env->fork[philo->right_fork_id]));
// 		pthread_mutex_lock(&(p_env->mutex_put_log));
// 		usec = get_now_usec();
// 		put_philo_log(philo, p_env, TAKE_FORK, usec);
// 	}
// 	return (PHILO_ALIVE_AND_NOT_FINISH);
// }

// bool	eat_philo(t_philo *philo, t_philo_env *p_env)
// {
// 	unsigned long	usec;

// 	usec = get_now_usec();
// 	if (is_starving(philo, p_env, usec) || is_check_finish(p_env))
// 	{
// 		pthread_mutex_unlock(&(p_env->mutex_put_log));
// 		pthread_mutex_unlock(&(p_env->fork[philo->right_fork_id]));
// 		pthread_mutex_unlock(&(p_env->fork[philo->left_fork_id]));
// 		return (PHILO_DEAD);
// 	}
// 	put_philo_log(philo, p_env, EATING, usec);
// 	pthread_mutex_lock(&(p_env->mutex_meal_time));
// 	philo->last_meal_time = usec;
// 	philo->num_of_meal++;
// 	if (philo->num_of_meal == p_env->max_meal_count)
// 		++p_env->philo_finish_meal_count;
// 	pthread_mutex_unlock(&(p_env->mutex_meal_time));
// 	pthread_mutex_unlock(&(p_env->mutex_put_log));
// 	philo_usleep(usec, p_env->t_t_eat * MSEC_TO_USEC, p_env);
// 	if (philo->id % 2 == 0)
// 	{
// 		pthread_mutex_unlock(&(p_env->fork[philo->left_fork_id]));
// 		pthread_mutex_unlock(&(p_env->fork[philo->right_fork_id]));
// 	}
// 	else
// 	{
// 		pthread_mutex_unlock(&(p_env->fork[philo->right_fork_id]));
// 		pthread_mutex_unlock(&(p_env->fork[philo->left_fork_id]));
// 	}
// 	return (PHILO_ALIVE_AND_NOT_FINISH);
// }

// フォークの持ち手を気にしない
bool	take_fork_right_start(t_philo *philo, t_philo_env *p_env)
{
	unsigned long	usec;

	pthread_mutex_lock(&(p_env->fork[philo->right_fork_id]));
	pthread_mutex_lock(&(p_env->mutex_put_log));
	usec = get_now_usec();
	put_philo_log(philo, p_env, TAKE_FORK, usec);
	pthread_mutex_unlock(&(p_env->mutex_put_log));
	pthread_mutex_lock(&(p_env->fork[philo->left_fork_id]));
	pthread_mutex_lock(&(p_env->mutex_put_log));
	// usec = get_now_usec();
	return (PHILO_ALIVE_AND_NOT_FINISH);
}

bool	eat_philo(t_philo *philo, t_philo_env *p_env)
{
	unsigned long	usec;

	usec = get_now_usec();
	if (is_starving(philo, p_env, usec) || is_check_finish(p_env))
	{
		pthread_mutex_unlock(&(p_env->mutex_put_log));
		pthread_mutex_unlock(&(p_env->fork[philo->right_fork_id]));
		pthread_mutex_unlock(&(p_env->fork[philo->left_fork_id]));
		return (PHILO_DEAD);
	}
	put_philo_log(philo, p_env, TAKE_FORK, usec);
	put_philo_log(philo, p_env, EATING, usec);
	pthread_mutex_lock(&(p_env->mutex_meal_time));
	philo->last_meal_time = usec;
	philo->num_of_meal++;
	if (philo->num_of_meal == p_env->max_meal_count)
		++p_env->philo_finish_meal_count;
	pthread_mutex_unlock(&(p_env->mutex_meal_time));
	pthread_mutex_unlock(&(p_env->mutex_put_log));
	philo_usleep(usec, p_env->t_t_eat * MSEC_TO_USEC, p_env);
	pthread_mutex_unlock(&(p_env->fork[philo->left_fork_id]));
	pthread_mutex_unlock(&(p_env->fork[philo->right_fork_id]));
	return (PHILO_ALIVE_AND_NOT_FINISH);
}

// bool	take_fork_left_start(t_philo *philo, t_philo_env *p_env)
// {
// 	unsigned long	usec;

// 	pthread_mutex_lock(&(p_env->fork[philo->left_fork_id]));
// 	pthread_mutex_lock(&(p_env->mutex_put_log));
// 	usec = get_now_usec();
// 	put_philo_log(philo, p_env, TAKE_FORK, usec);
// 	pthread_mutex_unlock(&(p_env->mutex_put_log));
// 	pthread_mutex_lock(&(p_env->fork[philo->right_fork_id]));
// 	pthread_mutex_lock(&(p_env->mutex_put_log));
// 	usec = get_now_usec();
// 	put_philo_log(philo, p_env, TAKE_FORK, usec);
// 	return (PHILO_ALIVE_AND_NOT_FINISH);
// }

bool	sleep_philo(t_philo *philo, t_philo_env *p_env)
{
	unsigned long	usec;
	struct timeval	now;

	pthread_mutex_lock(&(p_env->mutex_put_log));
	usec = get_now_usec();
	gettimeofday(&now, NULL);
	put_philo_log(philo, p_env, SLEEPING, usec);
	pthread_mutex_unlock(&(p_env->mutex_put_log));
	philo_usleep(usec, p_env->sleep_time * MSEC_TO_USEC, p_env);
	return (PHILO_ALIVE_AND_NOT_FINISH);
}

bool	think_philo(t_philo *philo, t_philo_env *p_env)
{
	unsigned long	usec;

	pthread_mutex_lock(&(p_env->mutex_put_log));
	usec = get_now_usec();
	put_philo_log(philo, p_env, THINKING, usec);
	pthread_mutex_unlock(&(p_env->mutex_put_log));
	return (PHILO_ALIVE_AND_NOT_FINISH);
}

// bool	take_right_fork_philo(t_philo *philo, t_philo_env *p_env)
// {
// 	struct timeval	tv_now;
// 	unsigned long	msec;

// 	pthread_mutex_lock(&(p_env->fork[philo->right_fork_id]));
// 	if (is_check_finish(p_env))
// 	{
// 		pthread_mutex_unlock(&(p_env->fork[philo->right_fork_id]));
// 		pthread_mutex_unlock(&(p_env->mutex_put_log));
// 		return (PHILO_DEAD_OR_FINISH);
// 	}
// 	gettimeofday(&tv_now, NULL);
// 	msec = tv_now.tv_sec * SEC_TO_MSEC + tv_now.tv_usec / USEC_TO_MSEC;
// 	if (is_starving(philo, p_env, msec))
// 	{
// 		pthread_mutex_unlock(&(p_env->fork[philo->right_fork_id]));
// 		// pthread_mutex_unlock(&(p_env->mutex_put_log));
// 		set_status_dead_and_put_log(philo, p_env);
// 		return (PHILO_DEAD_OR_FINISH);
// 	}
// 	pthread_mutex_lock(&(p_env->mutex_put_log));
// 	put_philo_log(philo, p_env, TAKE_FORK, msec);
// 	pthread_mutex_unlock(&(p_env->mutex_put_log));
// 	return (PHILO_ALIVE_AND_NOT_FINISH);
// }

// bool	take_left_fork_philo(t_philo *philo, t_philo_env *p_env)
// {
// 	struct timeval	tv_now;
// 	unsigned long	msec;

// 	// pthread_mutex_lock(&(p_env->mutex_put_log));
// 	pthread_mutex_lock(&(p_env->fork[philo->left_fork_id]));
// 	if (is_check_finish(p_env))
// 	{
// 		pthread_mutex_unlock(&(p_env->fork[philo->right_fork_id]));
// 		pthread_mutex_unlock(&(p_env->fork[philo->left_fork_id]));
// 		return (PHILO_DEAD_OR_FINISH);
// 	}
// 	if (is_starving(philo, p_env, msec))
// 	{
// 		pthread_mutex_unlock(&(p_env->fork[philo->right_fork_id]));
// 		pthread_mutex_unlock(&(p_env->fork[philo->left_fork_id]));
// 		set_status_dead_and_put_log(philo, p_env);
// 		return (PHILO_DEAD_OR_FINISH);
// 	}
// 	return (PHILO_ALIVE_AND_NOT_FINISH);
// }
