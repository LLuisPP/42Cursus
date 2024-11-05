/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_cd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:26:15 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/02 18:39:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_cd_error(char *path, int error_type)
{
	if (error_type == EACCES)
		ft_fd_printf(2, "cd: %s: Permission denied\n", path);
	else if (error_type == ENOTDIR)
		ft_fd_printf(2, "cd: %s: Not a directory\n", path);
	else
		ft_fd_printf(2, "cd: %s: No such file or directory\n", path);
}

void	update_pwd_vars(t_msh *msh)
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
	update_env_var(msh, "PWD", msh->env->pwd);
	update_env_var(msh, "OLDPWD", msh->env->old_pwd);
}

char	*built_abspath(char *relative_path, char *pwd)
{
	char	*abs_path;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(relative_path) + ft_strlen(pwd) + 2;
	i = -1;
	j = 0;
	abs_path = malloc(sizeof(char) * len);
	if (!abs_path)
		return (NULL);
	while (pwd[++i])
		abs_path[j++] = pwd[i];
	abs_path[j++] = '/';
	i = -1;
	while (relative_path[++i])
		abs_path[j++] = relative_path[i];
	abs_path[j] = '\0';
	return (abs_path);
}

char	*make_relative(char *arg, t_msh *msh)
{
	char	*new_path;

	new_path = NULL;
	if (arg[0] == '.' && arg[1] == '\0')
		new_path = ft_strdup(".");
	else if (arg[0] == '.' && arg[1] == '.'
		&& (arg[2] == '\0' || arg[2] == '/'))
		new_path = ft_strdup("..");
	else if (arg[0] == '.' && arg[1] == '/')
		new_path = built_abspath(arg + 2, msh->env->pwd);
	else
		new_path = built_abspath(arg, msh->env->pwd);
	return (new_path);
}
