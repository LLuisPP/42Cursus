/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:42:21 by user              #+#    #+#             */
/*   Updated: 2023/12/20 11:21:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* checkers handle de result of checkers and return desired error */
int	checkers(int argc, char **argv)
{
	if (arg_is_int(argc, argv) != 1)
		error_end(">  Error - (Not a Number)\n");
	if (arg_range(argc, argv) != 1)
		error_end(">  Error - (Out of range)\n");
	if (arg_duplicate(argc, argv) != 1)
		error_end(">  Error - (Duplicated Values)\n");
	if (arg_order(argc, argv) != 1)
		error_end(">  \n");
	if (arg_rev_order(argc, argv) != 1)
	{
		ft_printf("reverse order numbers\n");
		return (1);
	}
	return (1);
}

int	cheaper_mv(t_stack **stack, int target)
{
	int		r_count;
	int		rr_count;
	t_stack	*current;

	r_count = 0;
	rr_count = 0;
	current = *stack;
	while (current->value != target)
	{
		current = current->next;
		r_count++;
	}
	current = *stack;
	while (current->next->value != target) 
	{
		current = current->next;
		rr_count++;
	}
	if (r_count <= rr_count)
		return (1);
	else
		return (0);
}
