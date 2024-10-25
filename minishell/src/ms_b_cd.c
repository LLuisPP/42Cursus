/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:41:10 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/09 01:27:30 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Converts a relative path to an absolute path */
char	*built_abspath(char *relative_path, char *pwd)
{
	char	*abs_path;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(relative_path) + ft_strlen(pwd) + 2;
	abs_path = malloc(sizeof(char) * len);
	i = -1;
	j = 0;
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
	if (arg[0] == '-')
	{
		new_path = ft_strdup(msh->env->old_pwd);
		printf("%s\n", msh->env->old_pwd);
	}
	else if (arg[0] == '.' && (arg[1] == '\0' || arg[1] == '/'))
		new_path = ft_strdup("..");
	else if ((arg[0] == '.' && arg[1] == '.')
		&& (arg[2] == '\0' || arg[2] == '/'))
		new_path = ft_strdup("..");
	else
		new_path = built_abspath(msh->tkns[1].cmd, msh->env->pwd);
	return (new_path);
}

/* 
	Verifies the route & acces in case that exists 
	If the path starts whith the char '/' is an absolute path
	otherwise, the function converts the input to an absolute path
	and try to acces to the path in case that exists. 
*/
void	handle_cd_path(t_msh *msh)
{
	char	*new_path;

	new_path = NULL;
	if (varenv_man(msh, "cd", msh->tkns[1].cmd) == 0)
	{
		if (msh->tkns[1].cmd[0] == '/')
			new_path = ft_strdup(msh->tkns[1].cmd);
		else
			new_path = make_relative(msh->tkns[1].cmd, msh);
		if (new_path && chdir(new_path) != -1)
		{
			msh->env->old_pwd = msh->env->pwd;
			msh->env->pwd = getcwd(NULL, 0);
			env_pos(msh);
		}
		else
		{
			if (varenv_man(msh, "cd", msh->tkns[1].cmd) == 0)
				return ;
			else
				ft_fd_printf(2, "bash: %s: No such file or directory\n",
					msh->tkns->cmd);
		}
		free(new_path);
	}
}

void	ft_cd(t_msh *msh, int num_cmd)
{
	if (num_cmd > 2)
		ft_fd_printf(2, "bash: %s: too many arguments\n", msh->tkns->cmd);
	else if (num_cmd == 1)
		chdir(msh->env->home);
	else if (num_cmd == 2)
		handle_cd_path(msh);
}
