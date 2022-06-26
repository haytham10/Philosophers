/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:05:48 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/23 14:50:47 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	must_eat(int *c, t_all *philo)
{
	if (philo->ate >= philo->all->n_eat)
		*c += 1;
	if (*c == philo->all->n_philo)
	{
		print(philo, NULL, 0);
		return (0);
	}
	return (1);
}

void	*manage(t_philo *philo)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (1)
	{
		if (i == philo->n_philo)
		{
			i = 0;
			c = 0;
		}
		if (philo->n_eat)
			if (!must_eat(&c, &philo->philos[i]))
				return (NULL);
		if ((get_time() - philo->philos[i].time) >= philo->t_die)
		{
			print(&philo->philos[i], "died", 0);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}
