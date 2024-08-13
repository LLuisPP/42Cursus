/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:49:02 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/13 09:16:08 by lprieto-         ###   ########.fr       */
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


int create_threads(t_table *table)
{	
	int	i;

	i = 0;
	pthread_mutex_lock(&table->start_thds);
	printf("-------------- Creating philos (threads) --------------\n");
	t_philo *philo = calloc(sizeof(t_philo), table->nbr_phs);
	if (!philo)
		return (-1);
	while (i < table->nbr_phs)
	{
		philo[i].id = i + 1;
		philo[i].table = table;
		printf("%d > thread created\n", i);
		if (pthread_create(&table->thds[i], NULL, routine, &philo[i]) != 0)
		{
			free(philo);
			return (-1);
		}
		i++;
	}
	printf("-------------- All philos (threads) created -----------\n");
	pthread_mutex_unlock(&table->start_thds);
	return (0);
}

void	*checker(void *arg)
{
	t_table *table = (t_table *)arg;
	int all_feed;

	while (1)
	{
		all_feed = 1;
		for (int i = 0; i < table->nbr_phs; i++)
		{
			if (table->philos[i].feeded == 0)
			{
				all_feed = 0;
				break;
			}
		}
		if (all_feed)
		{
			printf("All philosophers ate the required number of meals.\n");
			// Aquí podrías finalizar la simulación, por ejemplo:
			pthread_mutex_lock(&table->print_m);
			table->feast_end = 1;
			pthread_mutex_unlock(&table->print_m);
			break;
		}
		usleep(1000);  // Pequeña espera para no sobrecargar la CPU
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_table			table;
	int			i;
	pthread_t checker_thread;
	
	if (argc < 5 || argc > 6)
		return (info('h'));
	if (arg_chck(argc, argv) == -1)
		return (info('d'));
	initfeast(argc, argv);
	if (init_table(argc, argv, &table) == -1)
		return (info('v'));
	printf("%s\n", "Struct intialized");
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
	printf("-------------- 10 -----------\n");
	pthread_join(checker_thread, NULL);
	printf("-------------- 11 -----------\n");
	destroy_all(&table);
	return (0);
}
