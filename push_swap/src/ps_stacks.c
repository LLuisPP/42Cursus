/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:21:23 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/24 09:15:20 by lprieto-         ###   ########.fr       */
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

/* get_numbers fill the stack and checks if its correct */
void	get_numbers(int argc, char **argv, t_stack **stack)
{
	long	i;
	int		value;
	t_stack	*new_node;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			error_end("Error\n");
		new_node->value = value;
		new_node->index = 0;
		new_node->next = NULL;
		stack_add(stack, new_node);
		i++;
		// free(&new_node);
	}
}

/* get_stack_size counts elements in a stack */
int	stack_size(t_stack *stack)
{
	int		stack_size;
	t_stack	*temp;

	temp = stack;
	stack_size = 0;
	if (!temp)
		return (0);
	while (temp && temp != NULL)
	{
		stack_size++;
		temp = temp->next;
	}
	return (stack_size);
}

/* stack_add adds new values to a stack */
void	stack_add_top(t_stack **stack, t_stack *new_node)
{
	if (!new_node)
		return ;
	if (!*stack)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
