/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:21:23 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/12 13:28:58 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* free_stack frees every element and set the pointer to NULL */

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/* stack_add adds new values to a stack */

void	stack_add(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!new_node)
		return ;
	if (!*stack)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
	}
}

/* print_stack to print complete stack to identify problems */

void	print_stack(t_stack *stack)
{
	ft_printf("Stack: ");
	while (stack != NULL)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

/* get_numbers fill the stack and checks if its correct */

void	get_numbers(int argc, char **argv, t_stack **stack)
{
	long	i;
	int		value;
	t_stack	*new_node;

	i = 1;
	while (i < argc)
	{
		value = atoi(argv[i]);
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			error_end("Error - Memory allocation failed\n");
		new_node->value = value;
		new_node->next = NULL;
		stack_add(stack, new_node);
		i++;
	}
}

/*Tenemos para index que hemos iniciado a 0 buscar en valor mas peque
y asignar un index y asi consecitivo*/

/* get_stack_size counts elements in a stack */
int	get_stack_size(t_stack *stack)
{
	int		stack_size;
	t_stack	*temp;

	temp = stack;
	stack_size = 0;
	if (!temp)
		return (0);
	while (temp)
	{
		stack_size++;
		temp = temp->next;
	}
	return (stack_size);
}
