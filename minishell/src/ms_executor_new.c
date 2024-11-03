/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:21:29 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/03 13:23:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_pipe_fds(int *pipe_fd)
{
	if (pipe_fd[0] != -1)
		close(pipe_fd[0]);
	if (pipe_fd[1] != -1)
		close(pipe_fd[1]);
}

static int	handle_builtin(t_msh *msh, int num_cmd)
{
	if (ft_strcmp(msh->tkns->cmd, "echo") == 0)
		return (ft_echo(msh, num_cmd), 1);
	else if (ft_strcmp(msh->tkns->cmd, "cd") == 0)
	{
		ft_cd(msh, num_cmd);
		return (0);
	}
	else if (ft_strcmp(msh->tkns->cmd, "pwd") == 0)
		return (ft_pwd(msh));
	else if (ft_strcmp(msh->tkns->cmd, "export") == 0)
		return (ft_export(msh, msh->tkns->args));
	else if (ft_strcmp(msh->tkns->cmd, "unset") == 0)
		return (ft_unset(msh, msh->tkns->args));
	else if (ft_strcmp(msh->tkns->cmd, "env") == 0)
		return (ft_env(msh));
	else if (ft_strcmp(msh->tkns->cmd, "exit") == 0)
		ft_exit(msh);
	return (-1);
}

static void	exec_child(t_msh *msh, int *pipe_fd, int is_piped)
{
	char	*cmd_path;

	if (is_piped && pipe_fd[1] != -1)
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			exit(ft_fd_printf(2, "dup2 error\n") * 0 + 1);
	}
	close_pipe_fds(pipe_fd);
	if (is_builtin(msh) == 0)
	{
		msh->last_exit_code = handle_builtin(msh, 1);
		exit(msh->last_exit_code);
	}
	cmd_path = make_path(msh->tkns->cmd, msh);
	if (!cmd_path)
	{
		ft_fd_printf(2, "minishell: %s: command not found\n", msh->tkns->cmd);
		exit(127);
	}
	if (execve(cmd_path, msh->tkns->args, msh->envs) == -1)
	{
		free(cmd_path);
		exit(ft_fd_printf(2, "execve error\n") * 0 + 1);
	}
}

static int	create_pipe_and_fork(t_msh *msh, int *pipe_fd, int is_piped)
{
	pid_t	pid;

	if (is_piped)
	{
		if (pipe(pipe_fd) == -1)
			return (ft_fd_printf(2, "pipe error\n") * 0 - 1);
	}
	else
	{
		pipe_fd[0] = -1;
		pipe_fd[1] = -1;
	}
	pid = fork();
	if (pid == -1)
	{
		close_pipe_fds(pipe_fd);
		return (ft_fd_printf(2, "fork error\n") * 0 - 1);
	}
	if (pid == 0)
		exec_child(msh, pipe_fd, is_piped);
	return (pid);
}

int	execute_command_new(t_msh *msh, int is_piped)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		status;

	if (!msh->tkns->cmd)
		return (0);
	if (!is_piped && is_builtin(msh) == 0)
		return (handle_builtin(msh, 1));
	pid = create_pipe_and_fork(msh, pipe_fd, is_piped);
	if (pid < 0)
		return (-1);
	close_pipe_fds(pipe_fd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		msh->last_exit_code = WEXITSTATUS(status);
	return (msh->last_exit_code);
}