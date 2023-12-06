/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/06 21:05:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void push_swap(t_stack **stack_a, int stack_size)
{
	if (stack_a)
		stack_size = stack_size + 1;
		stack_size = stack_size - 1;
}


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		stack_size;

	stack_a = NULL;
	if (argc < 2)
		error_end(">  Error - (Too few arguments)\n");
	checkers(argc, argv);
	ft_printf(">>> CORRECT INPUT PARAMS <<<\n    ⟱ ⟱ ⟱ ⟱ ⟱ ⟱ ⟱ ⟱ ⟱ ⟱\n");
	get_numbers(argc, argv, &stack_a);
	print_stack(stack_a);
	stack_size = get_stack_size(stack_a);
	push_swap(&stack_a, stack_size);
	ft_printf("stack size -> %d\n", stack_size);
	free_stack(&stack_a);
return (0);
}