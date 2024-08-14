/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:23:01 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/14 13:15:31 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_forks(t_table *table, int id, int l_fork, int r_fork)
{
	long long	t_elaps;

	pthread_mutex_lock(&table->forks[l_fork]);
	pthread_mutex_lock(&table->print_m);
	if (table->feast_end != 1)
    {
        t_elaps = t_ms(table);
        printf("[%lld] %d %s%s%s %d\n", t_elaps, id, PK, TF, F, l_fork);
    }
	pthread_mutex_unlock(&table->print_m);
	pthread_mutex_lock(&table->forks[r_fork]);
	pthread_mutex_lock(&table->print_m);
	if (table->feast_end != 1)
    {
        t_elaps = t_ms(table);
        printf("[%lld] %d %s%s%s %d\n", t_elaps, id, PP, TF, F, r_fork);
    }
	pthread_mutex_unlock(&table->print_m);
}

void	eat(t_table *table, int id)
{
	long long	t_elaps;
		
	
	pthread_mutex_lock(&table->print_m);
	pthread_mutex_lock(&table->data_m);
	if (table->feast_end != 1)
    {
    	t_elaps = t_ms(table);
	printf("VALOR TIEMPO ANTES %lld\n", table->philos[id - 1].last_meal);
        printf("[%lld] %d %s%s%s\n", t_elaps, id, GR, IE, F);
    }
	// pthread_mutex_unlock(&table->print_m);
	if (table->philos[id - 1].last_meal + table->t_to_eat >= table->t_to_die)
    {
        // El filósofo debe morir
        printf("[%lld] %d %s%s%s\n", t_elaps, id, RD, DI, F);
		pthread_mutex_unlock(&table->print_m);
		pthread_mutex_unlock(&table->data_m);
        table->philos[id - 1].alive = 0;
		table->feast_end = 1;
        return; // Salir de la función para evitar que el filósofo coma
    }
	
	table->philos[id - 1].meals_eaten++;
	// printf("\nPh %d has eaten %d from a total of %d\n\n",
	// 	id, table->philos[id -1].meals_eaten, table->meals_req);
	if (table->philos[id - 1].meals_eaten >= table->meals_req)
		table->philos[id - 1].feeded = 1;
	// check_philo_status(&table->philos[id - 1]);
	table->philos[id - 1].last_meal = t_ms(table) + table->t_to_eat;
	// printf("VALOR TIEMPO DESPUES %lld\n", table->philos[id - 1].last_meal);
	pthread_mutex_unlock(&table->data_m);
	pthread_mutex_unlock(&table->print_m);
	usleep(table->t_to_eat * 1000);
}

void	put_down_forks(t_table *table, /*int id,*/ int l_fork, int r_fork)
{
	// long long	t_elaps;

	pthread_mutex_lock(&table->print_m);
	pthread_mutex_unlock(&table->forks[r_fork]);
	// t_elaps = t_ms(table);
	// printf("[%lld] %d %srelease fork%s %d\n", t_elaps, id, PK, F, r_fork);
	// pthread_mutex_unlock(&table->print_m);
	pthread_mutex_unlock(&table->forks[l_fork]);
	// pthread_mutex_lock(&table->print_m);
	// t_elaps = t_ms(table);
	// printf("[%lld] %d %srelease fork%s %d\n", t_elaps, id, PK, F, l_fork);
	pthread_mutex_unlock(&table->print_m);
}

void	sleep_philo(t_table *table, int id)
{
	long long	t_elaps;

	pthread_mutex_lock(&table->print_m);
	if (table->feast_end != 1)
    {
        t_elaps = t_ms(table);
        printf("[%lld] %d %s%s%s\n", t_elaps, id, BL, IS, F);
    }
	pthread_mutex_unlock(&table->print_m);
	usleep(table->t_to_sleep * 1000);
}

void	think(t_table *table, int id)
{
	long long	t_elaps;
	
	pthread_mutex_lock(&table->print_m);
	if (table->feast_end != 1)
    {
        t_elaps = t_ms(table);
        printf("[%lld] %d %s\n", t_elaps, id, IT);
    }
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
	
	while (1)
	{
		pthread_mutex_lock(&table->data_m);
        if (table->feast_end == 1)
        {
            pthread_mutex_unlock(&table->data_m);
            break;
        }
        pthread_mutex_unlock(&table->data_m);
		pick_up_forks(table, id, left_fork, right_fork);

        pthread_mutex_lock(&table->data_m);
        if (table->feast_end == 1)
        {
            pthread_mutex_unlock(&table->data_m);
            put_down_forks(table, left_fork, right_fork);
            break;
        }
        pthread_mutex_unlock(&table->data_m);

        eat(table, id);

        put_down_forks(table, left_fork, right_fork);
        sleep_philo(table, id);
        think(table, id);
	}
	return (NULL);
}
