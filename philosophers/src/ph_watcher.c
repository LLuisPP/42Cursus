/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_watcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:05:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/15 08:10:24 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker(void *arg)
{
	int		i;
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		pthread_mutex_lock(&table->data_m);
		while (i < table->nbr_phs && table->philos[i].feeded != 0)
			i++;
		if (i == table->nbr_phs || table->feast_end == 1)
		{
			table->feast_end = 1;
			pthread_mutex_unlock(&table->data_m);
			return (NULL);
		}
		pthread_mutex_unlock(&table->data_m);
	}
	return (NULL);
}
