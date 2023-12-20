/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:01:15 by user              #+#    #+#             */
/*   Updated: 2023/12/20 12:19:32 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* error_end output msg error after checking all stacks are clearead */
void	error_end(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(0);
}

/* print_stack to print complete stack to identify problems */
void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_status(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("╔═══════ ◀═\n");
	ft_printf("║ stack a -> ");
	print_stack(stack_a);
	ft_printf("║ stack b -> ");
	print_stack(stack_b);
	ft_printf("╚═══════ ═▶\n");
}
