/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:47:42 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/17 17:33:07 by lprieto-         ###   ########.fr       */
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
	if (table->phs)
	{
		free(table->phs);
		table->phs = NULL;
	}
}

void	destroy_all(t_table *table)
{
	destroy_mutexes(table);
	destroy_forks(table);
	free_forks(table);
	free_philos(table);
}
