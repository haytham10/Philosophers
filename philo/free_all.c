/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:16:55 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/23 14:18:25 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_all(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->n_philo)
		pthread_mutex_destroy(&(philo->forks[i]));
	pthread_mutex_destroy(&(philo->mutex));
	free(philo->philos);
	free(philo->forks);
	return (0);
}
