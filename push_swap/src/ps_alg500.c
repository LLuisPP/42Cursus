/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg500.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:32:39 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/25 14:17:04 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* alg_10 moves 2 smaller to pile b and sort resting 3 before recover from b */
void	alg_500(t_stack **stack_a, t_stack **stack_b, int s_size)
{
	chnk_size(stack_a, stack_b, s_size, 20, 63);

	while ((stack_b != NULL && stack_size(*stack_b) != 0 && stack_a != NULL) || (stack_order(*stack_a) != 1 && stack_size(*stack_b) != 0))
	{
		while (f_last(*stack_a) == find_highest(*stack_a) && stack_size(*stack_a) != s_size)
		{
			if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index < f_last(*stack_a))/*Me3b1h*/
			{
				push_a(stack_a, stack_b);
				swap_a(stack_a);
			}
			if ((*stack_a)->index > (*stack_b)->index && (*stack_a)->index < f_last(*stack_a))/*Me1b3h*/
			{
				push_a(stack_a, stack_b);
			}
		}
		while (f_last(*stack_a) != find_highest(*stack_a))
		{
			print_status(*stack_a, *stack_b);
			if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index < f_last(*stack_a) && (*stack_b)->index < f_last(*stack_a))/*5e3b1h*/
			{
				push_a(stack_a, stack_b);
				swap_a(stack_a);
			}
			else if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index < f_last(*stack_a) && (*stack_b)->index > f_last(*stack_a))/*5e6b1h*/
			{
				rev_rot_a(stack_a);
				push_a(stack_a, stack_b);
			}
			else if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index > f_last(*stack_a) && (*stack_b)->index > f_last(*stack_a))/*3e5b4h*/
			{
				push_a(stack_a, stack_b);
				swap_a(stack_a);
			}
			if ((*stack_a)->index > (*stack_b)->index && (*stack_a)->index > f_last(*stack_a) && (*stack_b)->index > f_last(*stack_a))/*1e3b5h*/
				push_a(stack_a, stack_b);
			if ((*stack_a)->index > (*stack_b)->index && (*stack_a)->index > f_last(*stack_a) && (*stack_b)->index < f_last(*stack_a))/*3e1b5h*/
				push_a(stack_a, stack_b);
			if ((*stack_a)->index > (*stack_b)->index && (*stack_a)->index < f_last(*stack_a) && (*stack_b)->index < f_last(*stack_a))/*6e1b5h*/
				push_a(stack_a, stack_b);
		}
	}
}