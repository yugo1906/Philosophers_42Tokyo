/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:15:15 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 21:52:14 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo_env	p_env;
	pthread_t	monitor_tid;
	bool		is_thread_error;

	if (is_validate_arg(argc, argv) == ERROR)
		return (put_error_end_exit("Invalid argument."));
	if (init_philo_env(argc, argv, &p_env) == ERROR)
		return (put_error_end_exit("Failed to initialize philo_env."));
	if (init_all_mutexes(&p_env) == ERROR)
		return (put_error_philo_fork_free_exit(&p_env, "Failed init mutexes."));
	init_philosophers(&p_env);
	if (create_monitor_thread(&monitor_tid, &p_env) == ERROR)
		return (put_error_philo_fork_free_exit(&p_env, "Failed monitor."));
	if (create_philo_thread(&p_env, p_env.philo) == ERROR)
		return (put_error_philo_fork_free_exit(&p_env, "Failed philo."));
	if (pthread_join(monitor_tid, NULL))
		return (put_error_all_free_exit(&p_env, "Failed monitor join."));
	all_pthread_mutex_destroy(&p_env);
	all_free(&p_env);
	return (EXIT_SUCCESS);
}
