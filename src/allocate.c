/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:44:06 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/23 14:03:48 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	allocate(t_philo *philo, char **av)
{
	int	i;

	i = -1;
	philo->n_philo = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->n_eat = ft_atoi(av[5]);
	philo->philos = malloc(sizeof(t_all) * (philo->n_philo));
	if (!philo->philos)
		return (0);
	philo->time = get_time();
	while (++i < philo->n_philo)
	{
		philo->philos[i].id = i + 1;
		philo->philos[i].time = philo->time;
		philo->philos[i].ate = 0;
		philo->philos[i].all = philo;
	}
	return (1);
}
