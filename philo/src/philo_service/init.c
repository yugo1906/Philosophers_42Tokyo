/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:08:48 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/23 09:45:32 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	init_all_mutexes(t_philo_env *p_env)
{
	unsigned int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		if (pthread_mutex_init(&(p_env->fork[i]), NULL) != 0)
			return (ERROR);
		i++;
	}
	if (pthread_mutex_init(&(p_env->mutex_put_log), NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&(p_env->mutex_is_dead), NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&(p_env->mutex_meal_time), NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&(p_env->mutex_max_meal_count), NULL) != 0)
		return (ERROR);
	return (NOT_ERROR);
}

bool	init_philo_env(int argc, char **argv, t_philo_env *p_env)
{
	p_env->num_of_philo = ft_atoi(argv[1]);
	p_env->t_t_die = ft_atoi(argv[2]);
	p_env->t_t_eat = ft_atoi(argv[3]);
	p_env->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		p_env->max_meal_count = ft_atoi(argv[5]);
	else
		p_env->max_meal_count = NO_NUM_OF_MUST_EAT;
	p_env->philo_finish_meal_count = 0;
	p_env->is_dead = false;
	p_env->philo = (t_philo *)malloc(sizeof(t_philo) * p_env->num_of_philo);
	if (p_env->philo == NULL)
		return (ERROR);
	p_env->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* p_env->num_of_philo);
	if (p_env->fork == NULL)
		return (put_error_and_philo_free_exit(p_env, "fork malloc error."));
	if (init_all_mutexes(p_env) == ERROR)
		return (ERROR);
	p_env->last_meal_time = get_now_msec();
	return (NOT_ERROR);
}

void	init_philosophers(t_philo_env *p_env)
{
	unsigned long	msec;
	unsigned int	i;
	unsigned int	philo_num;

	msec = get_now_msec();
	i = 0;
	philo_num = 0;
	while (i < p_env->num_of_philo)
	{
		p_env->philo[i].id = ++philo_num;
		p_env->philo[i].right_fork_id = philo_num - 1;
		p_env->philo[i].left_fork_id = philo_num % p_env->num_of_philo;
		p_env->philo[i].num_of_meal = 0;
		p_env->philo[i].p_env = p_env;
		i++;
	}
}
