/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:03:28 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/12 17:00:39 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find_smallest find the lowest value in a stack */
int    find_lowest(t_stack *stack_a)
{
    int min_value;

    if (stack_a == NULL)
        return INT_MIN;
    min_value = INT_MAX;
    while (stack_a != NULL)
    {
        if (stack_a->value < min_value)
            min_value = stack_a->value;
        stack_a = stack_a->next;
    }
    ft_printf("lowest in A %d\n", min_value);
    return (min_value);
}

/* find_highest find the highest value in a stack */
int find_highest(t_stack *stack_a)
{
    int max_value;

    if (stack_a == NULL)
        return INT_MAX;
    max_value = INT_MIN;
    while (stack_a != NULL)
    {
        if (stack_a->value > max_value)
            max_value = stack_a->value;
        stack_a = stack_a->next;
    }
    ft_printf("highest in A %d\n", max_value);
    return (max_value);
}
