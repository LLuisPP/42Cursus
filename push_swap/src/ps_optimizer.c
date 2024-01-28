/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:59:07 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/26 10:33:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheaper_fr(t_stack **stack, int targetA, int targetB)
{
	int		F_count;
    int		R_count;
	t_stack	*current;

	if (targetA == targetB)
	{
		ft_printf("[[[[[[%d]]]]]]", targetA);
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
	if ((stack_size(*stack) - F_count) >= R_count)
	{
		{
			ft_printf("TARGET DERECHA >>>>>>: %d\n", targetB);
			ft_printf("TARGET IZQUIERDA: %d\n", targetA);
			return (targetB);
		}
	}
	else
	{
		ft_printf("TARGET IZQUIERDA >>>>: %d\n", targetA);
		ft_printf("TARGET DERECHA: %d\n", targetB);
		return (targetA);
	}
}
