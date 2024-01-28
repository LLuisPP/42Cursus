/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/27 12:41:58 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_swap commands the algorithm to order the input stack */
void	push_swap(t_stack **stack_a, t_stack **stack_b, int s_size)
{
		alg_selector(stack_a, stack_b, s_size);
		// chnk_size(stack_a, stack_b, s_size, 10, 4);
		// ft_printf(">>>>  <> <> <> <> <>  >>>>>>%d\n", cheaper_mv(stack_a, (cheaper_fr(stack_a, f_chk_v(*stack_a, 10), f_chk_vr(*stack_a, 10)))));
		// ft_printf(">>>>%d\n", s_size);
		// print_stack(*stack_b);

}

/* main handles inputs, calls PS, prints and free memory */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		s_size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		error_end("");
	else if (argc == 2 && (checkers(argc, argv) == 1))
	{
		get_numbers(argc, argv, &stack_a);
		error_end("Error\n");
	}
	checkers(argc, argv);
	get_numbers(argc, argv, &stack_a);
		ft_printf("║ STACK_A INPUT (%d) ═▶", stack_size(stack_a));
		print_stack(stack_a);
		// print_index_status(stack_a);
	index_s(stack_a, 1);
		// // print_index_status(stack_a);
		// ft_printf("╚═══════════════════════════════════════════════ INIT\n");
	s_size = stack_size(stack_a);
	push_swap(&stack_a, &stack_b, s_size);
		ft_printf("╔═════════════════════════════════════════════ FINAL\n");
		ft_printf("║ STACK_A OUTPUT (%d)-> ", stack_size(stack_a));
		print_stack(stack_a);
		// print_index_status(stack_a);
		ft_printf("║ STACK_B OUTPUT (%d)-> ", stack_size(stack_b));
		print_stack(stack_b);
		// print_index_status(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
 
/*****************************************************************************
required: sort   3 numbers with <=     3 operations				//
required: sort   5 numbers with <=    12 operations				//
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