/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:25:46 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/28 19:51:48 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Cuenta las variables que hay en env (No modificar) trabajando en ella */
int	env_var_count(char **envs)
{
	int	i;

	i = 0;
	if (!envs || envs == NULL)
		printf("THERE IS NO ENV\n");
	else
	{
		while (envs && envs[i])
			i++;
	}
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
	env->home = getenv("HOME");
	getcwd(env->pwd, PATH_MAX);
	// if (check_envs() != 0)
	// 	return (0);
	while (msh->envs[i])
	{
		eq_sep = ft_strchr(msh->envs[i], '=');
		if (eq_sep)
		{
			env->names[i] = ft_strndup(msh->envs[i], (eq_sep - msh->envs[i]));
			env->values[i] = ft_strdup(eq_sep + 1);
			if (!env->names[i] || !env->values[i])
				return (ft_fd_printf(2, "%s", E_ENVGET) * -1);
		}
		printf("nombre: %s, valor: %s\n", env->names[i], env->values[i]);
		i++;
	}
	return (0);
}
