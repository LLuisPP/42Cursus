/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:37 by lauriago          #+#    #+#             */
/*   Updated: 2024/11/01 20:52:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	remove_var_from_env(t_msh *msh, int pos)
{
	free(msh->env->values[pos]);
	free(msh->env->names[pos]);
	while (msh->env->names[pos])
	{
		msh->env->names[pos] = msh->env->names[pos + 1];
		msh->env->values[pos] = msh->env->values[pos + 1];
		pos++;
	}
	msh->env_var_count--;
}

static int	find_var_in_env(t_msh *msh, char *var_name)
{
	int	i;

	i = 0;
	while (msh->env->names[i])
	{
		if (ft_strcmp(msh->env->names[i], var_name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_unset(t_msh *msh, char **args)
{
	int	i;
	int	var_pos;
	int	status;

	if (!args[1])
		return (0);
	status = 0;
	i = 1;
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
		{
			ft_fd_printf(2, "unset: `%s': not a valid identifier\n", args[i]);
			status = 1;
		}
		else
		{
			var_pos = find_var_in_env(msh, args[i]);
			if (var_pos >= 0)
				remove_var_from_env(msh, var_pos);
		}
		i++;
	}
	return (status);
}
