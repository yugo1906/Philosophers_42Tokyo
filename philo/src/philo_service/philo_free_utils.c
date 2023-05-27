/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:07:50 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 10:09:49 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	all_pthread_mutex_destroy(t_philo_env *p_env)
{
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_mutex_destroy(&(p_env->fork[i])) != 0)
			return (ERROR);
		i++;
	}
	if (pthread_mutex_destroy(&(p_env->mutex_put_log)) != 0)
		return (ERROR);
	if (pthread_mutex_destroy(&(p_env->mutex_is_dead)) != 0)
		return (ERROR);
	if (pthread_mutex_destroy(&(p_env->mutex_meal_time)) != 0)
		return (ERROR);
	if (pthread_mutex_destroy(&(p_env->mutex_max_meal_count)) != 0)
		return (ERROR);
	if (pthread_mutex_destroy(&(p_env->mutex_simulation_finish)) != 0)
		return (ERROR);
	return (NOT_ERROR);
}
