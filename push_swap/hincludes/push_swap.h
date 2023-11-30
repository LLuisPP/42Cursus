/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:45:28 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/30 13:40:03 by lprieto-         ###   ########.fr       */
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
	int	data;
	int	index;
	int	stack_size;
}	t_stack;

int checkers(int argc, char **argv);
void	error_exit(char *msg);
int		arg_duplicate(int argc, char **argv);
int		arg_range(int argc, char **argv);
int		arg_is_int(int argc, char **argv);

#endif
