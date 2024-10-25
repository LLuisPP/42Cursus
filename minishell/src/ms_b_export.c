/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:15:46 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/07 13:51:51 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_export(t_msh *msh)
{
    int i;
    char **tmp_env;

    i = 0;
    while (msh->env->names[i])
    {
        ft_fd_printf(1, "%s\n", msh->env->values[i]);
        i++;
    }
    while (msh->envs->names[i])
	{
        *tmp_n_env = ft_strdup(msh->env.names[i], (ft_strlen(msh->env.names[i]) + 1));
    
        if (!env->names[i])
            return (ft_fd_printf(2, "Error: export failed"), -1);
		i++;
	}
    ft_fd_printf(2, "loop: %d\n", i);
    int y;
    y=0;
    while(y < ft_fd_printf(1, "%s"))
    return (i);
}