/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:24:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/01 06:53:02 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* f_lowidx find the lowest val with idx != 0 in a s */
int	f_lowidx(t_s **s)
{
	int	min_val;
	t_s	*curr;

	min_val = INT_MAX;
	if (!s || !*s)
		return (min_val);
	curr = *s;
	while (curr != NULL)
	{
		if (curr->idx != 0 && curr->idx <= min_val)
		{
			min_val = curr->idx;
		}
		curr = curr->nxt;
	}
	return (min_val);
}

/* find_highest find the highest val in a s */
int	find_highest(t_s *s)
{
	int	max_val;

	if (s == NULL)
		return (INT_MAX);
	max_val = INT_MIN;
	while (s != NULL)
	{
		if (s->idx > max_val)
			max_val = s->idx;
		s = s->nxt;
	}
	return (max_val);
}

/* find_highest find the highest val in a s */
int	find_lowest(t_s *s)
{
	int	min_val;

	if (s == NULL)
		return (INT_MIN);
	min_val = INT_MAX;
	while (s != NULL)
	{
		if (s->idx < min_val)
			min_val = s->idx;
		s = s->nxt;
	}
	return (min_val);
}

/* f_last find the last idx from a s */
int	f_last(t_s *s)
{
	int	idx_val;
	t_s	*curr;

	idx_val = 0;
	if (!s)
		return (0);
	curr = s;
	while (curr && curr->nxt != NULL)
	{
		curr = curr->nxt;
	}
	idx_val = curr->idx;
	return (idx_val);
}
