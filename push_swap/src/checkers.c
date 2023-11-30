/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:03:25 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/30 13:40:02 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(0);
}

int	arg_is_int(int argc, char **argv)
{
	long	i;
	long	j;

	i = 1;
	while (i < argc)
    {	
		j = 0;
		if (argv[i] == NULL || !argv[i] || argv[i][j] == '\0') /*OJO AL NULL*/
			return (0);
		if (argv[i][j] == '-' && (ft_isdigit(argv[i][j + 1]) == 1))
			j++;
		while (ft_isdigit(argv[i][j]) == 1 && argv[i][j] != '\0')
			j++;
		if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '\0')
			return (0);
		i++;
	}	
	return(1);
}

int	arg_range(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (0);
		i++;
	}	
	return (1);
}

int arg_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return(0);
			j++;
		}
		i++;
	}
	return (1);
}

int checkers(int argc, char **argv)
{
	if(arg_is_int(argc, argv) != 1)
		error_exit("Not a Number\n");
    if(arg_range(argc, argv) != 1)
		error_exit("Out of range\n");
    if(arg_duplicate(argc, argv) != 1)
		error_exit("Duplicated arguments\n");
    return (1);
}
