/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_watcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:05:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/14 13:20:38 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker(void *arg)
{
	t_table *table;
	int	i;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		while (i < table->nbr_phs && table->philos[i].feeded != 0)
			i++;
		if (i == table->nbr_phs)
		{
			pthread_mutex_lock(&table->print_m);
			table->feast_end = 1;
			// printf("All philosophers ate the required number of meals.\n");
			pthread_mutex_unlock(&table->print_m);
			return (NULL);
		}
	}
	return (NULL);
}

void    *death_checker(void *arg)
{
    t_table *table;
    int i;

    table = (t_table *)arg;
    while (1)
    {
        i = 0;
        while (i < table->nbr_phs && table->philos[i].alive == 0)
            i++;    
        if (i == table->nbr_phs)
        {
            pthread_mutex_lock(&table->print_m);
			table->feast_end = 1;
			pthread_mutex_unlock(&table->print_m);
            return (NULL);
        }
    }
}