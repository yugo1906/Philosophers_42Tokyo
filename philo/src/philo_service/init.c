/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:08:48 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/08 19:16:55 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	init_philo_env(int argc, char **argv, t_philo_env *p_env)
{
	p_env->num_of_philo = ft_atoi(argv[1]);
	p_env->time_to_die = ft_atoi(argv[2]);
	p_env->time_to_eat = ft_atoi(argv[3]);
	p_env->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		p_env->num_of_must_eat = ft_atoi(argv[5]);
	else
		p_env->num_of_must_eat = NO_NUM_OF_MUST_EAT;
	return (true);
}

bool	init_philosophers(t_philo_env *p_env)
{
	int	i;
	int	philo_num;

	i = 0;
	philo_num = 1;
	p_env->philo = malloc(sizeof(p_env->num_of_philo));
	if (p_env->philo == NULL)
		return (ERROR);
	while (i < p_env->num_of_philo)
	{
		p_env->philo[i].id = philo_num;
		i++;
		philo_num++;
	}
	return (NOT_ERROR);
}
