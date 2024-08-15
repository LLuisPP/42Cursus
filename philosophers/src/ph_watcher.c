/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_watcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:05:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/15 20:48:51 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulation_loop(t_table *table)
{
	while (1)
	{
		if (check_all_fed(table) || check_anyone_dead(table))
		{
			table->feast_end = 1;
			break ;
		}
		usleep(10);
	}
}

int	check_all_fed(t_table *table)
{
	int	i;

	pthread_mutex_lock(&table->data_m);
	i = 0;
	while (i < table->nbr_phs && table->philos[i].feeded != 0)
		i++;
	pthread_mutex_unlock(&table->data_m);
	return (i == table->nbr_phs);
}

int	check_anyone_dead(t_table *table)
{
	int			i;
	long long	current_time;

	pthread_mutex_lock(&table->data_m);
	current_time = t_ms(table);
	i = 0;
	while (i < table->nbr_phs)
	{
		if ((current_time - table->philos[i].last_meal) > table->t_to_die)
		{
			print_status(table, table->philos[i].nbr, "died", RD);
			table->feast_end = 1;
			pthread_mutex_unlock(&table->data_m);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&table->data_m);
	return (0);
}