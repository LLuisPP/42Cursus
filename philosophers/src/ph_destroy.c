/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:47:42 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/14 23:39:55 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_table *table)
{
	pthread_mutex_destroy(&table->start_thds);
	pthread_mutex_destroy(&table->print_m);
}

void	destroy_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_phs)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

void	free_threads(t_table *table)
{
	if (table->thds)
	{
		free(table->thds);
		table->thds = NULL;
	}
}

void	free_forks(t_table *table)
{
	if (table->forks)
	{
		free(table->forks);
		table->forks = NULL;
	}
}

void	free_philos(t_table *table)
{
	if (table->philos)
	{
		free(table->philos);
		table->philos = NULL;
	}
}
