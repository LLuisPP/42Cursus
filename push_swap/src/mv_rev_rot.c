/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rev_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:27:19 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/30 10:04:43 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rev_rot_a (rra) rot one position downwards all nodes from pile a */
void	rev_rot_a(t_s **s_a)
{
	t_s	*curr;
	t_s	*tmp;

	if (*s_a && (*s_a)->nxt != NULL)
	{
		curr = *s_a;
		while (curr->nxt != NULL)
			curr = curr->nxt;
		tmp = curr;
		curr = curr->prv;
		curr->nxt = NULL;
		tmp->prv = NULL;
		tmp->nxt = *s_a;
		(*s_a)->prv = tmp;
		*s_a = tmp;
	}
	ft_printf("rra\n");
	// print_s(*s_a);
}

/* rev_rot_b (rrb) rot one position downwards all nodes from pile b */
void	rev_rot_b(t_s **s_b)
{
	t_s	*curr;
	t_s	*tmp;

	if (*s_b && (*s_b)->nxt != NULL)
	{
		curr = *s_b;
		while (curr->nxt != NULL)
			curr = curr->nxt;
		tmp = curr;
		curr = curr->prv;
		curr->nxt = NULL;
		tmp->prv = NULL;
		tmp->nxt = *s_b;
		(*s_b)->prv = tmp;
		*s_b = tmp;
	}
	ft_printf("rrb\n");
	// print_s(*s_b);
}

/* rev_rot_both (rrr) rot one position downwards all nodes pile a & b */
void	rev_rot_both(t_s **s_a, t_s **s_b)
{
	rev_rot_a(s_a);
	rev_rot_b(s_b);
	ft_printf("rra\n");
}
