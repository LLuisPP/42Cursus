/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_varenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:12:48 by lauriago          #+#    #+#             */
/*   Updated: 2024/11/12 12:41:13 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_env(char *var, t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->env->names[i] && msh->env->values[i])
	{
		if (ft_strcmp(msh->env->names[i], var) == 0)
		{
			return (msh->env->values[i]);
		}
		i++;
	}
	return (NULL);
}

// Función para manejar variables de entorno en builtins
int	varenv_man(t_msh *msh, char *builting, char *var_name)
{
	char	*value;
	char	*current_pwd;

	if (!var_name || !builting || !msh)
		return (FALSE);
	value = search_env(var_name, msh);
	if (!value)
		return (FALSE);
	if (ft_strcmp(builting, "cd") == 0)
	{
		if (chdir(value) != -1)
		{
			current_pwd = getcwd(NULL, 0);
			msh->env->old_pwd = update_env(msh, "OLDPWD", msh->env->pwd);
			msh->env->pwd = update_env(msh, "PWD", current_pwd);
			free(current_pwd);
			return (TRUE);
		}
	}
	else if (ft_strcmp(builting, "echo") == 0)
	{
		printf("%s", value);
		return (TRUE);
	}
	return (FALSE);
}
