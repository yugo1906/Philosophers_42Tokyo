/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:42:49 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/17 08:54:33 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *a_philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)a_philosopher;
	// memo: philoの行動をループさせ、終了条件を満たしたら(diedしたら)ループを抜ける
	while (1)
	{
		if (take_right_fork_philo(philo))
			break ;
		if (take_left_fork_philo(philo))
			break ;
		if (eat_philo(philo))
			break ;
		if (sleep_philo(philo))
			break ;
		if (think_philo(philo))
			break ;
	}
	return (NULL);
}

bool	create_philo_thread(t_philo_env *p_env)
{
	pthread_t		tid;
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_create(&tid, NULL, philo_routine, &p_env->philo[i]) != 0)
			return (put_error_and_all_free_exit(p_env, "philo_create_thread."));
		if (pthread_detach(tid))
			return (put_error_and_all_free_exit(p_env, "philo_detach_thread."));
		i++;
	}
	return (NULL);
}

void	*monitor_routine(void *a_philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)a_philosopher;
	//
	return (NULL);
}

bool	create_monitor_thread(t_philo_env *p_env)
{
	pthread_t		tid;
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_create(&tid, NULL, monitor_routine, &p_env->philo[i]) != 0)
			return (ERROR);
		if (pthread_detach(tid) != 0)
			return (ERROR);
	}
	return (NOT_ERROR);
}
