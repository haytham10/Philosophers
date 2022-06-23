/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:36:22 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/23 14:42:33 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_all
{
	pthread_t		philo;
	long long		time;
	int				id;
	int				ate;
	struct s_philo	*all;
}	t_all;

typedef struct s_philo
{
	int				lamp;
	long long		time;
	int				n_philo;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_eat;
	pthread_mutex_t	mutex;
	t_all			*philos;
	pthread_mutex_t	*forks;
}	t_philo;

int			check_args(int ac, char **av);
int			ft_atoi(char *str);
int			allocate(t_philo *philo, char **av);
void		*manage(t_philo *philo);
int			must_eat(int *c, t_all *philo);
void		print(t_all *philo, char *s, int lamp);
long long	get_time(void);
void		thread_init(t_philo *philo);
void		*handler(void *arg);
void		init_forks(t_all *philo, int i);
void		ft_usleep(unsigned long time);
int			free_all(t_philo *philo);

#endif