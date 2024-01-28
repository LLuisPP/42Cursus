/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:03:28 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/26 10:48:10 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* chnk_size cuts the chunk in the size sent and pushes to b till s_size a 5 */

void	chnk_size(t_stack **stack_a, t_stack **stack_b, int s_size ,int strt, int chunk)
{

	while (strt <= s_size && stack_size(*stack_a) > 5)
	{
		while (stack_size(*stack_b) <= strt  && stack_size(*stack_a) > 5)
		{
			ft_printf("|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v| STACK SIZE A |---->%d\n", stack_size(*stack_a));
			// ft_printf("SIZEEEEEEEE MOTHERFUCKER!! :     %d // %d\n", s_size, strt);
			if ((*stack_a)->index <= strt && stack_size(*stack_a) > 5)
			{
				if (stack_size(*stack_a) >= 1)
				{
					ft_printf("---->%d\n", stack_size(*stack_a));
					push_b(stack_a, stack_b);
				}
			}
			
			// else
			if ((*stack_a)->index > strt && stack_size(*stack_a) > 5)
			{
				if (cheaper_mv(stack_a, cheaper_fr(stack_a, f_chk_v(*stack_a, strt), f_chk_vr(*stack_a, strt))) == 0)
					rev_rot_a(stack_a);
				if (cheaper_mv(stack_a, cheaper_fr(stack_a, f_chk_v(*stack_a, strt), f_chk_vr(*stack_a, strt))) == 1)
					rot_a(stack_a);
			}
		}
		ft_printf("|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0| STACK SIZE A |---->%d\n", stack_size(*stack_a));
		
		strt = strt + chunk;
	}
	alg_5(stack_a, stack_b);
	// print_status(*stack_a, *stack_b);
}

/* alg_selector choose better algorithm depending on stack_size */
void	alg_selector(t_stack **stack_a, t_stack **stack_b, int s_size)
{
	if (s_size <= 3)
		alg_3(stack_a);
	if (s_size == 4 && stack_rev_order(*stack_a) != 1)
		alg_4(stack_a, stack_b);
	if (s_size == 4 && stack_rev_order(*stack_a) == 1)
		alg_4_rev(stack_a);
	if (s_size == 5 && stack_rev_order(*stack_a) != 1)
		alg_5(stack_a, stack_b);
	if (s_size == 5 && stack_rev_order(*stack_a) == 1)
		alg_5_rev(stack_a, stack_b);
	if (s_size > 5 && s_size <= 10)
		alg_10(stack_a, stack_b, s_size);
	if (s_size > 10 && s_size <= 50)
		alg_100(stack_a, stack_b, s_size);
	if (s_size > 50 && s_size <= 100)
		alg_50(stack_a, stack_b, s_size);
	if (s_size > 100 && s_size <= 500)
		alg_50(stack_a, stack_b, s_size);
}