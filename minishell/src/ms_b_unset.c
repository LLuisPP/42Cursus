/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:37 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/26 08:52:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_unset(t_msh *msh)
{
    int i;
    int l;
    char **tmp_env;

    l = 0;
    i = 0;

    if (!msh->env->names[0])
    {
        ft_fd_printf(2, "Error: Environment names not initialized\n");
        return -1;
    }
    
    while(msh->env->names[l])
        l++;
    ft_fd_printf(1, "l value = %d\n", l);
    tmp_env = (char**)malloc(sizeof (char *) * (l + 1));
    if (!tmp_env)
        return (ft_fd_printf(2, E_MALLOC));

    while (msh->env->names[i])
    {
        ft_fd_printf(1, "%s\n", msh->env->values);
        ft_fd_printf(2, "i value: %d\n", i);
        i++;
    }
    while (msh->env->names[i])
	{
        tmp_env[i] = ft_strdup(msh->env->names[i]);
        ft_fd_printf(2, "loop: %d\n", i);
		i++;
	}
    tmp_env[i] = NULL;
    free(tmp_env);
    ft_fd_printf(2, "i returned: %d\n", i);
    return (i);
}
