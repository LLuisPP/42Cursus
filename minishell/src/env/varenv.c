/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:12:48 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/19 19:42:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_dirs(char *cwd, char *old_pwd)
{
	free(old_pwd);
	free(cwd);
}

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
	char	*old_pwd;
	char	*cwd;

	if (!var_name || !msh)
		return (FALSE);
	value = search_value(msh, var_name);
	if (!value)
		return (FALSE);
	old_pwd = msh->env->pwd;
	if (chdir(value) == -1)
		return (FALSE);
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (FALSE);
	update_env(msh, "OLDPWD", old_pwd);
	update_env(msh, "PWD", cwd);
	if (msh->env->old_pwd)
		free(msh->env->old_pwd);
	msh->env->old_pwd = ft_strdup(old_pwd);
	if (msh->env->pwd)
		free(msh->env->pwd);
	msh->env->pwd = ft_strdup(cwd);
	free_dirs(cwd, old_pwd);
	return (TRUE);
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
