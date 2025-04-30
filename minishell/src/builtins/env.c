/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:13:40 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/09 10:35:01 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_env_var(t_msh *msh, char *name, char *value)
{
	int		i;
	char	*new_value;

	i = 0;
	if (!name || !value)
		return (FALSE);
	new_value = ft_strdup(value);
	if (!new_value)
		return (FALSE);
	while (msh->env->names[i])
	{
		if (ft_strcmp(msh->env->names[i], name) == 0)
		{
			free(msh->env->values[i]);
			msh->env->values[i] = new_value;
			return (TRUE);
		}
		i++;
	}
	free(new_value);
	return (FALSE);
}

int	ft_env(t_msh *msh)
{
	int	i;

	if (!msh || !msh->env || !msh->env->names || !msh->env->values)
	{
		ft_fd_printf(2, "env: environment not available\n");
		return (FALSE);
	}
	if (msh->tkns->args[1] && ft_strcmp(msh->tkns->args[1], "env") != 0
		&& has_redirection(msh, msh->tkns) == -1)
	{
		ft_fd_printf(2, "env: '%s': No such file or directory\n",
			msh->tkns->args[1]);
		return (ft_err(msh, EXIT_NOFOUND));
	}
	i = 0;
	while (msh->env->names[i])
	{
		if (msh->env->values[i])
			ft_fd_printf(1, "%s=%s\n", msh->env->names[i],
				msh->env->values[i]);
		else
			ft_fd_printf(1, "%s=\n", msh->env->names[i]);
		i++;
	}
	return (TRUE);
}
