/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mv_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:16:59 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/01 09:29:39 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rot_a (ra) rot head node to the last node from pile a */
void	rot_a(t_s **s_a)
{
	t_s	*curr;
	t_s	*tmp;

	if (*s_a && (*s_a)->nxt)
	{
		tmp = *s_a;
		*s_a = (*s_a)->nxt;
		(*s_a)->prv = NULL;
		curr = *s_a;
		while (curr->nxt != NULL)
			curr = curr->nxt;
		tmp->prv = curr;
		tmp->nxt = NULL;
		curr->nxt = tmp;
	}
	ft_printf("ra\n");
}

/* rot_a (rb) rot head node to the last node from pile b */
void	rot_b(t_s **s_b)
{
	t_s	*curr;
	t_s	*tmp;

	if (*s_b && (*s_b)->nxt)
	{
		tmp = *s_b;
		*s_b = (*s_b)->nxt;
		(*s_b)->prv = NULL;
		curr = *s_b;
		while (curr->nxt != NULL)
			curr = curr->nxt;
		tmp->prv = curr;
		tmp->nxt = NULL;
		curr->nxt = tmp;
	}
	ft_printf("rb\n");
}

/* rot_both (rr) rot head nodes to the last node from pile a and b */
void	rot_both(t_s **s_a, t_s **s_b)
{
	rot_a(s_a);
	rot_b(s_b);
	ft_printf("rr\n");
}
