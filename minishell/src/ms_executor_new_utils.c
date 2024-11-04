/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_new_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:24:12 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/03 13:24:36 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redirect_input(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_fd_printf(2, "minishell: %s: %s\n", file, strerror(errno));
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

static int	redirect_output(char *file, int append)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(file, flags, 0644);
	if (fd == -1)
	{
		ft_fd_printf(2, "minishell: %s: %s\n", file, strerror(errno));
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	setup_redirections(t_tok *token)
{
	int	i;

	i = 0;
	while (token->args && token->args[i])
	{
		if (token->type == T_REDIR_IN)
		{
			if (redirect_input(token->args[i]) == -1)
				return (-1);
		}
		else if (token->type == T_REDIR_OUT)
		{
			if (redirect_output(token->args[i], 0) == -1)
				return (-1);
		}
		else if (token->type == T_APPEND)
		{
			if (redirect_output(token->args[i], 1) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

static void	cleanup_pipe(int *old_pipe, int *new_pipe)
{
	if (old_pipe[0] != -1)
	{
		close(old_pipe[0]);
		old_pipe[0] = -1;
	}
	if (old_pipe[1] != -1)
	{
		close(old_pipe[1]);
		old_pipe[1] = -1;
	}
	if (new_pipe[0] != -1)
		old_pipe[0] = new_pipe[0];
	if (new_pipe[1] != -1)
		old_pipe[1] = new_pipe[1];
}

int	handle_pipes(t_msh *msh)
{
	int	old_pipe[2];
	int	new_pipe[2];
	int	cmd_count;
	int	i;

	old_pipe[0] = -1;
	old_pipe[1] = -1;
	cmd_count = 0;
	while (msh->tkns[cmd_count].cmd)
		cmd_count++;
	i = 0;
	while (i < cmd_count)
	{
		if (i < cmd_count - 1)
		{
			if (pipe(new_pipe) == -1)
				return (-1);
		}
		else
		{
			new_pipe[0] = -1;
			new_pipe[1] = -1;
		}
		if (execute_command_new(msh, i < cmd_count - 1) == -1)
			return (-1);
		cleanup_pipe(old_pipe, new_pipe);
		i++;
	}
	return (0);
}
