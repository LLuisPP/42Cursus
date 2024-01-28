/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:11:02 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 15:24:55 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_a (pa) push_a push at top a value from pile b to pile a */
void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_a);
		(*stack_a) = temp;
	}
	ft_printf("pa\n");
	print_status(*stack_a, *stack_b);
}

/* push_b (pb) push_a push at top a value from pile b to pile a */
void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_b);
		(*stack_b) = temp;
	}
	ft_printf("pb\n");
	print_status(*stack_a, *stack_b);
}