/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:23:01 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/16 22:30:11 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_forks(t_table *table, int id, int l_fork, int r_fork)
{
	if (l_fork != r_fork)
	{
		pthread_mutex_lock(&table->forks[l_fork]);
		print_status(table, id, TFL, PK);
		pthread_mutex_lock(&table->forks[r_fork]);
		print_status(table, id, TFR, PP);
	}
	else
	{
		pthread_mutex_lock(&table->forks[l_fork]); 
		usleep(table->t_to_die * 1000);
		print_status(table, id, DI, RD); 
		pthread_mutex_lock(&table->data_m);
		table->feast_end = 1;
		pthread_mutex_unlock(&table->data_m);
		pthread_mutex_unlock(&table->forks[l_fork]);
	}
}

void	eat(t_table *table, int id)
{
	long long	ph_last_meal;

	ph_last_meal = table->philos[id - 1].last_meal;

	pthread_mutex_lock(&table->data_m);
	if (table->feast_end == 1)
	{
		pthread_mutex_unlock(&table->data_m);
		return ;
	}
	// printf("UPD hr last meal: %lld\n", table->philos[id - 1].last_meal);
	if (t_ms(table) + table->t_to_eat - ph_last_meal >= table->t_to_die)
	{
		print_status(table, id, DI, RD);
		table->philos[id - 1].alive = 0;
		table->feast_end = 1;
		pthread_mutex_unlock(&table->data_m);
		return ;
	}
	table->philos[id - 1].meals_eaten++;
	print_status(table, id, IE, GR);
	if (table->philos[id - 1].meals_eaten == table->meals_req)
		table->philos[id - 1].feeded = 1;
	// printf("Ph %d ha comido %d veces de %d\n", id, table->philos[id - 1].meals_eaten, table->meals_req);
	// printf("Ph %d esta %d feeded\n", id, table->philos[id - 1].feeded);
	pthread_mutex_unlock(&table->data_m);
	usleep(table->t_to_eat * 1000);
	pthread_mutex_lock(&table->data_m);
	table->philos[id - 1].last_meal = t_ms(table);
	pthread_mutex_unlock(&table->data_m);
}

// void    eat(t_table *table, int id)
// {
//     print_status(table, id, IE, GR);
//     pthread_mutex_lock(&table->data_m);
//     // table->philos[id - 1].meals_eaten++;
//     if (table->philos[id - 1].meals_eaten++ == table->meals_req)
//         table->philos[id - 1].feeded = 1;
//     pthread_mutex_unlock(&table->data_m);
//     usleep(table->t_to_eat * 1000);
//     table->philos[id - 1].last_meal = t_ms(table);
// 	printf("Ph %d ha comido %d veces de %d\n", id, table->philos[id - 1].meals_eaten, table->meals_req);
// }

void	put_down_forks(t_table *table, int l_fork, int r_fork)
{
	pthread_mutex_unlock(&table->forks[l_fork]);
	pthread_mutex_unlock(&table->forks[r_fork]);
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
