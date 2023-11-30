/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/30 12:42:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	// t_stack	*stack_a = NULL;
	// t_stack	*stack_b = NULL;
	int		stack_size;

	if (argc < 2)
		error_exit("Too few arguments");
	
	stack_size = (argc - 1);
	checkers(argc, argv);
	ft_printf("hola \n");
	// if (i == 1)
	// {
	
	// 	while (i < argc)
	// 	{
	// 		i++;
	// 		checkers(argc, argv);
	// 		ft_printf("%d\n", argv);
	// 	}
	// }
	/*LIBERAR LOS STAKCS AQUI*/
	return (0);
}