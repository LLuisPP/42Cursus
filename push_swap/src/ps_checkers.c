/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:03:25 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/23 10:34:29 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* arg_is_int checks input values are ints (-,+) & diff from NULL or '\0' */
int	arg_is_int(int argc, char **argv)
{
	long	i;
	long	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i] == NULL || !argv[i] || argv[i][j] == '\0')
			return (0);
		if (argv[i][j] == '-' && (ft_isdigit(argv[i][j + 1]) == 1))
			j++;
		if (argv[i][j] == '+' && (ft_isdigit(argv[i][j + 1]) == 1))
			j++;
		while (ft_isdigit(argv[i][j]) == 1 && argv[i][j] != '\0')
			j++;
		if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '\0')
			return (0);
		i++;
	}
	return (1);
}

/* arg_range checks if input is inside the max and min C handle values */
int	arg_range(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == 0)
		{
			while (argv[i][j + 1] == '0')
				j++;
			if ((ft_strlen(argv[i]) - j) > 12)
				return (0);
		}
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

/* arg_duplicate checks if input has any duplicate value */
int	arg_duplicate(int argc, char **argv)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* arg_order checks if inputs are alredy in order */
int	arg_order(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc -1)
	{
		if (ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
			++i;
		else
			return (1);
	}
	return (0);
}

/* checkers handle de result of checkers and return desired error */
int	checkers(int argc, char **argv)
{
	if (arg_is_int(argc, argv) != 1)
		error_end("Error\n");
	if (arg_range(argc, argv) != 1)
		error_end("Error\n");
	if (arg_duplicate(argc, argv) != 1)
		error_end("Error\n");
	if (arg_order(argc, argv) != 1)
		error_end("Error\n");
	return (1);
}
