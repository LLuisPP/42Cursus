/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/29 14:56:28 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void    print_error(char *msg)
{
    ft_putstr_fd(msg, 2);
    ft_puchar('\n');
    exit(0);
}

int num_check(char *stackA)
{
    int i;

    i = 0;
    while ((stackA[i]))
    {
        if (!ft_isdigit(stackA[i]) == -1)
            print_error("There is at least one non digit in the stack");
        i++;
    }
    return (1);
}
char    push_swap(int argc, char **argv)
{
    if (argc <= 0)
        return (0);
    if (num_check(argv) == -1)
        return (0);
    
    return (0);
}