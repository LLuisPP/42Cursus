/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:12:48 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/08 09:48:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_value(t_msh *msh, char *var)
{
	int	i;

	i = 0;
	while (msh->env->names[i] && msh->env->values[i])
	{
		if (ft_strcmp(msh->env->names[i], var) == 0)
			return (msh->env->values[i]);
		i++;
	}
	return (NULL);
}

char	*manage_cd_var(t_msh *msh, char *arg)
{
	char	*str;
	char	*tmp;
	int		len;

	str = ft_strdup(arg);
	if (!str)
		return (NULL);
	if ((arg[0] == '\"' && analyze_quotes(msh, arg, arg[0])) || arg[0] == '$')
	{
		tmp = remove_quotes(arg, '\"');
		free(str);
		str = tmp;
	}
	if (echo_has_2_expand(str))
	{
		len = ft_varlen(str, 1);
		tmp = copy_var(str, 1, len);
		free(str);
		return (tmp);
	}
	free(str);
	return (NULL);
}

int	cd_varman(t_msh *msh, char *var_name)
{
	char	*value;
	char	*current_pwd;

	if (!var_name || !msh)
		return (FALSE);
	value = search_value(msh, var_name);
	if (!value)
		return (FALSE);
	if (chdir(value) != -1)
	{
		current_pwd = getcwd(NULL, 0);
		msh->env->old_pwd = update_env(msh, "OLDPWD", msh->env->pwd);
		msh->env->pwd = update_env(msh, "PWD", current_pwd);
		free(current_pwd);
		return (TRUE);
	}
	return (FALSE);
}

char	*update_env(t_msh *msh, char *name, char *value)
{
	char	*new_value;
	int		i;

	i = 0;
	if (!value || !name || !msh->env || !msh->env->names
		|| !msh->env->values)
		return (NULL);
	while (msh->env->names[i] && msh->env->values[i])
	{
		if (ft_strcmp(msh->env->names[i], name) == 0)
		{
			if (ft_strcmp(msh->env->values[i], value) == 0)
				return (msh->env->values[i]);
			new_value = ft_strdup(value);
			if (!new_value)
				return (NULL);
			free(msh->env->values[i]);
			msh->env->values[i] = new_value;
			return (msh->env->values[i]);
		}
		i++;
	}
	return (NULL);
}
