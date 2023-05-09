/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:30:27 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/10 08:30:38 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	put_error_end_exit(char *str)
{
	printf("ERROR: %s\n", str);
	return (EXIT_FAILURE);
}

bool	put_error_and_philo_free_exit(t_philo_env *p_env, char *s)
{
	free(p_env->philo);
	return (put_error_end_exit(s));
}

bool	put_error_and_all_free_exit(t_philo_env *p_env, char *s)
{
	free(p_env->philo);
	free(p_env->fork);
	return (put_error_end_exit(s));
}
