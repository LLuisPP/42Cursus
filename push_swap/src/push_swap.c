/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/20 11:42:43 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_swap commands the algorithm to order the input stack */
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	while (stack_order(*stack_a) == 0)
		alg_selector(stack_a, stack_b, stack_size);
}

/* main handles inputs, calls PS, prints and free memory */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		error_end("");
	else if (argc == 2 && (checkers(argc, argv) == 1))
	{
		get_numbers(argc, argv, &stack_a);
		error_end("> Done - (Stack in order)\n");
	}
	checkers(argc, argv);
	get_numbers(argc, argv, &stack_a);
	ft_printf("║ STACK_A INPUT ══▶ ");
	print_stack(stack_a);
	ft_printf("╚═══════════════════════════════════════════════ INIT\n");
	stack_size = get_stack_size(stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	ft_printf("\n╔═════════════════════════════════════════════ FINAL\n");
	ft_printf("║ STACK_A OUTPUT -> ");
	print_stack(stack_a);
	ft_printf("║ STACK_B OUTPUT -> ");
	print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

/*****************************************************************************
required: sort   3 numbers with <=     3 operations
required: sort   5 numbers with <=    12 operations
scored:   sort 100 numbers with <=   700 operations   max score
                                     900 operations
                                    1100 operations
                                    1300 operations
                                    1500 operations   min score
scored:   sort 500 numbers with <=  5500 operations   max score
                                    7000 operations
                                    8500 operations
                                   10000 operations
                                   11500 operations   min score
******************************************************************************/
