/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:42:21 by user              #+#    #+#             */
/*   Updated: 2024/01/28 18:25:12 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* s_rev_order checks if s is alredy in reverse order */
int	s_rev_order(t_s *s)
{
	while (s && s->nxt != NULL)
	{
		if (s->idx < s->nxt->idx)
			return (0);
		s = s->nxt;
	}
	return (1);
}

/* s_rev_order checks if s is alredy in order */
int	s_order(t_s *s)
{
	while (s && s->nxt != NULL)
	{
		if (s->idx > s->nxt->idx)
			return (0);
		s = s->nxt;
	}
	return (1);
}

/* cheaper_mv checks distance from head our trgt value */
int	cheap_m(t_s **s, int trgt)
{
	int		r_count;
	int		rr_count;
	t_s	*curr;

	r_count = 0;
	rr_count = s_size(*s);
	curr = *s;
	while (curr->idx != trgt)
	{
		curr = curr->nxt;
		r_count++;
		rr_count--;
	}
	if (r_count <= rr_count)
		return (1);
	else
		return (0);
}

int	f_chk_v(t_s *s, int i)
{
	int idx_value;
	t_s *curr;

	idx_value = 0;
	if (!s)
		return (0);
	curr = s;
	while (curr && curr->nxt != NULL)
	{
		if (curr->idx <= i)
		{
			idx_value = curr->idx;
			return (idx_value);
		}
		else
			curr = curr->nxt;
	}
	return (idx_value);
}

int	f_chk_vr(t_s *s, int i)
{
	int idx_value;
	t_s *curr;
	
	idx_value = 0;
	if (!s)
		return (0);
	curr = s;
	while (curr && curr->nxt != NULL)
		curr = curr->nxt;
	while (curr && curr->prv != NULL)
	{
		if (curr->idx <= i)
		{
			idx_value = curr->idx;
			return (idx_value);
		}
		else
			curr = curr->prv;
	}
	return (idx_value);
}

int	final_order(t_s *s)
{
	while (s && s->nxt != NULL)
	{
		if (s->idx != s->nxt->idx + 1)
			return (0);
		s = s->nxt;
	}
	return (1);
}