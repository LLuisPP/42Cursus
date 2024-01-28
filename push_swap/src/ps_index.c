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
