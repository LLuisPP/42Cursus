/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:11:02 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/27 14:16:52 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_b (pa) push_a push at top a value from pile b to pile a */
void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*new_node;

	if (*stack_b)
	{
		new_node = stack_clone_node(*stack_b);
		stack_add_top(stack_a, new_node);
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
		if (*stack_b)
			(*stack_b)->prev = NULL;
	}
	ft_printf("pa\n");
	// print_status(*stack_a, *stack_b);
}

/* push_b (pb) push at top a value from pile a to pile b */
void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*new_node;

	if (*stack_a)
	{
		new_node = stack_clone_node(*stack_a);
		stack_add_top(stack_b, new_node);
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
		if (*stack_a)
			(*stack_a)->prev = NULL;
	}
	ft_printf("pb\n");
	// print_status(*stack_a, *stack_b);
}
