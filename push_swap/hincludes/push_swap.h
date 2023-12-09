/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:45:28 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/09 12:11:34 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/* * * * * * * * * * * * * * * * MAIN * * * * * * * * * * * * * * * * */
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);

/* * * * * * * * * * * * * * * * CHECKERS * * * * * * * * * * * * * * * * */
int		checkers(int argc, char **argv);
int		arg_duplicate(int argc, char **argv);
int		arg_range(int argc, char **argv);
int		arg_is_int(int argc, char **argv);
int		arg_order(int argc, char **argv);

/* * * * * * * * * * * * * * * * ERROR * * * * * * * * * * * * * * * * */
void	error_end(char *msg);

/* * * * * * * * * * * * * * * * STACKS * * * * * * * * * * * * * * * * */
void	free_stack(t_stack **stack);
int		get_stack_size(t_stack *stack);
void	stack_add(t_stack **stack, t_stack *new_node);
void	print_stack(t_stack *stack);
void	get_numbers(int argc, char **argv, t_stack **stack);

/* * * * * * * * * * * * * * * * ALGORITHM * * * * * * * * * * * * * * * * */
void	push_smallest(t_stack **stack_a, t_stack **stack_b);
void	push_next_smallest(t_stack **stack_a, t_stack **stack_b);
void	push_largest(t_stack **stack_a, t_stack **stack_b);
void	move_numbers(t_stack **stack_a, t_stack **stack_b);
void	sort_numbers(t_stack **stack_a, t_stack **stack_b, int *numbers, int n);

/* * * * * * * * * * * * * * * * MOVES * * * * * * * * * * * * * * * * * * */
/* - - - - - - - - - - - - - MOVES: SWAP - - - - - - - - - - - - - - */
t_stack	*stack_clone_node(t_stack *source);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);

/* - - - - - - - - - - - - - MOVES: PUSH - - - - - - - - - - - - - - */
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

/* - - - - - - - - - - - - - MOVES: ROTATE - - - - - - - - - - - - - */
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

/* * * * * * * * * * * * * * * ALGORITHM * * * * * * * * * * * * * * * * */
void    push_smallest(t_stack **stack_a, t_stack **stack_b);

#endif
