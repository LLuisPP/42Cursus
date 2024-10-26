/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:15:46 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/26 07:28:30 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_export(t_msh *msh)
{
    int i;
    char **tmp_env = NULL;

    i = 0;
    while (msh->env->names[i])
    {
        ft_fd_printf(1, "%s\n", msh->env->values[i]);
        i++;
    }
    while (msh->env->names[i])
	{
        tmp_env[i] = ft_strdup(msh->env->names[i]);
    
        if (!msh->env->names[i])
            return (ft_fd_printf(2, "Error: export failed"), -1);
		i++;
	}
    
    ft_fd_printf(2, "loop: %d\n", i);
    int y;
    y=0;
    while(y < ft_fd_printf(1, "%s", tmp_env[y]))
        y++;
    return (i);
}