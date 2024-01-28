/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:18:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/26 07:07:56 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* alg_5 moves 2 smaller to pile b and sort resting 3 before recover from b */
void	alg_5(t_stack **stack_a, t_stack **stack_b)
{
	// ft_printf("holiiiiii - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	while (stack_size(*stack_a) > 3 && stack_order(*stack_a) != 1)
	{
		if ((*stack_a)->index == find_lowest(*stack_a))
			push_b(stack_a, stack_b);
		else if (cheaper_mv(stack_a, (find_lowest(*stack_a))) == 1)
			rot_a(stack_a);
		else if (cheaper_mv(stack_a, (find_lowest(*stack_a))) != 1)
			rev_rot_a(stack_a);
	}
	if (stack_order(*stack_a) == 1)
	{
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		return ;
	}
	if (stack_order(*stack_a) != 1 && stack_size(*stack_a) == 3)
	{
		alg_3(stack_a);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	// ft_printf("adeuuuu * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

}

void	alg_5_rev(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_rev_order(*stack_a) == 1)
	{
		push_b(stack_a, stack_b);
		alg_4(stack_a, stack_b);
		push_a(stack_a, stack_b);
		rot_a(stack_a);
	}
}
