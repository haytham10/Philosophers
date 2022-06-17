/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:55:30 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/17 17:59:04 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	sem_error(t_all *var)
{
	if (var->philos)
		free(var->philos);
	if (var->forks != SEM_FAILED)
		sem_close(var->forks);
	if (var->main != SEM_FAILED)
		sem_close(var->main);
	if (var->print != SEM_FAILED)
		sem_close(var->print);
}

static void	malloc_error(t_all *var)
{
	if (var->philos)
		free(var->philos);
	write(2, "Error: Malloc Failed\n", 19);
}

int	end_program(int err, t_all *var)
{
	if (err == 1)
		write (2, "Error: Wrong Arguments\n", 24);
	if (err == 2)
		malloc_error(var);
	if (err == 3)
		sem_error(var);
	return (1);
}
