/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/04 09:35:36 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void push_swap(t_stack **stack_a, int stack_size)
{
	if (stack_a)
		stack_a++;
	ft_printf("%d\n", stack_size);
}


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	// t_stack	*stack_b = NULL;
	stack_a = NULL;
	int		stack_size;
	int		i;

	if (argc < 2)
		error_end(">  Error - (Too few arguments)\n");
	checkers(argc, argv);
	ft_printf("CORRECT INPUT PARAMS \n");
	i = 0;
	ft_printf("stack_a print %d \n", stack_a);
	
	while (i < argc - 1)
	{
		ft_printf("main get_numbersmak while \n");
		get_numbers(argv[i], stack_a);
		i++;
	}
	stack_size = get_stack_size(stack_a);
	ft_printf("Stack size -> %d\n", stack_size);
	push_swap(&stack_a, stack_size);
	
	free_stack(&stack_a);
	// free_stack(&stack_b);
return (0);
}