/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:03:28 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/21 22:38:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* alg_selector choose better algorithm depending on stack_size */
void	alg_selector(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size <= 3)
		alg_3(stack_a);
	if (stack_size == 4)
		alg_4(stack_a, stack_b);
	if (stack_size == 5)
		alg_5(stack_a, stack_b);
}

/* alg_3 hardcoded movements for three ints */
void	alg_3(t_stack **stack_a)
{
	int	i;

	i = get_stack_size(*stack_a);
	while (((*stack_a)->next != NULL) && i > 1 && stack_order(*stack_a) != 1)
	{
		if ((*stack_a)->value == find_lowest(*stack_a))
		{
			swap_a(stack_a);
			rot_a(stack_a);
		}
		else if ((*stack_a)->value == find_highest(*stack_a))
			rot_a(stack_a);
		else if ((*stack_a)->value != find_lowest(*stack_a)
			&& (*stack_a)->next->value == find_highest(*stack_a))
			rev_rot_a(stack_a);
		else if ((*stack_a)->value != find_lowest(*stack_a)
			&& (*stack_a)->value != find_highest(*stack_a))
			swap_a(stack_a);
		i--;
	}
}
/* alg_4 moves smaller to pile b and sort 3 rest in a before recover b */
void	alg_4(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(*stack_b) < 1 && stack_order(*stack_a) != 1)
	{
		if ((*stack_a)->value == find_lowest(*stack_a))
			push_b(stack_a, stack_b);
		if (cheaper_mv(stack_a, (find_lowest(*stack_a))) == 1)
			rot_a(stack_a);
		if (cheaper_mv(stack_a, (find_lowest(*stack_a))) != 1)
			rev_rot_a(stack_a);
	}
	if (stack_order(*stack_a) == 1)
	{
		push_a(stack_a, stack_b);
		return ;
	}
	if (stack_order(*stack_a) != 1 && get_stack_size(*stack_a) == 3)
	{
		alg_3(stack_a);
		push_a(stack_a, stack_b);
	}
}

/* alg_5 moves 2 smaller to pile b and sort resting 3 before recover from b */
void	alg_5(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(*stack_b) < 2 && stack_order(*stack_a) != 1)
	{
		if ((*stack_a)->value == find_lowest(*stack_a))
			push_b(stack_a, stack_b);
		if (cheaper_mv(stack_a, (find_lowest(*stack_a))) == 1)
			rot_a(stack_a);
		if (cheaper_mv(stack_a, (find_lowest(*stack_a))) != 1)
			rev_rot_a(stack_a);
	}
	if (stack_order(*stack_a) == 1)
	{
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		return ;
	}
	if (stack_order(*stack_a) != 1 && get_stack_size(*stack_a) == 3)
	{
		alg_3(stack_a);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}