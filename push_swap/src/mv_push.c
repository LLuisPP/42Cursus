/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:11:02 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 18:43:23 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_a (pa) push_a push at top a value from pile b to pile a */
void	push_a(t_s **s_a, t_s **s_b)
{
	t_s	*tmp;

	if (*s_b)
	{
		tmp = *s_b;
		*s_b = (*s_b)->nxt;
		tmp->nxt = (*s_a);
		(*s_a) = tmp;
	}
	ft_printf("pa\n");
	print_status(*s_a, *s_b);
}

/* push_b (pb) push_a push at top a value from pile b to pile a */
void	push_b(t_s **s_a, t_s **s_b)
{
	t_s	*tmp;

	if (*s_a)
	{
		tmp = *s_a;
		*s_a = (*s_a)->nxt;
		tmp->nxt = (*s_b);
		(*s_b) = tmp;
	}
	ft_printf("pb\n");
	print_status(*s_a, *s_b);
}