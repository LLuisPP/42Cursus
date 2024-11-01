/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:13:40 by lauriago          #+#    #+#             */
/*   Updated: 2024/11/01 21:00:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_env_var(t_msh *msh, char *name, char *value)
{
	int		i;
	char	*new_value;

	i = 0;
	if (!name || !value)
		return (0);
	new_value = ft_strdup(value);
	if (!new_value)
		return (0);
	while (msh->env->names[i])
	{
		if (ft_strcmp(msh->env->names[i], name) == 0)
		{
			free(msh->env->values[i]);
			msh->env->values[i] = new_value;
			return (1);
		}
		i++;
	}
	free(new_value);
	return (0);
}

void	env_pos(t_msh *msh)
{
	if (!msh || !msh->env)
		return ;
	if (msh->env->pwd)
		update_env_var(msh, "PWD", msh->env->pwd);
	if (msh->env->old_pwd)
		update_env_var(msh, "OLDPWD", msh->env->old_pwd);
}

int	ft_env(t_msh *msh)
{
	int	i;

	if (!msh || !msh->env || !msh->env->names || !msh->env->values)
	{
		ft_fd_printf(2, "env: environment not available\n");
		return (1);
	}
	if (msh->tkns[1].cmd)
	{
		ft_fd_printf(2, "env: '%s': No such file or directory\n",
			msh->tkns[1].cmd);
		return (127);
	}
	i = 0;
	while (msh->env->names[i] && msh->env->values[i])
	{
		ft_fd_printf(1, "%s=%s\n", msh->env->names[i],
			msh->env->values[i]);
		i++;
	}
	return (0);
}
