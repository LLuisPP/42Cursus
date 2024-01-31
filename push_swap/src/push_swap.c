/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/31 16:42:07 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_swap commands the algorithm to order the input s */
void	push_swap(t_s **s_a, t_s **s_b, int size)
{
		alg_selector(s_a, s_b, size);

}

/* main handles inputs, calls PS, prints and free memory */
int	main(int argc, char **argv)
{
	t_s	*s_a;
	t_s	*s_b;
	int	size;

	s_a = NULL;
	s_b = NULL;
	if (argc < 2)
		error_end("");
	else if (argc == 2 && (checkers(argc, argv) == 1))
	{
		get_nbrs(argc, argv, &s_a);
		error_end("Error\n");
	}
	checkers(argc, argv);
	get_nbrs(argc, argv, &s_a);
		// ft_printf("║ s_a INPUT (%d) ═▶", s_size(s_a));
		// print_s(s_a);
		// print_idx_status(s_a);
	idx_s(s_a, 1);
		// print_idx_status(s_a);
		// ft_printf("╚═══════════════════════════════════════════════ INIT\n");
	size = s_size(s_a);
	push_swap(&s_a, &s_b, size);
		// ft_printf("╔═════════════════════════════════════════════ FINAL\n");
		// ft_printf("║ s_a OUTPUT (%d)-> ", s_size(s_a));
		// print_s(s_a);
		// // print_idx_status(s_a);
		// ft_printf("║ s_b OUTPUT (%d)-> ", s_size(s_b));
		// print_s(s_b);
		// print_s(s_a);
		// ft_printf("[%d] STACK EN ORDEN? [%d]\n", s_order(s_a), s_order(s_a));
	free_s(&s_a);
	free_s(&s_b);
	return (0);
}
 
/*************************************************************************
required: sort   3 numbers with <=     3 operations	  < - avg 1,5 - - OK

required: sort   5 numbers with <=    12 operations	  < - avg 7 - - - OK

scored:   sort 100 numbers with <=   700 operations  max score
                                     900 operations   
                                    1100 operations   < - avg 794 - - OK
                                    1300 operations
                                    1500 operations  min score
								
scored:   sort 500 numbers with <=  5500 operations  max score
                                    7000 operations
                                    8500 operations   < - avg 7600- - OK
                                   10000 operations
                                   11500 operations  min score
**************************************************************************/