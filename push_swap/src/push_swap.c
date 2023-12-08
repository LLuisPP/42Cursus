/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/08 19:47:26 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, int stack_size)
{
	swap_a(stack_a);
    ft_printf("stack size de ps -> %d\n", stack_size);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_a = NULL;
	if (argc < 2)
		error_end("");
	else if (argc == 2)
		error_end("> Done - (Stack in order)\n");
	checkers(argc, argv);
	ft_printf("\n>>> CORRECT PARAMS! <<<\nv v v v v v v v v v v v\n\n");
	get_numbers(argc, argv, &stack_a);
	get_numbers(argc, argv, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	stack_size = get_stack_size(stack_a);
	push_swap(&stack_a, stack_size);
	ft_printf("stack size -> %d\n", stack_size);
	free_stack(&stack_a);
	return (0);
}
