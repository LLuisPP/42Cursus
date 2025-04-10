/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:37 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/08 09:25:21 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_var_from_env(t_msh *msh, int pos)
{
	int	i;

	free(msh->env->names[pos]);
	free(msh->env->values[pos]);
	i = pos;
	while (msh->env->names[i + 1])
	{
		msh->env->names[i] = msh->env->names[i + 1];
		msh->env->values[i] = msh->env->values[i + 1];
		i++;
	}
	msh->env->names[i] = NULL;
	msh->env->values[i] = NULL;
	msh->env_var_count--;
}

int	ft_unset(t_msh *msh, int tok_num)
{
	int	pos;

	if (!msh->tkns->args[1])
		return (FALSE);
	pos = find_env_pos(msh, msh->tkns->args[1]);
	if (tok_num == 2)
	{
		if (pos != -1)
			remove_var_from_env(msh, pos);
		return (TRUE);
	}
	return (FALSE);
}
