/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:03:28 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/20 12:28:10 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_selector(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size <= 3)
		alg_3(stack_a);
	if (stack_size >= 4)
		alg_4(stack_a, stack_b);
}

/* alg_3 hardcoded movements */
void	alg_3(t_stack **stack_a)
{
	int	i;

	i = get_stack_size(*stack_a);
	while (((*stack_a)->next != NULL) && i > 1 && stack_order(*stack_a) != 1)
	{
		if ((*stack_a)->value == find_lowest(*stack_a))
		{
			swap_a(stack_a);
			rotate_a(stack_a);
		}
		else if ((*stack_a)->value == find_highest(*stack_a))
			rotate_a(stack_a);
		else if ((*stack_a)->value != find_lowest(*stack_a)
			&& (*stack_a)->next->value == find_highest(*stack_a))
			reverse_rotate_a(stack_a);
		else if ((*stack_a)->value != find_lowest(*stack_a)
			&& (*stack_a)->value != find_highest(*stack_a))
			swap_a(stack_a);
		i--;
	}
}

void	alg_4(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->value == find_lowest(*stack_a))
	{
		push_b(stack_a, stack_b);
	}
	else if (cheaper_mv(stack_a, (find_lowest(*stack_a))) == 1)
		rotate_a(stack_a);
	else if (cheaper_mv(stack_a, (find_lowest(*stack_a))) == 0)
		reverse_rotate_a(stack_a);
	if (stack_order(*stack_a) != 1 && get_stack_size(*stack_a) == 3)
		alg_3(stack_a);
	if (stack_order(*stack_a) == 1)
		push_a(stack_a, stack_b);
	return ;
}

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
