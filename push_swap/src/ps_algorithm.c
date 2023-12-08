/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:17:43 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/07 20:00:10 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_smallest(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_a && (*stack_a)->value > (*stack_b)->value)
    {
        swap_a(stack_a);
    }

    push_a(stack_a, stack_b);
}

void push_next_smallest(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_a)
    {
        if ((*stack_a)->value > (*stack_b)->value)
        {
            swap_a(stack_a);
            push_a(stack_a, stack_b);
            break;
        }

        swap_a(stack_a);
    }
}

void push_largest(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a)
    {
        swap_a(stack_a);
        push_a(stack_a, stack_b);
    }
}

void move_numbers(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        push_a(stack_a, stack_b);
    }
}

void sort_numbers(t_stack **stack_a, t_stack **stack_b, int *numbers, int n)
{
    int i;
   

    i = 0;
 
    while (i < n)
    {
        if (*(numbers + i) < *(numbers))
   
        i++;
    }
    // Coloca el número más pequeño en la parte superior de la pila a
    push_smallest(stack_a, stack_b);
    // Mientras la pila b no esté vacía
    while (*stack_b)
    {
      // Encuentra el siguiente número más pequeño en la pila a
        push_next_smallest(stack_a, stack_b);
    }
    // Mueve el número más grande a la pila b
    push_largest(stack_a, stack_b);
    // Mueve los números de la pila b a la pila a en orden
    move_numbers(stack_a, stack_b);
}