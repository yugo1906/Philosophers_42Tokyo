/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:30:27 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 21:21:02 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	put_error_end_exit(char *str)
{
	printf("ERROR: %s\n", str);
	return (ERROR);
}

bool	put_error_philo_free_exit(t_philo_env *p_env, char *str)
{
	free(p_env->philo);
	p_env->philo = NULL;
	return (put_error_end_exit(str));
}

bool	put_error_philo_fork_free_exit(t_philo_env *p_env, char *str)
{
	free(p_env->philo);
	p_env->philo = NULL;
	free(p_env->fork);
	p_env->fork = NULL;
	return (put_error_end_exit(str));
}

bool	put_error_all_free_exit(t_philo_env *p_env, char *str)
{
	free(p_env->philo);
	p_env->philo = NULL;
	free(p_env->fork);
	p_env->fork = NULL;
	free(p_env->p_tid);
	p_env->p_tid = NULL;
	return (put_error_end_exit(str));
}
