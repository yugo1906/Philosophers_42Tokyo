/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:15:20 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/27 22:35:28 by yughoshi         ###   ########.fr       */
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
# define MIN_USLEEP_ADJUSTMENT_US 10
# define MAX_USLEEP_ADJUSTMENT_US 1000
# define USLEEP_ONE_MSEC 1000

typedef enum e_p_status
{
	TAKE_FORK = 0,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}						t_philo_status;

typedef struct s_philo
{
	unsigned int		id;
	unsigned int		right_fork_id;
	unsigned int		left_fork_id;
	unsigned long		num_of_meal;
	unsigned long		last_meal_time;
	bool				is_dead;
	struct s_philo_env	*p_env;
}						t_philo;

typedef struct s_philo_env
{
	unsigned int		num_of_philo;
	unsigned int		t_t_die;
	unsigned int		t_t_eat;
	unsigned int		sleep_time;
	unsigned int		usleep_adjustment_us;
	unsigned long		max_meal_count;
	unsigned long		philo_finish_meal_count;
	unsigned long		start_time;
	bool				is_dead_myself_or_other_philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		mutex_put_log;
	pthread_mutex_t		mutex_is_dead;
	pthread_mutex_t		mutex_meal_time;
	pthread_t			*p_tid;
	t_philo				*philo;
}						t_philo_env;

bool					is_validate_arg(int argc, char **argv);
int						ft_atoi(const char *str);
int						ft_isdigit(int c);
bool					init_philo_env(int argc, char **argv,
							t_philo_env *p_env);
void					init_philosophers(t_philo_env *p_env);
bool					put_error_philo_free_exit(t_philo_env *p_env,
							char *str);
bool					put_error_philo_fork_free_exit(t_philo_env *p_env,
							char *str);
bool					put_error_end_exit(char *str);
bool					create_monitor_thread(pthread_t *moni_tid,
							t_philo_env *p_env);
void					put_philo_log(t_philo *philo, t_philo_env *p_env,
							t_philo_status status, unsigned long msec);
bool					take_fork_philo(t_philo *philo, t_philo_env *p_env);
bool					eat_philo(t_philo *philo, t_philo_env *p_env);
bool					sleep_philo(t_philo *philo, t_philo_env *p_env);
bool					think_philo(t_philo *philo, t_philo_env *p_env);
bool					is_starving(t_philo *philo, t_philo_env *p_env,
							unsigned long now_msec);
bool					is_check_finish(t_philo_env *p_env);
unsigned long			get_now_msec(void);
unsigned long			get_now_usec(void);
void					philo_usleep(long start_time_us, long wait_time_us,
							t_philo_env *p_env);
bool					all_pthread_mutex_destroy(t_philo_env *p_env);
bool					init_all_mutexes(t_philo_env *p_env);
void					*monitor(void *a_philosopher);
bool					is_check_death(unsigned long usec, t_philo_env *p_env,
							unsigned int i);
bool					put_error_all_free_exit(t_philo_env *p_env, char *str);
void					all_free(t_philo_env *p_env);
bool					create_philo_thread(t_philo_env *p_env, t_philo *philo);
bool					create_philo_thread_detail(t_philo_env *p_env,
							t_philo *philo);
void					*p_routine(void *a_philosopher);

#endif
