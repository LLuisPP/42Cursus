/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:45:28 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 14:40:00 by lprieto-         ###   ########.fr       */
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

/* MAIN * * * * * * * * * * * * * * * * * */
void	push_swap(t_stack **stack_a, t_stack **stack_b, int s_size);
/* * * * * * * * * * * * * * * * CHECKERS * * * * * * * * * * * * * * * */
int		arg_is_int(int argc, char **argv);
int		arg_range(int argc, char **argv);
int		arg_duplicate(int argc, char **argv);
int		arg_order(int argc, char **argv);
int		checkers(int argc, char **argv);

/* STACKS * * * * * * * * * * * * * * * * */
void	free_stack(t_stack **stack);
void	stack_add(t_stack **stack, t_stack *new_node);
void	get_numbers(int argc, char **argv, t_stack **stack);
int		stack_size(t_stack *stack);
void	stack_add_top(t_stack **stack, t_stack *new_node);

/* HARDCODES * * * * * * * * * * * * * * * */
void	reverse_order(int argc, char **argv, t_stack **stack_a);

/* SWAP * * * * * * * * * * * * * * * */
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
/* PUSH * * * * * * * * * * * * * * * */
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
/* ROT * * * * * * * * * * * * * * * */
void	rot_a(t_stack **stack_a);
void	rot_b(t_stack **stack_b);
void	rot_both(t_stack **stack_a, t_stack **stack_b);
/* REV_ROT * * * * * * * * * * * * * * * */
void	rev_rot_a(t_stack **stack_a);
void	rev_rot_b(t_stack **stack_b);
void	rev_rot_both(t_stack **stack_a, t_stack **stack_b);

/* ALG_SELECTOR * * * * * * * * * * * * * * * */
void	chnk_size(t_stack **stack_a, t_stack **stack_b, int s_size ,int strt, int chunk);
void	alg_selector(t_stack **stack_a, t_stack **stack_b, int s_size);

/* ALGORITHMS * * * * * * * * * * * * * * * * */
void	alg_3(t_stack **stack_a);
void	alg_4(t_stack **stack_a, t_stack **stack_b);
void	alg_4_rev(t_stack **stack_a);
void	alg_5(t_stack **stack_a, t_stack **stack_b);
void	alg_5_rev(t_stack **stack_a, t_stack **stack_b);
void	alg_10(t_stack **stack_a, t_stack **stack_b, int s_size);
void	alg_10b(t_stack **stack_a, t_stack **stack_b);
void	alg_50(t_stack **stack_a, t_stack **stack_b, int s_size);
void	alg_100(t_stack **stack_a, t_stack **stack_b, int s_size);
void	alg_500(t_stack **stack_a, t_stack **stack_b, int s_size);

/* VALIDATE * * * * * * * * * * * * * * * */
int		stack_rev_order(t_stack *stack);
int		stack_order(t_stack *stack);
int		cheaper_mv(t_stack **stack, int target);
int		final_order(t_stack *stack);


/* PRINT_TOOLS * * * * * * * * * * * * * * * */
/* error - - - - - - - - - - - - - - */
void	error_end(char *msg);
/* prints - - - - - - - - - - - - - - */
void	print_stack(t_stack *stack);
void	print_status(t_stack *stack_a, t_stack *stack_b);
void	print_index_status(t_stack *stack);

/* RANGE * * * * * * * * * * * * * * * * */
int		find_h_i(t_stack *stack);
int		find_l_i(t_stack **stack);
int		f_lowidx(t_stack **stack);
int		find_lowest(t_stack *stack);
int		find_highest(t_stack *stack);

/* * * * * * * * * * * * * * * * OPTIMIZER * * * * * * * * * * * * * * * */
void	index_s(t_stack *stack, int i);
int		all_indexed(t_stack **stack);
void	index_change(t_stack **stack, int lowest_index, int i);
int		f_last(t_stack *stack);
int		f_chk_v(t_stack *stack, int strt);
int		f_chk_vr(t_stack *stack, int i);
int		cheaper_fr(t_stack **stack, int targetA, int targetB);

#endif
