/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:23:40 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/16 09:12:12 by lprieto-         ###   ########.fr       */
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

void	destroy_all(t_table *table)
{
	free_threads(table);
	destroy_mutexes(table);
	destroy_forks(table);
	free_forks(table);
	free_philos(table);
}
