/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:13:40 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/06 19:28:10 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Actualizar env (TO DO) */
void	env_pos(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->env->names[i] && msh->env->values[i])
	{
		if (ft_strcmp(msh->env->names[i], "PWD") == 0)
			msh->env->values[i] = msh->env->pwd;
		if (ft_strcmp(msh->env->names[i], "OLDPWD") == 0)
			msh->env->values[i] = msh->env->old_pwd;
		i++;
	}
}

/* builtin para imprimir el environment */
int	ft_env(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->env->names[i] && msh->env->values[i])
	{
		ft_fd_printf(1, "%s=%s\n", msh->env->names[i],
			msh->env->values[i]);
		i++;
	}
	return (1);
}
