/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:41:10 by lauriago          #+#    #+#             */
/*   Updated: 2024/11/02 18:44:08 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_cd_error(char *path, int error_type)
{
	if (error_type == EACCES)
		ft_fd_printf(2, "cd: %s: Permission denied\n", path);
	else if (error_type == ENOTDIR)
		ft_fd_printf(2, "cd: %s: Not a directory\n", path);
	else
		ft_fd_printf(2, "cd: %s: No such file or directory\n", path);
}

static void	update_pwd_vars(t_msh *msh)
{
	char	*temp;
	char	*new_pwd;

	temp = msh->env->pwd;
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
	{
		ft_fd_printf(2, "cd: error getting current directory\n");
		return ;
	}
	msh->env->old_pwd = temp;
	msh->env->pwd = new_pwd;
	env_pos(msh);
}

static char	*handle_cd_home(t_msh *msh, char *cmd)
{
	char	*home_path;
	char	*result;

	if (!msh->env->home)
	{
		ft_fd_printf(2, "cd: HOME not set\n");
		return (NULL);
	}
	if (!cmd[1])
		result = ft_strdup(msh->env->home);
	else
	{
		home_path = ft_strjoin(msh->env->home, cmd + 1);
		result = ft_strdup(home_path);
		free(home_path);
	}
	return (result);
}

static char	*handle_cd_minus(t_msh *msh)
{
	if (!msh->env->old_pwd)
	{
		ft_fd_printf(2, "cd: OLDPWD not set\n");
		return (NULL);
	}
	ft_fd_printf(1, "%s\n", msh->env->old_pwd);
	return (ft_strdup(msh->env->old_pwd));
}

static void	handle_cd_execute(t_msh *msh, char *path)
{
	if (!path)
		return ;
	if (chdir(path) == -1)
		handle_cd_error(msh->tkns[1].cmd, errno);
	else
		update_pwd_vars(msh);
	free(path);
}

void	handle_cd_path(t_msh *msh)
{
	char	*new_path;

	new_path = NULL;
	if (varenv_man(msh, "cd", msh->tkns[1].cmd) != 0)
		return ;
	if (msh->tkns[1].cmd[0] == '-' && msh->tkns[1].cmd[1] == '\0')
		new_path = handle_cd_minus(msh);
	else if (msh->tkns[1].cmd[0] == '~')
		new_path = handle_cd_home(msh, msh->tkns[1].cmd);
	else if (msh->tkns[1].cmd[0] == '/')
		new_path = ft_strdup(msh->tkns[1].cmd);
	else
		new_path = make_relative(msh->tkns[1].cmd, msh);
	if (!new_path)
	{
		ft_fd_printf(2, "cd: memory allocation error\n");
		return ;
	}
	handle_cd_execute(msh, new_path);
}

void	ft_cd(t_msh *msh, int num_cmd)
{
	if (num_cmd > 2)
		ft_fd_printf(2, "bash: %s: too many arguments\n", msh->tkns->cmd);
	else if (num_cmd == 1)
	{
		if (!msh->env->home)
			ft_fd_printf(2, "cd: HOME not set\n");
		else
			chdir(msh->env->home);
	}
	else if (num_cmd == 2)
		handle_cd_path(msh);
}
