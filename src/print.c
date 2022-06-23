/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:10:58 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/23 14:15:24 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	print(t_all *philo, char *s, int lamp)
{
	pthread_mutex_lock(&philo->all->mutex);
	if (s)
		printf("%lldms %d %s\n", (get_time() - philo->all->time)
			, philo->id, s);
	if (lamp)
		pthread_mutex_unlock(&philo->all->mutex);
}
