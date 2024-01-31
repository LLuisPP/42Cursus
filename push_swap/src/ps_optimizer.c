/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:59:07 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/31 17:13:52 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chp_val(t_s **s, int trgtA, int trgetB)
{
	int		F_count;
    int		R_count;
	t_s		*curr;
	
	F_count = 0;
    R_count = 0;
	if (trgtA == 0 && trgetB != 0)
		return (trgetB);
	if (trgetB == 0 && trgtA != 0)
		return (trgtA);
	if (trgtA == trgetB)
		return (trgtA);
	curr = *s;
	while (curr->idx != trgtA)
	{
		curr = curr->nxt;
		F_count++;
	}
    curr = *s;
    while (curr && curr->nxt != NULL)
		curr = curr->nxt;
    while (curr->idx != trgetB)
	{
		curr = curr->prv;
		R_count++;
	}
    curr = *s;
	if (F_count == s_size(*s) && R_count == s_size(*s))
		return (0);   
	if (F_count == 0)
		return (trgtA);
	else if (R_count == 0)
		return (trgetB);
	if (F_count <= R_count)
		return (trgtA);
	else
		return (trgetB);
}