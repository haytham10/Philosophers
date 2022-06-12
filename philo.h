/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:06:19 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/12 09:47:20 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_all
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				total_ate;
	unsigned long	time;
}	t_all;

typedef struct s_philo
{
	int				ate;
	int				id;
	t_all			*var;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print;
	unsigned long	last_meal;
}	t_philo;

int				exit_error(void);
void			*init_data(void *p);
void			ft(t_philo *philo, t_all *var);
void			print(t_philo *philo, unsigned long time, char *is_doing);
int				init_param(t_philo *philo, t_all *var);
int				free_param(t_philo *philo, pthread_mutex_t *mutex, t_all *var);
void			assign_param(t_philo *philo, t_all *var, pthread_mutex_t *mutex,
					pthread_mutex_t *print);
int				arg_to_param(t_all *var, char **av);
int				check_arg(char **av);
int				ft_atoi(char *str);
void			dst_mutex(t_philo *philo);
unsigned long	real_time(t_philo *philo);
unsigned long	in_time(void);

#endif