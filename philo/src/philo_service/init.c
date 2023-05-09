/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:08:48 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/09 09:42:58 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	init_philo_env(int argc, char **argv, t_philo_env *p_env)
{
	p_env->num_of_philo = ft_atoi(argv[1]);
	p_env->time_to_die = ft_atoi(argv[2]);
	p_env->meal_time = ft_atoi(argv[3]);
	p_env->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		p_env->num_of_must_eat = ft_atoi(argv[5]);
	else
		p_env->num_of_must_eat = NO_NUM_OF_MUST_EAT;
	return (true);
}

bool	init_philosophers(t_philo_env *p_env)
{
	unsigned int	i;
	unsigned int	philo_num;

	i = 0;
	philo_num = 1;
	p_env->philo = (t_philo *)malloc(sizeof(t_philo) * p_env->num_of_philo);
	if (p_env->philo == NULL)
		return (ERROR);
	while (i < p_env->num_of_philo)
	{
		p_env->philo[i].id = philo_num;
		p_env->philo[i].meal_time = 0;
		p_env->philo[i].num_of_forks = 0;
		p_env->philo[i].right_fork_id = philo_num - 1;
		p_env->philo[i].left_fork_id = philo_num % p_env->num_of_philo;
		if (pthread_mutex_init(&(p_env->philo[i].mutex_meal_time), NULL) != 0)
			return (free_and_put_error_and_exit(p_env, "mutex init error."));
		i++;
		philo_num++;
	}
	return (NOT_ERROR);
}
