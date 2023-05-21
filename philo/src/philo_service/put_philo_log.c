/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_philo_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:18:23 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/21 22:06:42 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_philo_log(t_philo *philo, t_philo_env *p_env, t_philo_status status,
		unsigned long msec)
{
	char	*str;

	str = NULL;
	if (status == TAKE_FORK)
		str = "has taken a fork";
	else if (status == EATING)
		str = "is eating";
	else if (status == SLEEPING)
		str = "is sleeping";
	else if (status == THINKING)
		str = "is thinking";
	else if (status == DIED)
		str = "died";
	printf("%lu %d %s\n", msec, philo->id, str);
}
