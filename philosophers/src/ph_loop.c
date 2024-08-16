/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:05:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/16 22:41:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulation_loop(t_table *table)
{
	while (table->feast_end != 1)
	{
		if (check_all_fed(table) == 1 || check_anyone_dead(table))
			break ;
		usleep(1000);
	}
	
}

int	check_all_fed(t_table *table)
{
	int		i;
	int		stop;
	
	i = 0;
	stop = 1;
	pthread_mutex_lock(&table->data_m);
	while (i < table->nbr_phs)
	{
		if (table->philos[i].feeded == 0)
		{
			stop = 0;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&table->data_m);
	return (stop);
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