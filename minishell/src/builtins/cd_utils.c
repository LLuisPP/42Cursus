/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:26:15 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/11 23:49:57 by leegon           ###   ########.fr       */
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

	if (arg[0] == '.' && arg[1] == '\0')
		new_path = ft_strdup(".");
	else if (arg[0] == '.' && arg[1] == '.' && arg[2] == '\0')
		return (go_back_dir(msh->env->pwd));
	else if (arg[0] == '.' && arg[1] == '.' && arg[2] == '/')
		return (handle_multiple_back(arg, msh));
	else if (arg[0] == '.' && arg[1] == '/')
		new_path = built_abspath(arg + 2, msh->env->pwd);
	else
		new_path = built_abspath(arg, msh->env->pwd);
	return (new_path);
}
