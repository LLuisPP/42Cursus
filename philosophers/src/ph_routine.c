/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:23:01 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/13 15:59:34 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_forks(t_table *table, int id, int l_fork, int r_fork)
{
	long long	t_elaps;

	pthread_mutex_lock(&table->forks[l_fork]);
	pthread_mutex_lock(&table->print_m);
	t_elaps = t_ms(table);
	printf("[%lld] %d %shas taken a fork%s %d\n", t_elaps, id, PK, F, l_fork);
	pthread_mutex_unlock(&table->print_m);
	pthread_mutex_lock(&table->forks[r_fork]);
	pthread_mutex_lock(&table->print_m);
	t_elaps = t_ms(table);
	printf("[%lld] %d %shas taken a fork%s %d\n", t_elaps, id, PP, F, r_fork);
	pthread_mutex_unlock(&table->print_m);
}

void	eat(t_table *table, int id)
{
	long long	t_elaps;
		
	pthread_mutex_lock(&table->print_m);
	t_elaps = t_ms(table);
	printf("[%lld] %d %sis eating%s\n", t_elaps, id, GR, F);
	table->philos[id - 1].meals_eaten++;
	// printf("\nPh %d has eaten %d from a total of %d\n\n",
	// 	id, table->philos[id -1].meals_eaten, table->meals_req);
	if (table->philos[id - 1].meals_eaten >= table->meals_req)
		table->philos[id - 1].feeded = 1;
	pthread_mutex_unlock(&table->print_m);
	usleep(table->t_to_eat * 1000);
}

void	put_down_forks(t_table *table, /*int id,*/ int l_fork, int r_fork)
{
	// long long	t_elaps;

	pthread_mutex_unlock(&table->forks[r_fork]);
	// pthread_mutex_lock(&table->print_m);
	// t_elaps = t_ms(table);
	// printf("[%lld] %d %srelease fork%s %d\n", t_elaps, id, PK, F, r_fork);
	// pthread_mutex_unlock(&table->print_m);
	pthread_mutex_unlock(&table->forks[l_fork]);
	// pthread_mutex_lock(&table->print_m);
	// t_elaps = t_ms(table);
	// printf("[%lld] %d %srelease fork%s %d\n", t_elaps, id, PK, F, l_fork);
	// pthread_mutex_unlock(&table->print_m);
}

void	sleep_philo(t_table *table, int id)
{
	long long	t_elaps;

	pthread_mutex_lock(&table->print_m);
	t_elaps = t_ms(table);
	printf("[%lld] %d %sis sleeping%s\n", t_elaps, id, BL, F);
	pthread_mutex_unlock(&table->print_m);
	usleep(table->t_to_sleep * 1000);
}

void	think(t_table *table, int id)
{
	long long	t_elaps;
	
	pthread_mutex_lock(&table->print_m);
	t_elaps = t_ms(table);
	printf("[%lld] %d is thinking\n", t_elaps, id);
	pthread_mutex_unlock(&table->print_m);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;
	int		id;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	table = philo->table;
	id = philo->id;
	left_fork = id;
	right_fork = (id % table->nbr_phs) + 1;
	pthread_mutex_lock(&table->start_thds);
	pthread_mutex_unlock(&table->start_thds);
	while (table->feast_end != 1)
	{
		if (table->feast_end != 1)
			pick_up_forks(table, id, left_fork, right_fork);
		if (table->feast_end != 1)
			eat(table, id);
		if (table->feast_end != 1)
			put_down_forks(table, /*id,*/ left_fork, right_fork);
		if (table->feast_end != 1)
			sleep_philo(table, id);
		if (table->feast_end != 1)
			think(table, id);
	}
	return (NULL);
}
