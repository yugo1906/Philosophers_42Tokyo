/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:15:20 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/09 09:02:07 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define ERROR 0
# define NOT_ERROR 1
# define NO_NUM_OF_MUST_EAT -1

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	unsigned int	id;
	unsigned long	meal_time;
	unsigned int	num_of_forks;
	unsigned int	right_fork_id;
	unsigned int	left_fork_id;
	pthread_mutex_t	mutex_meal_time;
}					t_philo;

typedef struct s_philo_env
{
	unsigned int	num_of_philo;
	unsigned int	time_to_die;
	unsigned int	meal_time;
	unsigned int	sleep_time;
	unsigned int	num_of_must_eat;
	t_philo			*philo;
}					t_philo_env;

bool				is_validate_arg(int argc, char **argv);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
bool				init_philo_env(int argc, char **argv, t_philo_env *p_env);
void				put_time_in_ms(struct timeval *tv);
bool				init_philosophers(t_philo_env *p_env);
bool				free_and_put_error_and_exit(t_philo_env *p_env, char *str);
bool				put_error_end_exit(char *str);
#endif
