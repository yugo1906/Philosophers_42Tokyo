/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:15:20 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/21 22:35:27 by yughoshi         ###   ########.fr       */
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

# define ERROR 1
# define NOT_ERROR 0
# define NO_NUM_OF_MUST_EAT -1
# define SEC_TO_MSEC 1000
# define USEC_TO_MSEC 1000
# define MSEC_TO_USEC 1000
# define SEC_TO_USEC 1000000
# define PHILO_DEAD 1
# define PHILO_ALIVE_AND_NOT_FINISH 0
# define PHILO_DEAD_OR_FINISH 1
# define ALL_PHILO_FINISHED_MAX_MEAL_COUNT 1
# define NOT_ALL_PHILO_FINISHED_MAX_MEAL_COUNT 0



typedef enum e_philo_status
{
	TAKE_FORK = 0,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}			t_philo_status;

typedef struct s_philo
{
	unsigned int		id;
	unsigned long		last_meal_time;
	unsigned int		right_fork_id;
	unsigned int		left_fork_id;
	unsigned long		num_of_meal;
	struct s_philo_env	*p_env;
}						t_philo;

typedef struct s_philo_env
{
	unsigned int		num_of_philo;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		sleep_time;
	unsigned long		max_meal_count;
	unsigned int		philo_finish_meal_count;
	bool				is_dead;
	pthread_mutex_t		*fork;
	pthread_mutex_t		mutex_put_log;
	pthread_mutex_t		mutex_is_dead;
	pthread_mutex_t		mutex_last_meal_time;
	pthread_mutex_t		mutex_philo_finish_meal_count;
	t_philo				*philo;
}						t_philo_env;

bool	is_validate_arg(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
bool	init_philo_env(int argc, char **argv, t_philo_env *p_env);
void	init_philosophers(t_philo_env *p_env);
bool	put_error_and_philo_free_exit(t_philo_env *p_env, char *str);
bool	put_error_and_all_free_exit(t_philo_env *p_env, char *str);
bool	put_error_end_exit(char *str);
bool	create_philo_thread(t_philo_env *p_env);
bool	create_monitor_thread(pthread_t *monitor_tid, t_philo_env *p_env);
void	put_philo_log(t_philo *philo, t_philo_env *p_env, t_philo_status status, unsigned long msec);
void	*philo_routine(void *a_philosopher);
void	*monitor_routine(void *a_philosopher);
bool	take_right_fork_philo(t_philo *philo, t_philo_env *p_env);
bool	take_left_fork_philo(t_philo *philo, t_philo_env *p_env);
bool	eat_philo(t_philo *philo, t_philo_env *p_env);
bool	sleep_philo(t_philo *philo, t_philo_env *p_env);
bool	think_philo(t_philo *philo, t_philo_env *p_env);
void	set_status_dead_and_put_log(t_philo *philo, t_philo_env *p_env);
bool	is_starving(t_philo *philo, t_philo_env *p_env, unsigned long now_msec);
bool	is_check_finish(t_philo_env *p_env);

#endif
