/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:49:02 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/15 08:17:28 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	while (table->feast_end == 0)
	{
		pick_up_forks(table, id, left_fork, right_fork);
		eat(table, id);
		put_down_forks(table, left_fork, right_fork);
		sleep_philo(table, id);
		think(table, id);
	}
	return (NULL);
}

int	create_threads(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	pthread_mutex_lock(&table->start_thds);
	philo = calloc(sizeof(t_philo), table->nbr_phs);
	if (!philo)
		return (-1);
	while (i < table->nbr_phs)
	{
		philo[i].id = i + 1;
		philo[i].table = table;
		if (pthread_create(&table->thds[i], NULL, routine, &philo[i]) != 0)
			return (free(philo), -1);
		i++;
	}
	pthread_mutex_unlock(&table->start_thds);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_table		table;
	pthread_t	checker_thread;

	if (argc < 5 || argc > 6)
		return (info('h'));
	if (arg_chck(argc, argv) == -1)
		return (info('d'));
	initfeast(argc, argv);
	if (init_table(argc, argv, &table) == -1)
		return (info('v'));
	if (create_threads(&table) == -1)
		return (info('t'));
	if (pthread_create(&checker_thread, NULL, checker, (void *)&table) != 0)
		return (info('k'));
	i = 0;
	while (i < table.nbr_phs)
	{
		pthread_join(table.thds[i], NULL);
		i++;
	}
	pthread_join(checker_thread, NULL);
	destroy_all(&table);
	printf("\n╚══════ 🍽  End of feast sim 🍽  ══▶\n\n");
	return (0);
}
