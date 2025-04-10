/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:26:15 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/08 08:37:16 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static char	*go_back_dir(char *pwd)
{
	char	*last_slash;
	char	*new_pwd;

	last_slash = ft_strrchr(pwd, '/');
	if (!last_slash || last_slash == pwd)
		return (ft_strdup("/"));
	new_pwd = ft_substr(pwd, 0, last_slash - pwd);
	return (new_pwd);
}

static char	*handle_multiple_back(char *path, t_msh *msh)
{
	char	*temp_pwd;
	char	*final_pwd;
	int		i;

	temp_pwd = ft_strdup(msh->env->pwd);
	i = 0;
	while (path[i] && path[i] == '.' && path[i + 1] == '.'
		&& (path[i + 2] == '/' || path[i + 2] == '\0'))
	{
		final_pwd = go_back_dir(temp_pwd);
		free(temp_pwd);
		temp_pwd = final_pwd;
		i += 2;
		if (path[i] == '/')
			i++;
	}
	if (path[i] == '\0')
		return (temp_pwd);
	final_pwd = built_abspath(path + i, temp_pwd);
	free(temp_pwd);
	return (final_pwd);
}

char	*make_relative(char *arg, t_msh *msh)
{
	char	*new_path;
	char	*tmp_pwd;

	tmp_pwd = ft_strdup(msh->env->pwd);
	if (!tmp_pwd)
		return (NULL);
	if (arg[0] == '.' && arg[1] == '\0')
		new_path = ft_strdup(".");
	else if (arg[0] == '.' && arg[1] == '.' && arg[2] == '\0')
	{
		free(tmp_pwd);
		return (go_back_dir(msh->env->pwd));
	}
	else if (arg[0] == '.' && arg[1] == '.' && arg[2] == '/')
	{
		free(tmp_pwd);
		return (handle_multiple_back(arg, msh));
	}
	else if (arg[0] == '.' && arg[1] == '/')
		new_path = built_abspath(arg + 2, tmp_pwd);
	else
		new_path = built_abspath(arg, tmp_pwd);
	free(tmp_pwd);
	return (new_path);
}

void	expand_cd_home(t_msh *msh)
{
	char	*home_path;
	char	*full_path;

	if (!msh->env->home)
	{
		ft_fd_printf(2, "cd: HOME not set\n");
		msh->last_exit_code = 1;
		return ;
	}
	home_path = msh->env->home;
	full_path = ft_strjoin(home_path, msh->tkns->args[1] + 1);
	if (!full_path)
		return ;
	if (chdir(full_path) == -1)
		handle_cd_error(msh, errno);
	else
		update_pwd_opwd(msh, full_path);
	free(full_path);
}
