/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/12 17:01:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_swap commands the algorithm to order the input stack */

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	smallest_a;

	ft_printf("stack size -> %d\n", stack_size);
	smallest_a = find_lowest(*stack_a);
	find_highest(*stack_a);
	push_b(stack_b, stack_a);
	rotate_a(stack_a);
	print_stack(*stack_a);
	push_a(stack_a, stack_b);
	print_stack(*stack_b);
	push_b(stack_b, stack_a);

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
	ft_printf("\n>>> CORRECT PARAMS! <<<\nv v v v v v v v v v v v\n\n");
	get_numbers(argc, argv, &stack_a);
	ft_printf("stack a -> ");
	print_stack(stack_a);
	ft_printf("stack b -> ");
	print_stack(stack_b);
	stack_size = get_stack_size(stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	ft_printf("stack a -> ");
	print_stack(stack_a);
	ft_printf("stack b -> ");
	print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
