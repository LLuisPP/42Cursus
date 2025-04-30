/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:25:46 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/19 19:38:41 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_var_count(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->envs[i])
		i++;
	msh->env_var_count = i;
	return (i);
}

int	find_env_pos(t_msh *msh, char *var_name)
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

int	env_init_values(t_env *env, t_msh *msh)
{
	int		i;
	int		j;
	char	*eq_sep;

	i = 0;
	j = 0;
	while (msh->envs[i])
	{
		eq_sep = ft_strchr(msh->envs[i], '=');
		if (eq_sep)
		{
			env->names[j] = ft_strndup(msh->envs[i], (eq_sep - msh->envs[i]));
			env->values[j] = ft_strdup(eq_sep + 1);
			if (!env->names[j] || !env->values[j])
				return (ft_fd_printf(2, "%s", E_ENVGET), ft_err(msh, -1));
			j++;
		}
		i++;
	}
	env->names[j] = NULL;
	env->values[j] = NULL;
	return (TRUE);
}

int	env_init(t_env *env, t_msh *msh)
{
	char	*tmp;

	tmp = search_value(msh, "HOME");
	if (tmp)
		env->home = ft_strdup(tmp);
	else
		env->home = NULL;
	tmp = getenv("OLDPWD");
	if (tmp)
		env->old_pwd = ft_strdup(tmp);
	else
		env->old_pwd = NULL;
	tmp = getenv("PATH");
	if (tmp)
		env->path = ft_strdup(tmp);
	else
		env->path = NULL;
	env->pwd = getcwd(NULL, 0);
	if (!env->pwd)
		return (ft_fd_printf(2, "%s", E_MEMASF), FALSE);
	env_init_values(env, msh);
	return (TRUE);
}
