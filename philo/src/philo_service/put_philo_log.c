/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_philo_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:18:23 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 20:42:08 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_philo_log(t_philo *philo, t_philo_env *p_env, t_philo_status status,
		unsigned long usec)
{
	char	*str;

	if (p_env->is_dead_myself_or_other_philo)
		return ;
	str = "died";
	if (status == DIED)
	{
		if (!(p_env->is_dead_myself_or_other_philo))
			printf("%lu %d %s\n", (usec - p_env->start_time) / 1000, philo->id,
				str);
		return ;
	}
	if (p_env->is_dead_myself_or_other_philo)
		return ;
	else if (status == TAKE_FORK)
		str = "has taken a fork";
	else if (status == EATING)
		str = "is eating";
	else if (status == SLEEPING)
		str = "is sleeping";
	else if (status == THINKING)
		str = "is thinking";
	printf("%lu %d %s\n", (usec - p_env->start_time) / 1000, philo->id, str);
}
