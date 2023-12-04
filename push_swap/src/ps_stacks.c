/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:21:23 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/04 09:36:20 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hincludes/push_swap.h"

/* creates nodes (elements) in the stack with input values */

t_stack *stack_new(int data)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if(!new)
        return(NULL);
    new->data = data,
    new->index = 0;
    new->prev = -1;
    new->next = NULL;
    return (new);
}

/* stack_add adds new values to a stack */

void	stack_add(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = get_bottom(*stack);
	bottom->next = new;
}

/* get_bottom puts the pointer in last pos of the stack */

t_stack	*get_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* get_numbers fill the stack and checks if its correct */

void	get_numbers(char *argv, t_stack *stack_a)
{
	char		**param;
	long int	n;
	int			i;

	write(1,"4124\n", 5);
	param = ft_split(argv, ' ');
	i = 0;
	while (param[i] != (void *)0)
	{
		write(1,"000\n", 5);
		n = ft_atoi(param[i]);
		stack_add(&stack_a, stack_new(n));
		i++;
	}
	write(1,"2\n", 2);
	free(param[i]);
	write(1,"3\n", 2);
	free(param);
}

/* get_stack_size counts elements in a stack */

int get_stack_size(t_stack *stack)
{
    int stack_size;

    stack_size = 0;
    if (!stack)
        return (0);
    while (stack)
    {
        stack = stack->next;
        stack_size++;
    }
    return (stack_size);
}