/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:59:07 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/01 10:35:28 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chp_v(t_s **s, int trgeta, int trgetb)
{
	int	f_count;
	int	r_count;
	t_s	*curr;

	if (trgeta == 0 && trgetb != 0)
		return (trgetb);
	if (trgetb == 0 && trgeta != 0)
		return (trgeta);
	if (trgeta == trgetb)
		return (trgeta);
	f_count = front_loop(s, trgeta);
	curr = *s;
	r_count = reverse_loop(s, trgetb);
	if (f_count == s_size(*s) && r_count == s_size(*s))
		return (0);
	if (f_count == 0)
		return (trgeta);
	else if (r_count == 0)
		return (trgetb);
	if (f_count <= r_count)
		return (trgeta);
	else
		return (trgetb);
}

int	front_loop(t_s **s, int trgeta)
{
	int	f_count;
	t_s	*curr;

	f_count = 0;
	curr = *s;
	while (curr->idx != trgeta)
	{
		curr = curr->nxt;
		f_count++;
	}
	return (f_count);
}

int	reverse_loop(t_s **s, int trgetb)
{
	int	r_count;
	t_s	*curr;

	r_count = 0;
	curr = *s;
	while (curr && curr->nxt != NULL)
		curr = curr->nxt;
	while (curr->idx != trgetb)
	{
		curr = curr->prv;
		r_count++;
	}
	return (r_count);
}
