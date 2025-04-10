/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:41:10 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/10 01:14:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_cd_minus(t_msh *msh)
{
	char	*tmp_oldpwd;
	char	*tmp_pwd;

	if (!msh->tkns->args[1])
		return ;
	if (!msh->env->old_pwd)
	{
		ft_fd_printf(2, "cd: OLDPWD not set\n");
		msh->last_exit_code = 1;
		return ;
	}
	tmp_oldpwd = ft_strdup(msh->env->old_pwd);
	tmp_pwd = ft_strdup(msh->env->pwd);
	if (!tmp_oldpwd || !tmp_pwd)
	{
		free_tmp_paths(tmp_oldpwd, tmp_pwd);
		ft_fd_printf(2, "%s", E_MEMASF);
		return ;
	}
	change_to_oldpwd(msh, tmp_oldpwd, tmp_pwd);
	free_tmp_paths(tmp_oldpwd, tmp_pwd);
}

static void	cd_home(t_msh *msh)
{
	char	*tmp_pwd;
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
	{
		tmp_pwd = ft_strdup(msh->env->pwd);
		if (!tmp_pwd)
			return ;
		msh->env->old_pwd = update_env(msh, "OLDPWD", tmp_pwd);
		msh->env->pwd = update_env(msh, "PWD", home_path);
		free(tmp_pwd);
	}
}

void	update_pwd_opwd(t_msh *msh, char *new_path)
{
	char	*tmp_pwd;
	char	*tmp_new;
	char	*res;

	tmp_pwd = ft_strdup(msh->env->pwd);
	tmp_new = ft_strdup(new_path);
	if (!tmp_pwd || !tmp_new)
	{
		free(tmp_pwd);
		free(tmp_new);
		ft_fd_printf(2, "%s", E_MEMASF);
		return ;
	}
	res = update_env(msh, "OLDPWD", tmp_pwd);
	if (res != tmp_pwd)
		free(tmp_pwd);
	msh->env->old_pwd = res;
	res = update_env(msh, "PWD", tmp_new);
	if (res != tmp_new)
		free(tmp_new);
	msh->env->pwd = res;
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
