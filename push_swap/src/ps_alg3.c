/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:15:19 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/23 10:41:17 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_3(t_stack **stack_a)
{
	while (stack_a != NULL && stack_order(*stack_a) != 1)
	{
		if ((*stack_a)->index == find_lowest(*stack_a))
		{
			swap_a(stack_a);
			rot_a(stack_a);
		}
		else if ((*stack_a)->index == find_highest(*stack_a))
			rot_a(stack_a);
		else if ((*stack_a)->index != find_highest(*stack_a)
			&& (*stack_a)->next->index == find_highest(*stack_a))
			rev_rot_a(stack_a);
		else
			swap_a(stack_a);
	}
}
