/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:45:28 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/21 22:40:41 by lprieto-         ###   ########.fr       */
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
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/* * * * * * * * * * * * * * * * MAIN * * * * * * * * * * * * * * * * */
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);

/* * * * * * * * * * * * * * * * CHECKERS * * * * * * * * * * * * * * * * */
int		arg_is_int(int argc, char **argv);
int		arg_range(int argc, char **argv);
int		arg_duplicate(int argc, char **argv);
int		arg_order(int argc, char **argv);
int		checkers(int argc, char **argv);


/* * * * * * * * * * * * * * * * STACKS * * * * * * * * * * * * * * * * */
void	free_stack(t_stack **stack);
void	stack_add(t_stack **stack, t_stack *new_node);
void	get_numbers(int argc, char **argv, t_stack **stack);
int		get_stack_size(t_stack *stack);
void	stack_add_top(t_stack **stack, t_stack *new_node);

/* * * * * * * * * * * * * * * * HARDCODEOS * * * * * * * * * * * * * * * * */
void	reverse_order(int argc, char **argv, t_stack **stack_a);

/* * * * * * * * * * * * * * * * MOVES * * * * * * * * * * * * * * * * * * */
	/* - - - - - - - - - - - - - MV_SWAP - - - - - - - - - - - - - - */
t_stack	*stack_clone_node(t_stack *source);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
	/* - - - - - - - - - - - - - MV_PUSH - - - - - - - - - - - - - - */
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
	/* - - - - - - - - - - - - - MV_rot - - - - - - - - - - - - - */
void	rot_a(t_stack **stack_a);
void	rot_b(t_stack **stack_b);
void	rot_both(t_stack **stack_a, t_stack **stack_b);
	/* - - - - - - - - - - - - - MV_REV_rot - - - - - - - - - - - - - */
void	rev_rot_a(t_stack **stack_a);
void	rev_rot_b(t_stack **stack_b);
void	rev_rot_both(t_stack **stack_a, t_stack **stack_b);

/* * * * * * * * * * * * * * * * ALGORITHM * * * * * * * * * * * * * * * * */
void	alg_selector(t_stack **stack_a, t_stack **stack_b, int stack_size);
void	alg_3(t_stack **stack_a);
void	alg_4(t_stack **stack_a, t_stack **stack_b);
void	alg_5(t_stack **stack_a, t_stack **stack_b);

/* * * * * * * * * * * * * * * * VALIDATIONS * * * * * * * * * * * * * * * * */
int		stack_rev_order(t_stack *stack);
int		stack_order(t_stack *stack);
int		cheaper_mv(t_stack **stack, int target);

/* * * * * * * * * * * * * * * * PRINT_TOOLS * * * * * * * * * * * * * * * */
	/* * * * * * * * * * * * * * * * ERROR * * * * * * * * * * * * * * * * */
void	error_end(char *msg);
void	print_stack(t_stack *stack);
void	print_status(t_stack *stack_a, t_stack *stack_b);

/* * * * * * * * * * * * * * * * RANGE * * * * * * * * * * * * * * * * */
int		find_lowest(t_stack *stack);
int		find_highest(t_stack *stack);

#endif
