/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:01 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/19 18:52:24 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	is_overflow(t_msh *msh, char *str)
{
	int			i;
	long long	num;
	long long	prev;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		prev = num;
		num = num * 10 + (str[i] - '0');
		if (num < prev)
			handle_exit_error(msh, str);
		i++;
	}
}

static void	handle_numeric_arg(t_msh *msh, char *arg)
{
	long long	exit_code;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	exit_code = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	while (arg[i])
	{
		exit_code = exit_code * 10 + (arg[i] - '0');
		i++;
	}
	exit_code = exit_code * sign;
	msh->last_exit_code = (exit_code % 256 + 256) % 256;
}

static int	is_numeric_arg(t_msh *msh, char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		handle_exit_error(msh, str);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (2);
	}
	if (!str[i])
		return (2);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (2);
		i++;
	}
	return (1);
}

void	ft_exit(t_msh *msh)
{
	if (msh == NULL)
		exit(1);
	if (msh->tkns == NULL || msh->tkns->args == NULL
		|| msh->tkns->args[1] == NULL)
	{
		write(STDERR_FILENO, "exit\n", 5);
		free_structs(msh->env, msh->tkns, msh->mpip);
		exit(msh->last_exit_code);
	}
	if (msh->tkns->args[2] != NULL)
	{
		write(STDERR_FILENO, "minishell: exit: too many arguments\n", 36);
		msh->last_exit_code = 1;
		return ;
	}
	if (is_numeric_arg(msh, msh->tkns->args[1]) != 1)
		handle_exit_error(msh, msh->tkns->args[1]);
	is_overflow(msh, msh->tkns->args[1]);
	handle_numeric_arg(msh, msh->tkns->args[1]);
	write(STDERR_FILENO, "exit\n", 5);
	free_structs(msh->env, msh->tkns, msh->mpip);
	exit(msh->last_exit_code);
}
