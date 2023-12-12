/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:27:19 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/12 16:59:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* reverse_rotate_a (rra) rot one position downwards all nodes from pile a */
void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		current = *stack_a;
		while (current->next != NULL)
			current = current->next;
		temp = current;
		current = current->prev;
		current->next = NULL;
		temp->prev = NULL;
		temp->next = *stack_a;
		(*stack_a)->prev = temp;
		*stack_a = temp;
	}
	ft_printf("rra\n");
}

/* reverse_rotate_b (rrb) rot one position downwards all nodes from pile b */
void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		current = *stack_b;
		while (current->next != NULL)
			current = current->next;
		temp = current;
		current = current->prev;
		current->next = NULL;
		temp->prev = NULL;
		temp->next = *stack_b;
		(*stack_b)->prev = temp;
		*stack_b = temp;
	}
	ft_printf("rrb\n");
}

/* reverse_rotate_both (rrr) rot one position downwards all nodes pile a & b */
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rra\n");
}
