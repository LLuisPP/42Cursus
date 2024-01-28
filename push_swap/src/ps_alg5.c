/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:18:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 18:23:55 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* alg_5 moves 2 smaller to pile b and sort resting 3 before recover from b */
void	alg_5(t_s **s_a, t_s **s_b)
{
	if (s_order(*s_a) == 1)
		return ;
	while (s_order(*s_a) != 1 && s_size(*s_a) > 3)
	{
		if ((*s_a)->idx == find_lowest(*s_a))
			push_b(s_a, s_b);
		else if (cheap_m(s_a, (find_lowest(*s_a))) == 1)
			rot_a(s_a);
		else if (cheap_m(s_a, (find_lowest(*s_a))) != 1)
			rev_rot_a(s_a);
	}
	if (s_order(*s_a) == 1 && s_size(*s_a) != 5)
	{
		push_a(s_a, s_b);
		push_a(s_a, s_b);
		return ;
	}
	if (s_order(*s_a) != 1 && s_size(*s_a) == 3)
	{
		alg_3(s_a);
		push_a(s_a, s_b);
		push_a(s_a, s_b);
	}
}

void	alg_5_rev(t_s **s_a, t_s **s_b)
{
	if (s_rev_order(*s_a) == 1)
	{
		push_b(s_a, s_b);
		alg_4(s_a, s_b);
		push_a(s_a, s_b);
		rot_a(s_a);
	}
}
