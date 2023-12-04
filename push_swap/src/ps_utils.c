/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:55:58 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/01 21:11:06 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

/* free_stack frees every element and set the pointer to NULL */

void    free_stack(t_stack **stack)
{
    t_stack *tmp;

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

/*  */
