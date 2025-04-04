/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:41:10 by lauriago          #+#    #+#             */
/*   Updated: 2025/02/19 02:12:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_cd_minus(t_msh *msh)
{
	char	*new_path;

	if (!msh->tkns->args[1])
		return ;
	if (!msh->env->old_pwd)
	{
		ft_fd_printf(2, "cd: OLDPWD not set\n");
		return ;
	}
	new_path = ft_strdup(msh->env->old_pwd);
	if (chdir(msh->env->old_pwd) == -1)
		perror("cd");
	else
	{
		msh->env->old_pwd = update_env(msh, "OLDPWD", msh->env->pwd);
		msh->env->pwd = update_env(msh, "PWD", new_path);
		ft_fd_printf(1, "%s\n", new_path);
	}
}

static void	cd_home(t_msh *msh)
{
	if (!msh->env->home)
		ft_fd_printf(2, "cd: HOME not set\n");
	if (chdir(msh->env->home) == -1)
		perror("cd");
	else
	{
		msh->env->old_pwd = update_env(msh, "OLDPWD", msh->env->pwd);
		msh->env->pwd = update_env(msh, "PWD", msh->env->home);
	}
}

static void	update_pwd_opwd(t_msh *msh, char *new_path)
{
	msh->env->old_pwd = update_env(msh, "OLDPWD", msh->env->pwd);
	msh->env->pwd = update_env(msh, "PWD", new_path);
}

void	handle_cd_path(t_msh *msh)
{
	char	*new_path;

	if (msh->tkns->args[1][0] == '/')
		new_path = ft_strdup(msh->tkns->args[1]);
	else
		new_path = make_relative(msh->tkns->args[1], msh);
	if (!new_path)
	{
		ft_fd_printf(2, "Error updating PWD environment variable\n");
		return ;
	}
	if (chdir(new_path) == -1)
	{
		if (errno == EACCES)
			handle_cd_error(msh, EACCES);
		else if (errno == ENOTDIR)
			handle_cd_error(msh, ENOTDIR);
		else
			handle_cd_error(msh, errno);
	}
	else
		update_pwd_opwd(msh, new_path);
	free(new_path);
}

void	ft_cd(t_msh *msh, int num_cmd)
{
	if (num_cmd == 1)
		cd_home(msh);
	if (num_cmd == 2)
	{
		if (cd_varman(msh, manage_cd_var(msh, msh->tkns->args[1])))
			return ;
		if (msh->tkns->args[1][0] == '-' && msh->tkns->args[1][1] == '\0')
			handle_cd_minus(msh);
		else if (msh->tkns->args[1][0] == '~' && msh->tkns->args[1][1] == '\0')
			cd_home(msh);
		else
			handle_cd_path(msh);
	}
	else if (num_cmd == 3)
		handle_cd_path(msh);
}
