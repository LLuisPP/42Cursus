/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:42:21 by user              #+#    #+#             */
/*   Updated: 2024/01/28 15:21:31 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* stack_rev_order checks if stack is alredy in reverse order */
int	stack_rev_order(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->index < stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* stack_rev_order checks if stack is alredy in order */
int	stack_order(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* cheaper_mv checks distance from head our target value */
int	cheaper_mv(t_stack **stack, int target)
{
	int		r_count;
	int		rr_count;
	t_stack	*current;

	r_count = 0;
	rr_count = stack_size(*stack);
	current = *stack;
	while (current->index != target)
	{
		current = current->next;
		r_count++;
		rr_count--;
	}
	if (r_count <= rr_count)
		return (1);
	else
		return (0);
}

int	f_chk_v(t_stack *stack, int i)
{
	int index_value;
	t_stack *current;

	index_value = 0;
	if (!stack)
		return (0);
	current = stack;
	while (current && current->next != NULL)
	{
		if (current->index <= i)
		{
			index_value = current->index;
			return (index_value);
		}
		else
			current = current->next;
	}
		return (index_value);
}

int	f_chk_vr(t_stack *stack, int i)
{
	int index_value;
	t_stack *current;
	
	index_value = 0;
	if (!stack)
		return (0);
	current = stack;
	while (current && current->next != NULL)
		current = current->next;
	while (current && current->prev != NULL)
	{
		if (current->index <= i)
		{
			index_value = current->index;
			return (index_value);
		}
		else
			current = current->prev;
	}
	return (index_value);
}

int	final_order(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->index != stack->next->index + 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}