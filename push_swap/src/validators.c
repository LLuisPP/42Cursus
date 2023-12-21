/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:42:21 by user              #+#    #+#             */
/*   Updated: 2023/12/21 21:50:40 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* stack_rev_order checks if stack is alredy in reverse order */
int	stack_rev_order(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* stack_rev_order checks if stack is alredy in order */
int	stack_order(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* cheaper_mv checks distance from head our target value */
int cheaper_mv(t_stack **stack, int target) {
    int r_count;
    int rr_count;
    t_stack *current;

    r_count = 0;
    rr_count = get_stack_size(*stack);
    current = *stack;
    while (current->value != target)
	{
        current = current->next;
        r_count++;
        rr_count--;
    }
    if (r_count < rr_count)
        return (1);
	else
        return (0);
}