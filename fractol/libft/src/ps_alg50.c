/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg50.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:35:17 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/01 10:47:35 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_50(t_s **s_a, t_s **s_b, int size)
{
	chnk_size(s_a, s_b, 10, 4);
	alg_5(s_a, s_b);
	while ((s_b != NULL && s_size(*s_b) != 0 && s_a != NULL)
		|| (s_order(*s_a) != 1 && s_size(*s_b) != 0))
	{
		while (f_last(*s_a) == find_highest(*s_a) && s_size(*s_a) != size)
		{
			highatend(s_a, s_b);
		}
		while (f_last(*s_a) != find_highest(*s_a) && s_size(*s_a) != size)
		{
			nohighatend(s_a, s_b);
		}
		while (f_last(*s_a) != find_highest(*s_a))
		{
			if (chp_m(s_a, find_highest(*s_a)) == 1)
				rot_a(s_a);
			else if (chp_m(s_a, find_highest(*s_a)) != 1)
				rev_rot_a(s_a);
		}
	}
}

void	chka_rcv(t_s **s_a, t_s **s_b)
{
	while (f_last(*s_a) == (*s_a)->idx - 1 && f_last(*s_a) < (*s_a)->idx)
		rev_rot_a(s_a);
	if ((*s_a)->idx > f_last(*s_a))
	{
		while (f_last(*s_a) < (*s_a)->idx && f_last(*s_a) > (*s_b)->idx)
		{
			rev_rot_a(s_a);
		}
	}
}

void	chka_qut(t_s **s_a, t_s **s_b)
{
	int	count;
	t_s	*curr;

	count = 0;
	curr = *s_a;
	if ((*s_b)->idx < (curr)->idx)
	{
		while ((curr)->idx != find_highest(curr) && (curr)->nxt != NULL)
		{
			if ((curr)->idx == (curr)->nxt->idx)
				curr = curr->nxt;
			count++;
		}
	}
	while (count != 0)
	{
		rot_a(s_a);
		count--;
	}
}

void	highatend(t_s **s_a, t_s **s_b)
{
	if ((*s_b)->idx + 1 == (*s_a)->idx)
		push_a(s_a, s_b);
	else if ((*s_b)->idx == (*s_a)->idx + 1)
	{
		push_a(s_a, s_b);
		swap_a(s_a);
	}
	else if ((*s_b)->idx + 1 < (*s_a)->idx)
	{
		push_a(s_a, s_b);
	}
	if ((*s_b)->idx + 1 > (*s_a)->idx)
		rot_a(s_a);
}

void	nohighatend(t_s **s_a, t_s **s_b)
{
	if ((*s_a)->idx == find_highest(*s_a))
		rot_a(s_a);
	while ((*s_b)->idx + 1 > (*s_a)->idx)
		rot_a(s_a);
	if ((*s_b)->idx + 1 == (*s_a)->idx)
	{
		chka_rcv(s_a, s_b);
		push_a(s_a, s_b);
	}
	else if ((*s_b)->idx + 1 < (*s_a)->idx)
	{
		chka_rcv(s_a, s_b);
		push_a(s_a, s_b);
	}
	else if ((*s_b)->idx < f_last(*s_a))
	{
		chka_qut(s_a, s_b);
		push_a(s_a, s_b);
		chka_rcv(s_a, s_b);
	}
}
