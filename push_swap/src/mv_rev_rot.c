/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rev_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:27:19 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 15:25:04 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rev_rot_a (rra) rot one position downwards all nodes from pile a */
void	rev_rot_a(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*temp;

	if (*stack_a && (*stack_a)->next != NULL)
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
	print_stack(*stack_a);
}

/* rev_rot_b (rrb) rot one position downwards all nodes from pile b */
void	rev_rot_b(t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*temp;

	if (*stack_b && (*stack_b)->next != NULL)
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
	print_stack(*stack_b);
}

/* rev_rot_both (rrr) rot one position downwards all nodes pile a & b */
void	rev_rot_both(t_stack **stack_a, t_stack **stack_b)
{
	rev_rot_a(stack_a);
	rev_rot_b(stack_b);
	ft_printf("rra\n");
}
