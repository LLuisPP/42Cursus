/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:11:02 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/12 16:53:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* (pa) push_a push at top a value from pile b to pile a */
void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_node;

	if (*stack_b == NULL)
		return ;
	new_node = *stack_b;
	*stack_b = new_node->next;
	if (*stack_a == NULL)
	{
		*stack_a = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack_a;
		*stack_a = new_node;
	}
	ft_printf("pa\n");
}

/* push_b (pb) push at top a value from pile a to pile b */
void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*new_node;

	if (*stack_a == NULL)
		return ;
	new_node = *stack_a;
	*stack_a = new_node->next;
	if (*stack_b == NULL)
	{
		*stack_b = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack_b;
		*stack_b = new_node;
	}
	ft_printf("pb\n");
}