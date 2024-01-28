/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:24:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/24 12:45:18 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find_h_i find the highest value with index != 0 in stack */
int	find_h_i(t_stack *stack)
{
	int	max_value;

	if (stack == NULL)
		return (INT_MAX);
	max_value = INT_MIN;
	while (stack->next != NULL && stack->index == 0)
	{
		if (stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}

/* find_l_i find the lowest value with index != 0 in a stack */
int	find_l_i(t_stack **stack)
{
	int		min_value;
	t_stack	*current;

	min_value = INT_MAX;
	if (!stack || !*stack)
		return (min_value);
	current = *stack;
	while (current != NULL)
	{
		if (current->index == 0 && current->value <= min_value)
		{
			min_value = current->value;
		}
		current = current->next;
	}
	return (min_value);
}

/* f_lowidx find the lowest value with index != 0 in a stack */
int	f_lowidx(t_stack **stack)
{
	int		min_value;
	t_stack	*current;

	min_value = INT_MAX;
	if (!stack || !*stack)
		return (min_value);
	current = *stack;
	while (current != NULL)
	{
		if (current->index != 0 && current->index <= min_value)
		{
			min_value = current->index;
		}
		current = current->next;
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
		if (stack->index > max_value)
			max_value = stack->index;
		stack = stack->next;
	}
	return (max_value);
}

/* find_highest find the highest value in a stack */
int	find_lowest(t_stack *stack)
{
	int	min_value;

	if (stack == NULL)
		return (INT_MIN);
	min_value = INT_MAX;
	while (stack != NULL)
	{
		if (stack->index < min_value)
			min_value = stack->index;
		stack = stack->next;
	}
	return (min_value);
}

/* f_last find the last index from a stack */
int	f_last(t_stack *stack)
{
	int index_value;
	t_stack *current;
	
	index_value = 0;
	if (!stack )
		return (0);
	current = stack;
	while (current && current->next != NULL)
	{
		current = current->next;
	}
	index_value = current->index;
	// ft_printf("Final position index %d\n", index_value);
	return (index_value);
}