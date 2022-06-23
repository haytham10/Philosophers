/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:40:19 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/23 14:50:52 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if ((ac == 5 || ac == 6) && check_args(ac, av))
	{
		if (!allocate(&philo, av))
			return (printf("ERROR: malloc\n"), 0);
		thread_init(&philo);
		manage(&philo);
		return (free_all(&philo), 0);
	}
}
