/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_philo_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:18:23 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/10 09:31:04 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static unsigned long	get_timestamp_ms(void)
{
	struct timeval	tv;
	unsigned long	timestamp;

	gettimeofday(&tv, NULL);
	timestamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (timestamp);
}

void	put_philo_log(t_philo *philo, char *str)
{
	printf("%lu %d %s\n", get_timestamp_ms(), philo->id, str);
}
