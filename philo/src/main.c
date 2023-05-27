/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:15:15 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 20:25:00 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// todo: メモリーリークテスト_課題提出前に削除

int	main(int argc, char **argv)
{
	t_philo_env	p_env;
	pthread_t	monitor_tid;
	bool		is_thread_error;

	if (is_validate_arg(argc, argv) == ERROR)
		return (put_error_end_exit("Invalid argument."));
	if (init_philo_env(argc, argv, &p_env) == ERROR)
		return (put_error_end_exit("Failed to initialize philo_env."));
	init_philosophers(&p_env);
	if (create_monitor_thread(&monitor_tid, &p_env) == ERROR)
		return (put_error_end_exit("Failed to create monitor_thread."));
	if (create_philo_thread(&p_env) == ERROR)
		return (EXIT_FAILURE);
	if (pthread_join(monitor_tid, NULL))
		return (put_error_end_exit("Failed to join monitor_thread."));
	all_pthread_mutex_destroy(&p_env);
	free(p_env.philo);
	free(p_env.fork);
	return (EXIT_SUCCESS);
}
