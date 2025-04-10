/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:01 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/10 01:23:14 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	is_overflow(t_msh *msh, char *str)
{
	int			i;
	int			sign;
	long long	num;
	long long	prev;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') * -2 + 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		prev = num;
		num = num * 10 + (str[i++] - '0');
		if (num < prev)
			handle_exit_error(msh, str);
	}
	if ((sign == 1 && num < 0) || (sign == -1 && num > 0))
		handle_exit_error(msh, str);
}

static void	is_numeric_arg(t_msh *msh, char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		handle_exit_error(msh, str);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		handle_exit_error(msh, str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			handle_exit_error(msh, str);
		i++;
	}
	if (!str[i])
		handle_exit_error(msh, str);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
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
	exit_code *= sign;
	msh->last_exit_code = (exit_code % 256 + 256) % 256;
}

void	ft_exit(t_msh *msh)
{
	if (!msh)
		exit(1);
	if (!msh->tkns || !msh->tkns->args || !msh->tkns->args[1])
		exit(msh->last_exit_code);
	is_numeric_arg(msh, msh->tkns->args[1]);
	is_overflow(msh, msh->tkns->args[1]);
	if (msh->tkns->args[2])
	{
		write(STDERR_FILENO, "exit: too many arguments\n", 25);
		msh->end_sig = 1;
		return ;
	}
	handle_numeric_arg(msh, msh->tkns->args[1]);
	write(STDERR_FILENO, "exit\n", 5);
	free_structs(msh->env, msh->tkns, msh->mpip);
	exit(msh->last_exit_code);
}
