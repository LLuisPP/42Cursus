/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:17:04 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/23 10:58:20 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_4(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3 && stack_order(*stack_a) != 1)
	{
		if ((*stack_a)->index == find_lowest(*stack_a))
			push_b(stack_a, stack_b);
		else if (cheaper_mv(stack_a, (find_lowest(*stack_a))) == 1)
			rot_a(stack_a);
		else if (cheaper_mv(stack_a, (find_lowest(*stack_a))) != 1)
			rev_rot_a(stack_a);
	}
	if (stack_order(*stack_a) != 1 && stack_size(*stack_a) == 3)
	{
		alg_3(stack_a);
		while (stack_size(*stack_b) != 0)
			push_a(stack_a, stack_b);
	}
}

void	alg_4_rev(t_stack **stack_a)
{
	if (stack_size(*stack_a) == 4)
	{
		swap_a(stack_a);
		rot_a(stack_a);
		rot_a(stack_a);
		swap_a(stack_a);
	}
}
