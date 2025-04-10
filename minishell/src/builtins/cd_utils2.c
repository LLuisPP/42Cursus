/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:12:28 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/10 10:12:33 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_to_oldpwd(t_msh *msh, char *tmp_oldpwd, char *tmp_pwd)
{
	if (chdir(tmp_oldpwd) == -1)
		perror("cd");
	else
	{
		msh->env->old_pwd = update_env(msh, "OLDPWD", tmp_pwd);
		msh->env->pwd = update_env(msh, "PWD", tmp_oldpwd);
		ft_fd_printf(1, "%s\n", tmp_oldpwd);
	}
}
