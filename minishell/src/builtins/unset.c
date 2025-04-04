/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:37 by lauriago          #+#    #+#             */
/*   Updated: 2024/11/01 20:52:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_var_from_env(t_msh *msh, int pos)
{
	while (msh->env->names[pos])
	{
		msh->env->names[pos] = msh->env->names[pos + 1];
		msh->env->values[pos] = msh->env->values[pos + 1];
		pos++;
	}
	free(msh->env->names[pos]);
	free(msh->env->values[pos]);
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

// int	ft_unset(t_msh *msh, char **args)
// {
// 	int	i;
// 	int	var_pos;
// 	int	status;

// 	if (!args[1])
// 		return (FALSE);
// 	status = 0;
// 	i = 1;
// 	while (args[i])
// 	{
// 		if (!is_valid_identifier(args[i]))
// 		{
// 			ft_fd_printf(2, "unset: `%s': not a valid identifier\n", args[i]);
// 			status = 1;
// 		}
// 		else
// 		{
// 			var_pos = find_var_in_env(msh, args[i]);
// 			if (var_pos >= 0)
// 				remove_var_from_env(msh, var_pos);
// 		}
// 		i++;
// 	}
// 	return (status);
// }
