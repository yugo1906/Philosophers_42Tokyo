/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:18:23 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/08 19:18:10 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_time_in_ms(struct timeval *tv)
{
	unsigned long	timestamp;

	gettimeofday(tv, NULL);
	timestamp = (tv->tv_sec * 1000) + (tv->tv_usec / 1000);
	printf("timestamp: %lu", timestamp);
}
