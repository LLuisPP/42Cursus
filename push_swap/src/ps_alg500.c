/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg500.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:32:39 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/31 17:20:59 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* alg_10 moves 2 smaller to pile b and sort resting 3 before recover from b (20, 40)*/
void	alg_500(t_s **s_a, t_s **s_b, int size)
{
	chnk_size(s_a, s_b, size, 20, 40);
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