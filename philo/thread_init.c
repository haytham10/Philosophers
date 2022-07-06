/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:50:36 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/07/06 16:15:00 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(unsigned long time)
{
	unsigned long	now;

	now = get_time();
	while (get_time() - now < time)
		usleep(50);
}

void	init_forks(t_all *philo, int i)
{
	if (i == 0)
	{
		pthread_mutex_lock(&philo->all->forks[(philo->id - 1)
			% philo->all->n_philo]);
		print(philo, "taken a fork", 1);
		pthread_mutex_lock(&philo->all->forks[(philo->id)
			% philo->all->n_philo]);
		print(philo, "taken a fork", 1);
	}
	else
	{
		pthread_mutex_unlock(&philo->all->forks[(philo->id - 1)
			% philo->all->n_philo]);
		pthread_mutex_unlock(&philo->all->forks[(philo->id)
			% philo->all->n_philo]);
	}
}

void	*handler(void *arg)
{
	t_all	*philo;

	philo = arg;
	if (!(philo->id & 1))
		ft_usleep(philo->all->t_eat / 2);
	while (1)
	{
		init_forks(philo, 0);
		print(philo, "is eating", 1);
		philo->ate += 1;
		ft_usleep(philo->all->t_eat);
		init_forks(philo, 1);
		philo->time = get_time();
		print(philo, "is sleeping", 1);
		ft_usleep(philo->all->t_sleep);
		print(philo, "is thinking", 1);
	}
}

void	thread_init(t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_init(&philo->mutex, NULL);
	while (++i < philo->n_philo)
		pthread_create(&philo->philos[i].philo, NULL,
			handler, &philo->philos[i]);
	i = -1;
	while (++i < philo->n_philo)
		pthread_detach(philo->philos[i].philo);
}
