/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:01 by lauriago          #+#    #+#             */
/*   Updated: 2024/11/03 12:14:53 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric_arg(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
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
	msh->end_sig = (exit_code % 256 + 256) % 256;
}

static void	handle_exit_error(t_msh *msh, char *arg)
{
	ft_fd_printf(2, "exit\n");
	ft_fd_printf(2, "minishell: exit: %s: numeric argument required\n", arg);
	free_structs(msh->env, msh->tkns, msh->mpip);
	msh->end_sig = 2;
	exit(msh->end_sig);
}

void	ft_exit(t_msh *msh)
{
	ft_fd_printf(1, "exit\n");
	if (!msh->tkns[1].cmd)
	{
		msh->end_sig = 0;
		exit(msh->end_sig);
	}
	if (!is_numeric_arg(msh->tkns[1].cmd))
		handle_exit_error(msh, msh->tkns[1].cmd);
	if (msh->tkns[2].cmd)
	{
		ft_fd_printf(2, "minishell: exit: too many arguments\n");
		msh->end_sig = 1;
		return ;
	}
	handle_numeric_arg(msh, msh->tkns[1].cmd);
	exit(msh->end_sig);
}
