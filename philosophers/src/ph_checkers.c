/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:34:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/10 10:46:34 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	ft_atol(const char *str)
{
	long			i;
	long long int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr);
}

int	ft_isdigit(char *str)
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

	i = 0;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
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
		if (!argv[i] || argv[i][j] == '\0')
			return (-1);
		else if (argv[i][j] == '+' && argv[i][j + 1] != 0)
			j++;
		else if (argv[i][j] == '-' && (ft_isdigit(&argv[i][++j]) == 0))
			return (-1);
		while (ft_isdigit(&argv[i][j]) == 0 && argv[i][j] != '\0')
			j++;
		if (ft_isdigit(&argv[i][j]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	arg_chck(int argc, char **argv)
{
	if (arg_is_int(argc, argv) != 0)
		return (-1);
	if (ft_arg_range(argc, argv) != 0)
		return (-1);
	return (0);
}
