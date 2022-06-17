/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:07:05 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/17 18:31:33 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print(t_philo *philo, char *str)
{
	unsigned int	now;

	now = get_time();
	sem_wait(philo->var->print);
	printf("%u\t%d\t%s\n", now - philo->var->creat_date, philo->n + 1, str);
	if (philo->var->finish == 1)
		return ;
	sem_post(philo->var->print);
}
