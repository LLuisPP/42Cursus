/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg500.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:32:39 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 17:50:23 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* alg_10 moves 2 smaller to pile b and sort resting 3 before recover from b */
void	alg_500(t_s **s_a, t_s **s_b, int size)
{
	chnk_size(s_a, s_b, size, 20, 63);

	while ((s_b != NULL && s_size(*s_b) != 0 && s_a != NULL) || (s_order(*s_a) != 1 && s_size(*s_b) != 0))
	{
		while (f_last(*s_a) == find_highest(*s_a) && s_size(*s_a) != size)
		{
			if ((*s_a)->idx < (*s_b)->idx && (*s_a)->idx < f_last(*s_a))/*Me3b1h*/
			{
				push_a(s_a, s_b);
				swap_a(s_a);
			}
			if ((*s_a)->idx > (*s_b)->idx && (*s_a)->idx < f_last(*s_a))/*Me1b3h*/
			{
				push_a(s_a, s_b);
			}
		}
		while (f_last(*s_a) != find_highest(*s_a))
		{
			print_status(*s_a, *s_b);
			if ((*s_a)->idx < (*s_b)->idx && (*s_a)->idx < f_last(*s_a) && (*s_b)->idx < f_last(*s_a))/*5e3b1h*/
			{
				push_a(s_a, s_b);
				swap_a(s_a);
			}
			else if ((*s_a)->idx < (*s_b)->idx && (*s_a)->idx < f_last(*s_a) && (*s_b)->idx > f_last(*s_a))/*5e6b1h*/
			{
				rev_rot_a(s_a);
				push_a(s_a, s_b);
			}
			else if ((*s_a)->idx < (*s_b)->idx && (*s_a)->idx > f_last(*s_a) && (*s_b)->idx > f_last(*s_a))/*3e5b4h*/
			{
				push_a(s_a, s_b);
				swap_a(s_a);
			}
			if ((*s_a)->idx > (*s_b)->idx && (*s_a)->idx > f_last(*s_a) && (*s_b)->idx > f_last(*s_a))/*1e3b5h*/
				push_a(s_a, s_b);
			if ((*s_a)->idx > (*s_b)->idx && (*s_a)->idx > f_last(*s_a) && (*s_b)->idx < f_last(*s_a))/*3e1b5h*/
				push_a(s_a, s_b);
			if ((*s_a)->idx > (*s_b)->idx && (*s_a)->idx < f_last(*s_a) && (*s_b)->idx < f_last(*s_a))/*6e1b5h*/
				push_a(s_a, s_b);
		}
	}
}