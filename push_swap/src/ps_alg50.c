/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg50.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:35:17 by user              #+#    #+#             */
/*   Updated: 2024/01/28 18:01:40 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_50(t_s **s_a, t_s **s_b, int s_size)
{
 
	// int count;
    
    // count = 0;
	chnk_size(s_a, s_b, s_size, 10, 4);
	// alg_5(s_a, s_b);
    // while ((s_b != NULL && stack_size(*s_b) != 0 && s_a != NULL) || (s_order(*s_a) != 1 && stack_size(*s_b) != 0))
    // {
    //     while (f_last(*s_a) == find_highest(*s_a) && stack_size(*s_a) != s_size)
    //     {
    //         if ((*s_a)->idx < (*s_b)->idx && (*s_a)->idx < f_last(*s_a))/*Me3b1h*/
    //         {
    //              while ((*s_a)->idx != (*s_a)->nxt->idx + 1)
    //             {
    //                 // rot_a(s_a);
    //                 count++;
    //             }
    //             push_a(s_a, s_b);
    //             swap_a(s_a);
    //             while (count != 0 || (final_order(*s_a) != 1 || s_order(*s_a)))
    //             {
    //                 count--;
    //                 // rev_rot_a(s_a);
    //             }
    //         }
    //         else if ((*s_a)->idx > (*s_b)->idx && (*s_a)->idx < f_last(*s_a))/*Me1b3h*/
    //         {
	// 			push_a(s_a, s_b);
	// 		}
    //     }
    //     while (f_last(*s_a) != find_highest(*s_a))
    //     {
    //         if ((*s_a)->idx < (*s_b)->idx && (*s_a)->idx < f_last(*s_a) && (*s_b)->idx < f_last(*s_a))/*5e3b1h*/
    //         {
    //             // while ((*s_a)->idx != (*s_a)->nxt->idx + 1)
    //             // {
    //             //     rot_a(s_a);
    //             //     count++;
    //             // }
    //             push_a(s_a, s_b);
    //             swap_a(s_a);
    //             // while (count != 0 || (final_order(*s_a) != 1 || s_order(*s_a)))
    //             // {
    //             //     rev_rot_a(s_a);
    //             //     count--;
    //             // }
    //         }
    //         else if ((*s_a)->idx < (*s_b)->idx && (*s_a)->idx < f_last(*s_a) && (*s_b)->idx > f_last(*s_a))/*5e6b1h*/
    //         {
    //             rev_rot_a(s_a);
    //             push_a(s_a, s_b);
    //         }
    //         else if ((*s_a)->idx < (*s_b)->idx && (*s_a)->idx > f_last(*s_a) && (*s_b)->idx > f_last(*s_a))/*3e5b4h*/
    //         {
    //             //  while ((*s_a)->idx != (*s_a)->nxt->idx + 1)
    //             // {
    //             //     rot_a(s_a);
    //             //     count++;
    //             // }
    //             push_a(s_a, s_b);
    //             swap_a(s_a);
    //             // while (count != 0 || (final_order(*s_a) != 1 || s_order(*s_a)))
    //             // {
    //             //     rev_rot_a(s_a);
    //             //     count--;
    //             // }
    //         }
    //         else if ((*s_a)->idx > (*s_b)->idx && (*s_a)->idx > f_last(*s_a) && (*s_b)->idx > f_last(*s_a))/*1e3b5h*/
    //             push_a(s_a, s_b);
    //         else if ((*s_a)->idx > (*s_b)->idx && (*s_a)->idx > f_last(*s_a) && (*s_b)->idx < f_last(*s_a))/*3e1b5h*/
    //             push_a(s_a, s_b);
    //         else if ((*s_a)->idx > (*s_b)->idx && (*s_a)->idx < f_last(*s_a) && (*s_b)->idx < f_last(*s_a))/*6e1b5h*/
    //             push_a(s_a, s_b);
    //     }
    // }

}