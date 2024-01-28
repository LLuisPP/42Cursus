/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:59:07 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 15:23:33 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheaper_fr(t_stack **stack, int targetA, int targetB)
{
	int		F_count;
    int		R_count;
	t_stack	*current;
	if (targetA == 0 && targetB != 0)
		return (targetB);
	if (targetB == 0 && targetA != 0)
		return (targetA);
	if (targetA == targetB)
	{
		ft_printf("\n[[[[[[%d]]]]]]\n", targetA);
		return (targetA);
	}
	ft_printf("Wich one is closer, F:%d vs R:%d ? ", targetA, targetB);
	F_count = 0;
    R_count = 0;
	current = *stack;
	while (current->index != targetA)
	{
		current = current->next;
		F_count++;
	}
    current = *stack;
    while (current && current->next != NULL)
		current = current->next;
    while (current->index != targetB)
	{
		current = current->prev;
		R_count++;
	}
    current = *stack;
	if (F_count == stack_size(*stack) && R_count == stack_size(*stack))
		return (0);   
	if (F_count == 0)
		return (targetA);
	else if (R_count == 0)
		return (targetB);
	if (F_count <= R_count)
	{
		{
			ft_printf("L: [%d] <|", targetA);
			ft_printf(" %d :R\n", targetB);
			return (targetA);
		}
	}
	else
	{
			ft_printf("L: %d  |", targetA);
			ft_printf("> [%d] :R\n", targetB);
		return (targetB);
	}
}
