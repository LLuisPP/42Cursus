/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:24:09 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/20 08:01:17 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find_highest find the lowest value in a stack */
int	find_lowest(t_stack *stack)
{
	int	min_value;

	if (stack == NULL)
		return (INT_MIN);
	min_value = INT_MAX;
	while (stack != NULL)
	{
		if (stack->value < min_value)
			min_value = stack->value;
		stack = stack->next;
	}
	return (min_value);
}

/* find_highest find the highest value in a stack */
int	find_highest(t_stack *stack)
{
	int	max_value;

	if (stack == NULL)
		return (INT_MAX);
	max_value = INT_MIN;
	while (stack != NULL)
	{
		if (stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}
