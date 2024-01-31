/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:10:01 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/30 19:06:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap_a (sa) swaps 2 first nodes in pile a */
void	swap_a(t_s **s_a)
{
	t_s	*tmp;

	if (*s_a && (*s_a)->nxt)
	{
		tmp = (*s_a)->nxt;
		(*s_a)->nxt = tmp->nxt;
		tmp->prv = NULL;
		tmp->nxt = *s_a;
		(*s_a)->prv = tmp;
		*s_a = tmp;
	}
	ft_printf("sa\n");
	// print_s(*s_a);
}

/* swap_b (sb) swaps 2 first nodes in pile b */
void	swap_b(t_s **s_b)
{
	t_s	*tmp;

	if (*s_b && (*s_b)->nxt)
	{
		tmp = (*s_b)->nxt;
		(*s_b)->nxt = tmp->nxt;
		tmp->prv = NULL;
		tmp->nxt = *s_b;
		(*s_b)->prv = tmp;
		*s_b = tmp;
	}
	ft_printf("sb\n");
	// print_s(*s_b);
}

/* swap_both (ss) swaps 2 first nodes in pile a & b */
void	swap_both(t_s **s_a, t_s **s_b)
{
	swap_a(s_a);
	swap_b(s_b);
	ft_printf("ss\n");
}
