/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 17:38:03 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_swap commands the algorithm to order the input s */
void	push_swap(t_s **s_a, t_s **s_b, int size)
{
		alg_selector(s_a, s_b, size);
		// chnk_size(s_a, s_b, size, 10, 4);
		// ft_printf(">>>>  <> <> <> <> <>  >>>>>>%d\n", cheaper_mv(s_a, (cheaper_fr(s_a, f_chk_v(*s_a, 10), f_chk_vr(*s_a, 10)))));
		// ft_printf(">>>>%d\n", size);
		// print_s(*s_b);

}

/* main handles inputs, calls PS, prints and free memory */
int	main(int argc, char **argv)
{
	t_s	*s_a;
	t_s	*s_b;
	int		size;

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
		ft_printf("╔═════════════════════════════════════════════ FINAL\n");
		ft_printf("║ s_a OUTPUT (%d)-> ", s_size(s_a));
		print_s(s_a);
		// print_idx_status(s_a);
		ft_printf("║ s_b OUTPUT (%d)-> ", s_size(s_b));
		print_s(s_b);
		// print_idx_status(s_b);
	free_s(&s_a);
	free_s(&s_b);
	return (0);
}
 
/*****************************************************************************
required: sort   3 numbers with <=     3 operations				//
required: sort   5 numbers with <=    12 operations				//
scored:   sort 100 numbers with <=   700 operations   max score
                                     900 operations
                                    1100 operations
                                    1300 operations
                                    1500 operations   min score
scored:   sort 500 numbers with <=  5500 operations   max score
                                    7000 operations
                                    8500 operations
                                   10000 operations
                                   11500 operations   min score
******************************************************************************/