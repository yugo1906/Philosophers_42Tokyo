/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:07:50 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 21:52:23 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	all_pthread_mutex_destroy(t_philo_env *p_env)
{
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_mutex_destroy(&(p_env->fork[i])))
			return (ERROR);
		i++;
	}
	if (pthread_mutex_destroy(&(p_env->mutex_put_log)))
		return (ERROR);
	if (pthread_mutex_destroy(&(p_env->mutex_is_dead)))
		return (ERROR);
	if (pthread_mutex_destroy(&(p_env->mutex_meal_time)))
		return (ERROR);
	return (NOT_ERROR);
}

void	all_free(t_philo_env *p_env)
{
	if (p_env->philo)
	{
		free(p_env->philo);
		p_env->philo = NULL;
	}
	if (p_env->fork)
	{
		free(p_env->fork);
		p_env->fork = NULL;
	}
	if (p_env->p_tid)
	{
		free(p_env->p_tid);
		p_env->p_tid = NULL;
	}
}
