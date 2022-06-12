/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:43:38 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/12 09:14:24 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && j != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_to_param(t_all *var, char **av)
{
	if (check_arg(av))
		return (exit_error());
	var->total_ate = 0;
	var->time = in_time();
	var->num_philo = ft_atoi(av[1]);
	var->time_to_die = ft_atoi(av[2]);
	var->time_to_eat = ft_atoi(av[3]);
	var->time_to_sleep = ft_atoi(av[4]);
	if (var->num_philo <= 0 || var->time_to_die <= 0
		|| var->time_to_eat <= 0 || var->time_to_sleep <= 0)
		return (1);
	if (av[5])
	{
		var->must_eat = ft_atoi(av[5]);
		if (var->must_eat <= 0)
			return (1);
	}
	else
		var->must_eat = -1;
	return (0);
}

void	assign_param(t_philo *philo, t_all *var, pthread_mutex_t *mutex,
	pthread_mutex_t *print)
{
	int	i;

	i = 0;
	while (i < var->num_philo)
	{
		philo[i].ate = 0;
		philo[i].var = var;
		philo[i].mutex = mutex;
		philo[i].print = print;
		philo[i].id = i + 1;
		i++;
	}
}

int	free_param(t_philo *philo, pthread_mutex_t *mutex, t_all *var)
{
	if (philo)
		free(philo);
	if (mutex)
		free(mutex);
	if (var)
		free(var);
	return (1);
}

int	init_param(t_philo *philo, t_all *var)
{
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	int				i;

	i = 0;
	mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * var->num_philo);
	if (!mutex || !philo)
		return (free_param(philo, mutex, var));
	while (i < var->num_philo)
		if (pthread_mutex_init(&mutex[i++], 0))
			return (free_param(philo, mutex, var));
	if (pthread_mutex_init(&print, 0))
		return (free_param(philo, mutex, var));
	assign_param(philo, var, mutex, &print);
	return (0);
}
