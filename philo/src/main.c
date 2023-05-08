/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:15:15 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/08 19:27:08 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// todo: テストコード_課題提出前に削除
void		test_philo(t_philo_env *p_env);
// ### memo
// 1st arg : number of philosophers
// 2nd arg : time to die
// 3rd arg : time to eat
// 4th arg : time to sleep
// 5th arg : [number_of_times_each_philosopher_must_eat]

static bool	put_error_end_exit(char *str)
{
	printf("ERROR: %s\n", str);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_philo_env	p_env;

	if (is_validate_arg(argc, argv) == ERROR)
		return (put_error_end_exit("Invalid argument."));
	init_philo_env(argc, argv, &p_env);
	if (init_philosophers(&p_env) == ERROR)
		return (put_error_end_exit("Failed to initialize philosophers."));
	// todo: テスト実行関数_課題提出前に削除
	// test_philo(&p_env);
	return (EXIT_SUCCESS);
}

// todo: テストコード_課題提出前に削除
void	test_put_philo(t_philo_env *p_env)
{
	int	i;

	i = 0;
	while (i < p_env->num_of_philo)
	{
		printf("philo[%d]: %d\n", i, p_env->philo[i].id);
		i++;
	}
}

void	test_philo(t_philo_env *p_env)
{
	test_put_philo(p_env);
}
