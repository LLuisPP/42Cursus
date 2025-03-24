/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:25:46 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/11 17:46:39 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Cuenta las variables que hay en env (No modificar) trabajando en ella */
int	env_var_count(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->envs[i])
		i++;
	msh->env_var_count = i;
	return (i);
}

/* busca una variable especifica y nos retorna la pos*/
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

void	update_shlvl(t_msh *msh)
{
	char	*new_level;
	int		i;

	i = find_env_pos(msh, "SHLVL");
	if (i >= 0)
		msh->shlvl = msh->shlvl + 1;
	else
		msh->shlvl = 1;
	new_level = ft_itoa(msh->shlvl);
	if (!new_level)
		return ;
	if (i >= 0)
	{
		free(msh->env->values[i]);
		msh->env->values[i] = new_level;
	}
}

/* Inicializa las variables de entorno con los valores del env (si existe) */
int	env_init_values(t_env *env, t_msh *msh)
{
	int		i;
	int		j;
	char	*eq_sep;

	i = 0;
	j = 0;
	eq_sep = NULL;
	env->home = ft_strdup(getenv("HOME"));
	if (!env->home)
		return (ft_fd_printf(2, "%s", E_MEMASF) * 0);
	env->old_pwd = getenv("OLDPWD");
	env->path = getenv("PATH");
	getcwd(env->pwd, PATH_MAX);
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
	update_shlvl(msh);
	return (TRUE);
}
