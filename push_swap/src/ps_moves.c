/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:55:31 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/08 15:20:52 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para clonar un nodo
t_stack *stack_clone_node(t_stack *source)
{
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        exit(EXIT_FAILURE);

    new_node->value = source->value;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

// Función para hacer swap en la pila a (sa)
void swap_a(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next)
    {
        t_stack *temp = (*stack_a)->next;
        (*stack_a)->next = temp->next;
        temp->prev = NULL;
        temp->next = *stack_a;
        (*stack_a)->prev = temp;
        *stack_a = temp;
    }
}

// Función para hacer swap en la pila b (sb)
void swap_b(t_stack **stack_b)
{
    if (*stack_b && (*stack_b)->next)
    {
        t_stack *temp = (*stack_b)->next;
        (*stack_b)->next = temp->next;
        temp->prev = NULL;
        temp->next = *stack_b;
        (*stack_b)->prev = temp;
        *stack_b = temp;
    }
}

// Función para hacer swap simultáneo en las pilas a y b (ss)
void swap_both(t_stack **stack_a, t_stack **stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
}

// Función para hacer push de la pila b a la pila a (pa)
void push_a(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_b)
    {
        t_stack *new_node = stack_clone_node(*stack_b);
        stack_add(stack_a, new_node);

        t_stack *temp = *stack_b;
        *stack_b = (*stack_b)->next;
        free(temp);

        if (*stack_b)
            (*stack_b)->prev = NULL;
    }
}

// Función para hacer push de la pila a a la pila b (pb)
void push_b(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a)
    {
        t_stack *new_node = stack_clone_node(*stack_a);
        stack_add(stack_b, new_node);

        t_stack *temp = *stack_a;
        *stack_a = (*stack_a)->next;
        free(temp);

        if (*stack_a)
            (*stack_a)->prev = NULL;
    }
}

// Función para rotar hacia arriba la pila a (ra)
void rotate_a(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next)
    {
        t_stack *temp = *stack_a;
        *stack_a = (*stack_a)->next;
        (*stack_a)->prev = NULL;

        t_stack *current = *stack_a;
        while (current->next != NULL)
            current = current->next;

        temp->prev = current;
        temp->next = NULL;
        current->next = temp;
    }
}

// Función para rotar hacia arriba la pila b (rb)
void rotate_b(t_stack **stack_b)
{
    if (*stack_b && (*stack_b)->next)
    {
        t_stack *temp = *stack_b;
        *stack_b = (*stack_b)->next;
        (*stack_b)->prev = NULL;

        t_stack *current = *stack_b;
        while (current->next != NULL)
            current = current->next;

        temp->prev = current;
        temp->next = NULL;
        current->next = temp;
    }
}

// Función para rotar simultáneamente las pilas a y b (rr)
void rotate_both(t_stack **stack_a, t_stack **stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
}

// Función para rotar hacia abajo la pila a (rra)
void reverse_rotate_a(t_stack **stack_a)
{
    if (*stack_a && (*stack_a)->next)
    {
        t_stack *current = *stack_a;
        while (current->next != NULL)
            current = current->next;

        t_stack *temp = current;
        current = current->prev;
        current->next = NULL;

        temp->prev = NULL;
        temp->next = *stack_a;
        (*stack_a)->prev = temp;
        *stack_a = temp;
    }
}
void reverse_rotate_b(t_stack **stack_b)
{
    if (*stack_b && (*stack_b)->next)
    {
        t_stack *current = *stack_b;
        while (current->next != NULL)
            current = current->next;

        t_stack *temp = current;
        current = current->prev;
        current->next = NULL;

        temp->prev = NULL;
        temp->next = *stack_b;
        (*stack_b)->prev = temp;
        *stack_b = temp;
    }
}

// Función para rotar simultáneamente las pilas a y b (rrr)
void reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
}