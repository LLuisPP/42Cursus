/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:45:28 by lprieto-          #+#    #+#             */
/*   Updated: 2023/12/04 09:26:18 by lprieto-         ###   ########.fr       */
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

typedef struct s_stack
{
	int				data;
	int				index;
	int				prev;
	struct s_stack	*next;
}	t_stack;

/* * * * * * * * * * * * * * * * MAIN * * * * * * * * * * * * * * * * */
void	push_swap(t_stack **stack_a, int stack_size);

/* * * * * * * * * * * * * * * * CHECKERS * * * * * * * * * * * * * * * * */
int 	checkers(int argc, char **argv); /* solo hace falta este */
int		arg_duplicate(int argc, char **argv);
int		arg_range(int argc, char **argv);
int		arg_is_int(int argc, char **argv);

/* * * * * * * * * * * * * * * * ERROR * * * * * * * * * * * * * * * * */
void	error_end(char *msg);

/* * * * * * * * * * * * * * * * UTILS * * * * * * * * * * * * * * * * */
void    free_stack(t_stack **stack);

/* * * * * * * * * * * * * * * * STACKS * * * * * * * * * * * * * * * * */
int 	get_stack_size(t_stack *stack);
void	stack_add(t_stack **stack, t_stack *new);
t_stack	*get_bottom(t_stack *stack);
void	get_numbers(char *argv, t_stack *stack_a);
t_stack *stack_new( int data);

#endif
