/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:25:46 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/03 12:53:11 by lprieto-         ###   ########.fr       */
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

/* busca una variable especifica en el env y nos retorna el valor de su indice*/
int	find_env_var(t_msh *msh, char *var_name)
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

/* Comprueba que las variables PWD, OLDPWD y HOME existan  */
int	check_envs(void)
{
	if (getenv("PWD") == NULL || getenv("OLDPWD") == NULL)
		return (printf("Warning: modified env (PWD)\n") * -1);
	return (0);
}

void	update_shlvl(t_msh *msh)
{
	char	*new_level;
	int		i;

	i = find_env_var(msh, "SHLVL");
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
	char	*eq_sep;

	i = 0;
	eq_sep = NULL;
	env->home = getenv("HOME");
	env->old_pwd = getenv("OLDPWD");
	env->path = getenv("PATH");
	getcwd(env->pwd, PATH_MAX);
	check_envs();
	while (msh->envs[i])
	{
		eq_sep = ft_strchr(msh->envs[i], '=');
		if (eq_sep)
		{
			env->names[i] = ft_strndup(msh->envs[i], (eq_sep - msh->envs[i]));
			env->values[i] = ft_strdup(eq_sep + 1);
			if (!env->names[i] || !env->values[i])
				return (ft_fd_printf(2, "%s", E_ENVGET), -1);
		}
		i++;
	}
	update_shlvl(msh);
	return (0);
}
