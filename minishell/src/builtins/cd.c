/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:41:10 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/19 19:01:05 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_cd_minus(t_msh *msh)
{
	char	*tmp_oldpwd;

	tmp_oldpwd = msh->env->old_pwd;
	if (!tmp_oldpwd)
	{
		ft_fd_printf(2, "cd: OLDPWD not set\n");
		msh->last_exit_code = 1;
		return ;
	}
	if (chdir(tmp_oldpwd) == -1)
		perror("cd");
	else
		update_pwd_opwd(msh, tmp_oldpwd);
}

static void	cd_home(t_msh *msh)
{
	char	*home_path;

	home_path = search_value(msh, "HOME");
	if (!home_path)
	{
		ft_fd_printf(2, "cd: HOME not set\n");
		msh->last_exit_code = 1;
		return ;
	}
	if (chdir(home_path) == -1)
		perror("cd");
	else
		update_pwd_opwd(msh, home_path);
}

void	update_pwd_opwd(t_msh *msh, char *new_path)
{
	char	*oldpwd;
	char	*dup_old;
	char	*dup_new;

	oldpwd = msh->env->pwd;
	dup_old = ft_strdup(oldpwd);
	dup_new = ft_strdup(new_path);
	if (!dup_old || !dup_new)
	{
		free(dup_old);
		free(dup_new);
		ft_fd_printf(2, "%s", E_MEMASF);
		return ;
	}
	update_env(msh, "OLDPWD", dup_old);
	update_env(msh, "PWD", dup_new);
	if (msh->env->old_pwd)
		free(msh->env->old_pwd);
	if (msh->env->pwd)
		free(msh->env->pwd);
	msh->env->old_pwd = ft_strdup(dup_old);
	msh->env->pwd = ft_strdup(dup_new);
	free(dup_old);
	free(dup_new);
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
		else if (msh->tkns->args[1][0] == '~')
		{
			if (msh->tkns->args[1][1] == '\0')
				cd_home(msh);
			else if (msh->tkns->args[1][1] == '/')
				expand_cd_home(msh);
		}
		else
			handle_cd_path(msh);
	}
	else if (num_cmd == 3)
	{
		ft_fd_printf(2, "minishell: cd: too many arguments\n");
		msh->last_exit_code = 1;
	}
}
