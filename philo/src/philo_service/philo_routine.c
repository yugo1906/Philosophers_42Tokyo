/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:42:49 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 22:00:08 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	create_philo_thread(t_philo_env *p_env, t_philo *philo)
{
	unsigned int	i;

	p_env->p_tid = (pthread_t *)malloc(sizeof(pthread_t) * p_env->num_of_philo);
	if (p_env->p_tid == NULL)
		return (put_error_philo_fork_free_exit(p_env, "philo_thread."));
	if (create_philo_thread_detail(p_env, philo) == ERROR)
		return (put_error_all_free_exit(p_env, "philo_thread."));
	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_join(p_env->p_tid[i], NULL))
			return (put_error_all_free_exit(p_env, "philo_join_thread."));
		i++;
	}
	return (NOT_ERROR);
}

bool	create_philo_thread_detail(t_philo_env *p_env, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (philo[i].id % 2 == 1)
		{
			if (pthread_create(&(p_env->p_tid[i]), NULL, p_routine, &philo[i]))
				return (ERROR);
		}
		i += 2;
	}
	i = 1;
	while (i < p_env->num_of_philo)
	{
		if (philo[i].id % 2 == 0)
		{
			if (pthread_create(&(p_env->p_tid[i]), NULL, p_routine, &philo[i]))
				return (ERROR);
		}
		i += 2;
	}
	return (NOT_ERROR);
}

void	*p_routine(void *a_philosopher)
{
	t_philo			*philo;
	unsigned long	usec;

	philo = a_philosopher;
	if (philo->p_env->num_of_philo == 1)
	{
		usec = get_now_usec();
		put_philo_log(philo, philo->p_env, TAKE_FORK, usec);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(200);
	while (true)
	{
		if (take_fork_philo(philo, philo->p_env) == PHILO_DEAD_OR_FINISH)
			break ;
		if (eat_philo(philo, philo->p_env) == PHILO_DEAD_OR_FINISH)
			break ;
		if (sleep_philo(philo, philo->p_env) == PHILO_DEAD_OR_FINISH)
			break ;
		if (think_philo(philo, philo->p_env) == PHILO_DEAD_OR_FINISH)
			break ;
	}
	return (NULL);
}
