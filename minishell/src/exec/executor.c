/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:13:10 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/09 21:27:55 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_command_executable(char *fullpath)
{
	if (access(fullpath, F_OK) == 0 && access(fullpath, X_OK) == 0)
		return (TRUE);
	return (FALSE);
}

static void	child_process(t_msh *msh, char *fullpath)
{
	if (execve(fullpath, msh->tkns->args, msh->envs) == -1)
	{
		cmd_not_found(msh);
		free(fullpath);
		exit(EXIT_FAILURE);
	}
}

static void	parent_process(t_msh *msh, pid_t pid, char *fullpath)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		msh->last_exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		msh->last_exit_code = 128 + WTERMSIG(status);
	free(fullpath);
}

int	execute_command(t_msh *msh, char *fullpath)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_fd_printf(2, "bash: fork: Cannot allocate memory\n");
		free(fullpath);
		msh->last_exit_code = 1;
		return (-1);
	}
	else if (pid == 0)
		child_process(msh, fullpath);
	else
		parent_process(msh, pid, fullpath);
	return (TRUE);
}

int	find_cmd(char *tkn, t_msh *msh)
{
	char	*fullpath;

	fullpath = make_path(tkn, msh);
	if (!fullpath && msh->tkns->args[0])
		fullpath = ft_strdup(msh->tkns->args[0]);
	if (is_command_executable(fullpath))
	{
		if (!execute_command(msh, fullpath))
			return (-1);
	}
	else
	{
		if (access(fullpath, F_OK) == 0 && access(fullpath, X_OK) != 0)
		{
			msh->last_exit_code = 126;
			ft_fd_printf(2, "%s: Permission denied\n", fullpath);
			free(fullpath);
			return (TRUE);
		}
		free(fullpath);
		return (-1);
	}
	return (TRUE);
}
