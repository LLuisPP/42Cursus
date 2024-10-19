/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:25:46 by lprieto-          #+#    #+#             */
/*   Updated: 2024/10/08 22:54:01 by leegon           ###   ########.fr       */
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
	ft_fd_printf(1, " # ENV VARS # > %d\n", i);
	return (i);
}

/* Comprueba que las variables PWD, OLDPWD y HOME existan  */
int	check_envs(void)
{
	if (getenv("PWD") == NULL || getenv("OLDPWD") == NULL)
		return (printf("Warning: modified env (PWD)\n") * -1);
	return (0);
}

/* Inicializa las variables de entorno con los valores del env (si existe) */
int	init_env(t_env *env, t_msh *msh)
{
	int		i;
	char	*eq_sep;

	i = 0;
	eq_sep = NULL;
	env->home = getenv("HOME");
	env->old_pwd = getenv("OLDPWD");
	env->path = getenv("PATH");
	getcwd(env->pwd, PATH_MAX);
	if (check_envs() != 0)
		return (0);
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
	return (0);
}
