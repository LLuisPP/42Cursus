/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:19:27 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/23 13:05:56 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* alg_10 moves 2 smaller to pile b and sort resting 3 before recover from b */
void	alg_10(t_stack **stack_a, t_stack **stack_b, int s_size)
{
	while (stack_size(*stack_a) > 5 && stack_order(*stack_a) != 1)
	{
		if ((*stack_a)->index <= (find_lowest(*stack_a)) && (*stack_a)->index
			<= (s_size / 2))
			push_b(stack_a, stack_b);
		else
		{
			if (cheaper_mv(stack_a, (find_lowest(*stack_a))) == 1)
				rot_a(stack_a);
			else if (cheaper_mv(stack_a, (find_lowest(*stack_a))) != 1)
				rev_rot_a(stack_a);
		}
	}
	alg_5(stack_a, stack_b);
	alg_10b(stack_a, stack_b);
}

void	alg_10b(t_stack **stack_a, t_stack **stack_b)
{
	while ((stack_size(*stack_b) != 0 && stack_a != NULL)
		|| (stack_order(*stack_a) != 1 && stack_size(*stack_b) != 0))
	{
		if ((*stack_b)->index > (*stack_a)->index)
			rot_a(stack_a);
		else if ((*stack_b)->index > (*stack_a)->index)
		{
			if ((*stack_b)->index > (*stack_a)->next->index)
				rot_a(stack_a);
			else
				rev_rot_a(stack_a);
		}
		else if ((*stack_b)->index < (*stack_a)->index)
			push_a(stack_a, stack_b);
	}
}
