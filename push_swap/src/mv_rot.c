/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:16:59 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 15:25:08 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rot_a (ra) rot head node to the last node from pile a */
void	rot_a(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		current = *stack_a;
		while (current->next != NULL)
			current = current->next;
		temp->prev = current;
		temp->next = NULL;
		current->next = temp;
	}
	ft_printf("ra\n");
	print_stack(*stack_a);
}

/* rot_a (rb) rot head node to the last node from pile b */
void	rot_b(t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		current = *stack_b;
		while (current->next != NULL)
			current = current->next;
		temp->prev = current;
		temp->next = NULL;
		current->next = temp;
	}
	ft_printf("rb\n");
	print_stack(*stack_b);
}

/* rot_both (rr) rot head nodes to the last node from pile a and b */
void	rot_both(t_stack **stack_a, t_stack **stack_b)
{
	rot_a(stack_a);
	rot_b(stack_b);
	ft_printf("rr\n");
}
