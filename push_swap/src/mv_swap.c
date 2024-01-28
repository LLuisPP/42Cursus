/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:10:01 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/24 09:20:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// /* stack_clone_node clones the head node from a stack */
// t_stack	*stack_clone_node(t_stack *source)
// {
// 	t_stack	*new_node;

// 	new_node = malloc(sizeof(t_stack));
// 	if (!new_node)
// 		exit(0);
// 	new_node->value = source->value;
// 	new_node->index = source->index;
// 	new_node->prev = NULL;
// 	new_node->next = NULL;
// 	return (new_node);
// 	// free(&source);
// }

/* swap_a (sa) swaps 2 first nodes in pile a */
void	swap_a(t_stack **stack_a)
{
	t_stack	*temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->prev = NULL;
		temp->next = *stack_a;
		(*stack_a)->prev = temp;
		*stack_a = temp;
	}
	ft_printf("sa\n");
	// print_stack(*stack_a);
}

/* swap_b (sb) swaps 2 first nodes in pile b */
void	swap_b(t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = temp->next;
		temp->prev = NULL;
		temp->next = *stack_b;
		(*stack_b)->prev = temp;
		*stack_b = temp;
	}
	ft_printf("sb\n");
	// print_stack(*stack_b);
}

/* swap_both (ss) swaps 2 first nodes in pile a & b */
void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}
