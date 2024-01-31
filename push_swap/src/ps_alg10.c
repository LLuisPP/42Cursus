/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:19:27 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/31 16:49:55 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* alg_10 moves 2 smaller to pile b and sort resting 3 before recover from b */
void	alg_10(t_s **s_a, t_s **s_b, int size)
{
	while (s_size(*s_a) > 5 && s_order(*s_a) != 1)
	{
		if ((*s_a)->idx <= (find_lowest(*s_a)) && (*s_a)->idx
			<= (size / 2))
			push_b(s_a, s_b);
		else
		{
			if (chp_m(s_a, (find_lowest(*s_a))) == 1)
				rot_a(s_a);
			else if (chp_m(s_a, (find_lowest(*s_a))) != 1)
				rev_rot_a(s_a);
		}
	}
	alg_5(s_a, s_b);
	alg_10b(s_a, s_b);
}

void	alg_10b(t_s **s_a, t_s **s_b)
{
	while ((s_size(*s_b) != 0 && s_a != NULL)
		|| (s_order(*s_a) != 1 && s_size(*s_b) != 0))
	{
		if ((*s_b)->idx > (*s_a)->idx)
			rot_a(s_a);
		else if ((*s_b)->idx > (*s_a)->idx)
		{
			if ((*s_b)->idx > (*s_a)->nxt->idx)
				rot_a(s_a);
			else
				rev_rot_a(s_a);
		}
		else if ((*s_b)->idx < (*s_a)->idx)
			push_a(s_a, s_b);
	}
}
