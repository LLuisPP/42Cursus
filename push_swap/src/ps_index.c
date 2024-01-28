/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:39:34 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/23 10:09:07 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_s(t_stack *stack, int i)
{
	t_stack	*current;

	current = stack;
	while (stack && all_indexed(&stack) == 0)
	{
		if (stack->index == 0)
		{
			if (stack->value == find_l_i(&stack))
			{
				stack->index = i;
				i++;
				index_s(current, i);
			}
		}
		stack = stack->next;
	}
	stack = current;
}

int	all_indexed(t_stack **stack)
{
	int	s_size;
	int	i;

	i = 0;
	s_size = stack_size(*stack);
	while (i < s_size)
	{
		if ((*stack)->index == 0)
			return (0);
		i++;
		*stack = (*stack)->next;
	}
	return (1);
}
