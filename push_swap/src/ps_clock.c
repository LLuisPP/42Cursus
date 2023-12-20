/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:02:57 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/20 12:11:06 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_top_a(t_stack *stack_a)
{
	while ((stack_a)->value != find_lowest(stack_a))
		rotate_a(&stack_a);
	print_stack(stack_a);
}

void	max_top_a(t_stack *stack_a)
{
	while (stack_a->value != find_highest(stack_a))
		rotate_a(&stack_a);
	print_stack(stack_a);
}

void	max_top_b(t_stack *stack_b)
{
	while (stack_b->value != find_highest(stack_b))
		rotate_a(&stack_b);
	print_stack(stack_b);
}
