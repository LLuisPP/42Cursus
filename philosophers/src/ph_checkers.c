/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:34:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/17 17:31:42 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	ft_atol(const char *str)
{
	long			i;
	long long int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr);
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_arg_range(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	arg_is_int(int argc, char **argv)
{
	long	i;
	long	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ' || argv[i][j] == '\t')
			j++;
		if (!argv[i] || argv[i][j] == '\0')
			return (-1);
		else if (argv[i][j] == '+' && argv[i][j + 1] != 0)
			j++;
		else if (argv[i][j] == '-' && (ft_is_digit(&argv[i][++j]) == 0))
			return (-1);
		while (ft_is_digit(&argv[i][j]) == 0 && argv[i][j] != '\0')
			j++;
		if (ft_is_digit(&argv[i][j]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	arg_check(int argc, char **argv)
{
	if (arg_is_int(argc, argv) != 0)
		return (-1);
	if (ft_arg_range(argc, argv) != 0)
		return (-1);
	return (0);
}
