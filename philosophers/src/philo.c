/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:49:02 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/18 10:57:33 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	feast(t_table *table, int id, int left_fork, int right_fork)
{
	pick_up_forks(table, id, left_fork, right_fork);
	eat(table, id);
	put_down_forks(table, left_fork, right_fork);
	sleep_philo(table, id);
	think(table, id);
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
	left_fork = id - 1;
	right_fork = (id % table->nbr_phs);
	pthread_mutex_lock(&table->start_thds);
	pthread_mutex_unlock(&table->start_thds);
	philo->last_meal = table->start_t;
	if (id % 2)
		usleep(table->t_to_eat * 1000);
	pthread_mutex_lock(&table->data_m);
	while (table->feast_end == 0)
	{
		pthread_mutex_unlock(&table->data_m);
		feast(table, id, left_fork, right_fork);
		pthread_mutex_lock(&table->data_m);
	}
	pthread_mutex_unlock(&table->data_m);
	return (NULL);
}

void	thread_protection(t_table *table, int up)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->data_m);
	free_philos(table);
	while (i < up)
	{
		pthread_join(table->phs[i].thd, NULL);
		i++;
	}
	pthread_mutex_unlock(&table->data_m);
}

int	create_threads(t_table *table)
{
	int				i;
	t_philo			*phs;
	struct timeval	tv;

	i = 0;
	phs = calloc(table->nbr_phs, sizeof(t_philo));
	if (!phs)
		return (-1);
	pthread_mutex_lock(&table->start_thds);
	while (i < table->nbr_phs)
	{
		phs[i].id = i + 1;
		phs[i].table = table;
		if (pthread_create(&table->phs[i].thd, NULL, routine, &phs[i]) != 0)
		{
			free(phs);
			pthread_mutex_unlock(&table->start_thds);
			return (thread_protection(table, i), -1);
		}
		i++;
	}
	gettimeofday(&tv, NULL);
	table->start_t = (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
	pthread_mutex_unlock(&table->start_thds);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_table		table;

	if (argc < 5 || argc > 6)
		return (info('h'));
	if (arg_check(argc, argv) == -1)
		return (info('d'));
	initfeast(argc, argv);
	if (init_table(argc, argv, &table) == -1)
		return (info('v'));
	if (create_threads(&table) == -1)
		return (info('t'));
	simulation_loop(&table);
	i = 0;
	while (i < table.nbr_phs)
	{
		pthread_join(table.phs[i].thd, NULL);
		i++;
	}
	printf("\n╚══════ 🍽  End of feast sim 🍽  ══▶\n\n");
	destroy_all(&table);
	return (0);
}
