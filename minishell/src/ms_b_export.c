/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:15:46 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/26 19:23:10 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/* deberia funcionar pero no pasa de ls primera comprobacion (no hay env?)*/

/* La idea es que lo copie a un array temporal, liberemos la memoria actual
del env y malloquemos nueva con la nueva variable incluida mas el null del final*/
int ft_export(t_msh *msh, char *new_var)
{
    int i;
    int l;
    char **tmp_env;

    l = 0;
    i = 0;
    (void) new_var;

    // if (!msh->env->names[0])
    // {
    //     ft_fd_printf(2, "Error: Environment names not initialized\n");
    //     return -1;
    // }
    while(msh->env->names[l])
        l++;
    ft_fd_printf(1, "l value = %d\n", l);
    tmp_env = (char**)malloc(sizeof (char *) * (l + 2));
    if (!tmp_env)
        return (ft_fd_printf(2, E_MALLOC));

    while (msh->env->names[i])
    {
        tmp_env[i] = ft_strdup(msh->env->names[i]);
        // ft_fd_printf(1, "%s\n", msh->env->values);
        // ft_fd_printf(2, "i value: %d\n", i);
        i++;
    }
    while (msh->env->names[i])
	{
        tmp_env[i] = ft_strdup(msh->env->names[i]);
        ft_fd_printf(2, "loop: %d\n", i);
		i++;
	}
    tmp_env[l] = NULL;
    free(tmp_env);
    ft_fd_printf(2, "i returned: %d\n", i);
    return (i);
}

/* cuenta las variables del env*/
int count_env_vars(t_msh *msh)
{
    int l;

    l = 0;
    while (msh->env->names[l])
        l++;
    return (l);
}


/* busca una variable especifica en el env y nos retorna el valor de su indice*/
int find_env_var(t_msh *msh, char *var_name)
{
    int i;

    i = 0;
    while (msh->env->names[i])
    {
        if (ft_strcmp(msh->env->names[i], var_name) == 0)
            return (i);
        i++;
    }
    return (-1);
}