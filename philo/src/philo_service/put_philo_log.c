/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_philo_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:18:23 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/23 08:55:15 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	 put_philo_log(t_philo *philo, t_philo_env *p_env, t_philo_status status,
		unsigned long msec)
{
	char	*str;

	str = "died";

	// 動作確認用、RとLのフォーク
	if (status == DIED)
		printf("%lu %d %s\n", msec, philo->id, str);
	if (p_env->is_dead)
	{
		pthread_mutex_unlock(&(p_env->mutex_put_log));
		return ;
	}
	if (status == R_TAKE_FORK)
		str = "has right fork";
	else if (status == L_TAKE_FORK)
		str = "has left fork";
	else if (status == TAKE_FORK)
		str = "has taken a fork";
	else if (status == EATING)
		str = "is eating";
	else if (status == SLEEPING)
		str = "is sleeping";
	else if (status == THINKING)
		str = "is thinking";
	printf("%lu %d %s\n", msec, philo->id, str);
}
