/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:15:20 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/10 09:38:33 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERROR 0
# define NOT_ERROR 1
# define NO_NUM_OF_MUST_EAT -1

typedef struct s_philo
{
	unsigned int		id;
	unsigned long		meal_time;
	unsigned int		num_of_forks;
	unsigned int		right_fork_id;
	unsigned int		left_fork_id;
	pthread_mutex_t		mutex_meal_time;
	struct s_philo_env	*p_env;
}						t_philo;

typedef struct s_philo_env
{
	unsigned int		num_of_philo;
	unsigned int		time_to_die;
	unsigned int		meal_time;
	unsigned int		sleep_time;
	unsigned int		num_of_must_eat;
	t_philo				*philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		mutex_end;
}						t_philo_env;

bool	is_validate_arg(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
bool	init_philo_env(int argc, char **argv, t_philo_env *p_env);
bool	init_philosophers(t_philo_env *p_env);
bool	put_error_and_philo_free_exit(t_philo_env *p_env, char *str);
bool	put_error_and_all_free_exit(t_philo_env *p_env, char *str);
bool	put_error_end_exit(char *str);
bool	create_philo_thread(t_philo_env *p_env);
void	put_philo_log(t_philo *philo, char *str);
#endif
