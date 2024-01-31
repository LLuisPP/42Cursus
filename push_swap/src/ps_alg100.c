/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:37:54 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/31 17:19:01 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* alg_100 chop the stack values sending valids to stack b and recover them */
void	alg_100(t_s **s_a, t_s **s_b, int size)
{
	chnk_size(s_a, s_b, size, 15, 15);
    while ((s_b != NULL && s_size(*s_b) != 0 && s_a != NULL)
        || (s_order(*s_a) != 1 && s_size(*s_b) != 0))
    {
        while (f_last(*s_a) == find_highest(*s_a) && s_size(*s_a) != size)
        {
            highatend(s_a, s_b);
        }
        while (f_last(*s_a) != find_highest(*s_a) && s_size(*s_a) != size)
        {
            nohighatend(s_a, s_b);
        }
        while (f_last(*s_a) != find_highest(*s_a))
        {
            if (chp_m(s_a, find_highest(*s_a)) == 1)
                rot_a(s_a);
            else if (chp_m(s_a, find_highest(*s_a)) != 1)
                rev_rot_a(s_a);
        }
    }
}
