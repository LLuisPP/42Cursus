/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:16:59 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/12 16:59:01 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate_a (ra) rot one position upwards all nodes from pile a */
void	rotate_a(t_stack **stack_a)
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
}

/* rotate_a (rb) rot one position upwards all nodes from pile b */
void	rotate_b(t_stack **stack_b)
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
}

/* rotate_both (rr) rot one position upwards all nodes from pile a and b */
void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}
