/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:05:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/17 17:56:41 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	t_ms(t_table *table)
{
	struct timeval	tv;
	long long		timestamp;

	gettimeofday(&tv, NULL);
	timestamp = (tv.tv_sec * 1000LL + tv.tv_usec / 1000) - table->start_t;
	return (timestamp);
}

void	simulation_loop(t_table *table)
{
	pthread_mutex_lock(&table->data_m);
	while (table->feast_end != 1)
	{
		pthread_mutex_unlock(&table->data_m);
		if (check_all_fed(table) == 1 || check_anyone_dead(table))
		{
			pthread_mutex_lock(&table->data_m);
			break ;
		}
		usleep(100);
		pthread_mutex_lock(&table->data_m);
	}
	pthread_mutex_unlock(&table->data_m);
}

int	check_all_fed(t_table *table)
{
	int		i;
	int		all_feed;

	i = 0;
	all_feed = 1;
	pthread_mutex_lock(&table->data_m);
	while (i < table->nbr_phs)
	{
		if (table->phs[i].feeded == 0)
		{
			all_feed = 0;
			break ;
		}
		i++;
		if (all_feed == 1)
			table->feast_end = 1;
	}
	pthread_mutex_unlock(&table->data_m);
	return (all_feed);
}

int	check_anyone_dead(t_table *table)
{
	int			i;
	long long	current_time;

	current_time = t_ms(table);
	i = 0;
	while (i < table->nbr_phs)
	{
		pthread_mutex_lock(&table->data_m);
		if ((current_time - table->phs[i].last_meal) > table->t_to_die)
		{
			table->feast_end = 1;
			pthread_mutex_unlock(&table->data_m);
			print_death(table, table->phs[i].nbr, DI, RD);
			return (1);
		}
		else
			pthread_mutex_unlock(&table->data_m);
		i++;
	}
	return (0);
}
