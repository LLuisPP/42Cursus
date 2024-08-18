/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ph_init.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: lprieto- <lprieto-@student.42barcelona.	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/08/11 16:17:30 by lprieto-		   #+#	  #+#			  */
/*	 Updated: 2024/08/12 21:18:48 by lprieto-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "philo.h"

int	setup_table_params(int argc, char **argv, t_table *table)
{
	struct timeval	tv;

	table->nbr_phs = ft_atol(argv[1]);
	table->t_to_die = ft_atol(argv[2]);
	table->t_to_eat = ft_atol(argv[3]);
	table->t_to_sleep = ft_atol(argv[4]);
	table->meals_req = -1;
	if (argc == 6)
		table->meals_req = ft_atol(argv[5]);
	table->feast_end = 0;
	gettimeofday(&tv, NULL);
	table->start_t = (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
	return (0);
}

int	init_table(int argc, char **argv, t_table *table)
{
	memset(table, 0, sizeof(t_table));
	if (setup_table_params(argc, argv, table) != 0)
		return (-1);
	table->forks = calloc(table->nbr_phs, sizeof(t_mutex));
	if (!table->forks)
		return (free(table->phs), -1);
	table->phs = malloc(sizeof(t_philo) * table->nbr_phs);
	if (!table->phs)
		return (free(table->phs), free(table->forks), -1);
	if (init_mutex(table) != 0)
		return (destroy_all(table), -1);
	init_philos(table, table->nbr_phs);
	return (0);
}

int	init_philos(t_table *table, int nbr_philo)
{
	int	i;

	i = 0;
	while (i < nbr_philo)
	{
		table->phs[i].last_meal = t_ms(table);
		table->phs[i].nbr = i + 1;
		table->phs[i].l_fork = &table->forks[i];
		table->phs[i].r_fork = &table->forks[((i + 1) % table->nbr_phs)];
		table->phs[i].table = table;
		table->phs[i].meals_eaten = 0;
		table->phs[i].feeded = 0;
		i++;
	}
	return (1);
}

int	init_mutex(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&table->start_thds, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&table->print_m, NULL) != 0)
	{
		pthread_mutex_destroy(&table->start_thds);
		return (-1);
	}
	if (pthread_mutex_init(&table->data_m, NULL) != 0)
	{
		pthread_mutex_destroy(&table->start_thds);
		pthread_mutex_destroy(&table->print_m);
		return (-1);
	}
	while (i < table->nbr_phs)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (mutex_protection(table, i), -1);
		i++;
	}
	return (0);
}

void	mutex_protection(t_table *table, int up)
{
	int	i;

	i = 0;
	while (i < up)
	{
		pthread_mutex_destroy(&table->forks[i]);
	}
	pthread_mutex_destroy(&table->start_thds);
	pthread_mutex_destroy(&table->print_m);
	pthread_mutex_destroy(&table->data_m);
}
