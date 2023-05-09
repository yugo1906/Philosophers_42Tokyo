/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_and_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:30:27 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/09 08:52:02 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	put_error_end_exit(char *str)
{
	printf("ERROR: %s\n", str);
	return (EXIT_FAILURE);
}

bool	free_and_put_error_and_exit(t_philo_env *p_env, char *str)
{
	free(p_env->philo);
	return (put_error_end_exit(str));
}
