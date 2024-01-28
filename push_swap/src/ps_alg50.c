/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg50.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:35:17 by user              #+#    #+#             */
/*   Updated: 2024/01/28 15:27:37 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_50(t_stack **stack_a, t_stack **stack_b, int s_size)
{
    // int count;
    
    // count = 0;
	chnk_size(stack_a, stack_b, s_size, 10, 4);
	alg_5(stack_a, stack_b);
    // while ((stack_b != NULL && stack_size(*stack_b) != 0 && stack_a != NULL) || (stack_order(*stack_a) != 1 && stack_size(*stack_b) != 0))
    // {
    //     while (f_last(*stack_a) == find_highest(*stack_a) && stack_size(*stack_a) != s_size)
    //     {
    //         if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index < f_last(*stack_a))/*Me3b1h*/
    //         {
    //              while ((*stack_a)->index != (*stack_a)->next->index + 1)
    //             {
    //                 rot_a(stack_a);
    //                 count++;
    //             }
    //             push_a(stack_a, stack_b);
    //             // swap_a(stack_a);
    //             while (count != 0 || (final_order(*stack_a) != 1 || stack_order(*stack_a)))
    //             {
    //                 rev_rot_a(stack_a);
    //                 count--;
    //             }
    //         }
    //         else if ((*stack_a)->index > (*stack_b)->index && (*stack_a)->index < f_last(*stack_a))/*Me1b3h*/
    //         {
	// 			push_a(stack_a, stack_b);
	// 		}
    //     }
    //     while (f_last(*stack_a) != find_highest(*stack_a))
    //     {
    //         if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index < f_last(*stack_a) && (*stack_b)->index < f_last(*stack_a))/*5e3b1h*/
    //         {
    //             while ((*stack_a)->index != (*stack_a)->next->index + 1)
    //             {
    //                 rot_a(stack_a);
    //                 count++;
    //             }
    //             push_a(stack_a, stack_b);
    //             swap_a(stack_a);
    //             while (count != 0 || (final_order(*stack_a) != 1 || stack_order(*stack_a)))
    //             {
    //                 rev_rot_a(stack_a);
    //                 count--;
    //             }
    //         }
    //         else if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index < f_last(*stack_a) && (*stack_b)->index > f_last(*stack_a))/*5e6b1h*/
    //         {
    //             rev_rot_a(stack_a);
    //             push_a(stack_a, stack_b);
    //         }
    //         else if ((*stack_a)->index < (*stack_b)->index && (*stack_a)->index > f_last(*stack_a) && (*stack_b)->index > f_last(*stack_a))/*3e5b4h*/
    //         {
    //              while ((*stack_a)->index != (*stack_a)->next->index + 1)
    //             {
    //                 rot_a(stack_a);
    //                 count++;
    //             }
    //             push_a(stack_a, stack_b);
    //             swap_a(stack_a);
    //             while (count != 0 || (final_order(*stack_a) != 1 || stack_order(*stack_a)))
    //             {
    //                 rev_rot_a(stack_a);
    //                 count--;
    //             }
    //         }
    //         else if ((*stack_a)->index > (*stack_b)->index && (*stack_a)->index > f_last(*stack_a) && (*stack_b)->index > f_last(*stack_a))/*1e3b5h*/
    //             push_a(stack_a, stack_b);
    //         else if ((*stack_a)->index > (*stack_b)->index && (*stack_a)->index > f_last(*stack_a) && (*stack_b)->index < f_last(*stack_a))/*3e1b5h*/
    //             push_a(stack_a, stack_b);
    //         else if ((*stack_a)->index > (*stack_b)->index && (*stack_a)->index < f_last(*stack_a) && (*stack_b)->index < f_last(*stack_a))/*6e1b5h*/
    //             push_a(stack_a, stack_b);
    //     }
    // }
}