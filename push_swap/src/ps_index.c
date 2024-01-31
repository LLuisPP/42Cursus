/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_idx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:39:34 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 17:25:19 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	idx_s(t_s *s, int i)
{
	t_s	*curr;

	curr = s;
	while (s && all_idxed(&s) == 0)
	{
		if (s->idx == 0)
		{
			if (s->val == find_l_i(&s))
			{
				s->idx = i;
				i++;
				idx_s(curr, i);
			}
		}
		s = s->nxt;
	}
	s = curr;
}

int	all_idxed(t_s **s)
{
	int	size;
	int	i;

	i = 0;
	size = s_size(*s);
	while (i < size)
	{
		if ((*s)->idx == 0)
			return (0);
		i++;
		*s = (*s)->nxt;
	}
	return (1);
}

/* find_h_i find the highest val with idx != 0 in s */
int	find_h_i(t_s *s)
{
	int	max_val;

	if (s == NULL)
		return (INT_MAX);
	max_val = INT_MIN;
	while (s->nxt != NULL && s->idx == 0)
	{
		if (s->val > max_val)
			max_val = s->val;
		s = s->nxt;
	}
	return (max_val);
}

/* find_l_i find the lowest val with idx != 0 in a s */
int	find_l_i(t_s **s)
{
	int		min_val;
	t_s	*curr;

	min_val = INT_MAX;
	if (!s || !*s)
		return (min_val);
	curr = *s;
	while (curr != NULL)
	{
		if (curr->idx == 0 && curr->val <= min_val)
		{
			min_val = curr->val;
		}
		curr = curr->nxt;
	}
	return (min_val);
}
