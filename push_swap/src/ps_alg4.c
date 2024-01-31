/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:17:04 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/31 16:49:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_4(t_s **s_a, t_s **s_b)
{
	while (s_size(*s_a) > 3 && s_order(*s_a) != 1)
	{
		if ((*s_a)->idx == find_lowest(*s_a))
			push_b(s_a, s_b);
		else if (chp_m(s_a, (find_lowest(*s_a))) == 1)
			rot_a(s_a);
		else if (chp_m(s_a, (find_lowest(*s_a))) != 1)
			rev_rot_a(s_a);
	}
	if (s_order(*s_a) != 1 && s_size(*s_a) == 3)
	{
		alg_3(s_a);
		while (s_size(*s_b) != 0)
			push_a(s_a, s_b);
	}
}

void	alg_4_rev(t_s **s_a)
{
	if (s_size(*s_a) == 4)
	{
		swap_a(s_a);
		rot_a(s_a);
		rot_a(s_a);
		swap_a(s_a);
	}
}
