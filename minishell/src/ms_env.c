/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:25:46 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/21 17:58:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Cuenta las variables que hay en env (No modificar) trabajando en ella */
int env_var_count(char **envs)
{
    int i;
    
    i = 0;
     if (!envs || envs == NULL)
        printf("NO HAY ENV 1\n");
    else
    {    
        while (envs && envs[i])
            i++;
    }
    return (i);
}

/* Comprueba que las variables PWD, OLDPWD y HOME existan  */
int check_envs()
{
    if (getenv("PWD") == NULL || getenv("OLDPWD") == NULL)
        return (printf("Warning: modified env (PWD)\n")* -1);
    return (0);
}

/* Inicializa las variables de entorno con los valores del env (si existe) */
int init_env(t_env *env, char **envs)
{
    int     i;
    char    *eq_sep;
    
    i = 0;
    getcwd(env->pwd, PATH_MAX);
    env->home = getenv("HOME");
    if (check_envs(envs) != 0)
    {
        getcwd(env->pwd, sizeof(env));
        return (0);
    }
    else
    {
        while (envs[i])
        {
            eq_sep = ft_strchr(envs[i], '=');
            if (eq_sep)
            {
                env->name = ft_strndup(envs[i], (eq_sep - envs[i]));
                env->value = ft_strdup(eq_sep + 1);
                printf("nombre: %s, valor: %s\n", env->name, env->value);
            }
            i++;
        }
    }
    return (0);
}

