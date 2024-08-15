/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:23:01 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/15 12:20:39 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_forks(t_table *table, int id, int l_fork, int r_fork)
{
	pthread_mutex_lock(&table->forks[l_fork]);
	pthread_mutex_lock(&table->data_m);
	if (table->feast_end != 1)
		print_status(table, id, TF, PK);
	pthread_mutex_unlock(&table->data_m);
	pthread_mutex_unlock(&table->data_m);
	if (&table->forks[l_fork] == &table->forks[r_fork])
	{
		usleep(table->t_to_die * 1000);
		pthread_mutex_unlock(&table->forks[l_fork]);
		print_status(table, id, DI, RD);
		table->feast_end = 1;
		pthread_mutex_unlock(&table->data_m);
		return ;
	}
	pthread_mutex_lock(&table->forks[r_fork]);
	pthread_mutex_lock(&table->data_m);
	if (table->feast_end != 1)
		print_status(table, id, TF, PP);
	pthread_mutex_unlock(&table->data_m);
}

void	eat(t_table *table, int id)
{
	pthread_mutex_lock(&table->data_m);
	if (table->feast_end != 1)
		print_status(table, id, IE, GR);
	if (table->philos[id - 1].last_meal + table->t_to_eat >= table->t_to_die)
	{
		print_status(table, id, DI, RD);
		table->philos[id - 1].alive = 0;
		table->feast_end = 1;
		pthread_mutex_unlock(&table->data_m);
		return ;
	}
	table->philos[id - 1].meals_eaten++;
	if (table->philos[id - 1].meals_eaten >= table->meals_req)
		table->philos[id - 1].feeded = 1;
	table->philos[id - 1].last_meal = t_ms(table) + table->t_to_eat;
	pthread_mutex_unlock(&table->data_m);
	usleep(table->t_to_eat * 1000);
}

void	put_down_forks(t_table *table, int l_fork, int r_fork)
{
	pthread_mutex_unlock(&table->forks[r_fork]);
	pthread_mutex_unlock(&table->forks[l_fork]);
}

void	sleep_philo(t_table *table, int id)
{
	print_status(table, id, IS, BL);
	usleep(table->t_to_sleep * 1000);
}

void	think(t_table *table, int id)
{
	if (table->feast_end != 1)
		print_status(table, id, IT, YL);
}
