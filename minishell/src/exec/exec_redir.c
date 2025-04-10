/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:31:02 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/03 19:33:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**redir_args(char **args, int redir_pos)
{
	char	**result;
	int		i;
	int		j;

	if (!args || redir_pos <= 0)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (redir_pos + 2));
	if (!result)
	{
		ft_fd_printf(2, "malloc failed");
		return (NULL);
	}
	i = 0;
	j = 0;
	printf("redir_ps = %d\n", redir_pos);
	while (i < redir_pos && args[i])
	{
		if (!is_operator(args[i][0]) && !is_pipe(args[i][0]))
			result[j++] = ft_strdup(args[i]);
		i++;
	}
	result[j] = NULL;
	return (result);
}

static void	child_process_redir(t_msh *msh, char *fullpath, t_redir type)
{
	char	**new_args;

	new_args = redir_args(msh->tkns->args, msh->tkns->redir_pos);
	if (type == REDIR_OUT || type == REDIR_APPEND)
		handle_output_file(msh, msh->mpip->outfile, type);
	else if (type == REDIR_IN)
		handle_input_file(msh, msh->mpip->infile, type);
	else if (type == REDIR_HERE)
	{
		if (!redirect_input_output(msh))
		{
			ft_fd_printf(2, "Failed to redirect heredoc\n");
			exit(EXIT_FAILURE);
		}
	}
	if (execve(fullpath, new_args, msh->envs) == -1)
	{
		cmd_not_found(msh);
		free(fullpath);
		exit(EXIT_FAILURE);
	}
	ft_free_array(new_args);
}

static void	parent_process_redir(t_msh *msh, pid_t pid, char *fullpath)
{
	int		status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		msh->last_exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		msh->last_exit_code = 128 + WTERMSIG(status);
	cleanup_heredoc(msh);
	free (fullpath);
}

void	exec_redir(t_msh *msh, char *tkn, t_redir type)
{
	pid_t	pid;
	char	*fullpath;

	msh->mpip->backup_out = dup(STDOUT_FILENO);
	msh->mpip->backup_in = dup(STDIN_FILENO);
	fullpath = make_path(tkn, msh);
	pid = fork();
	if (pid == -1)
	{
		ft_fd_printf(2, "bash: fork: Cannot allocate memory\n");
		msh->last_exit_code = 1;
		return ;
	}
	else if (pid == 0)
		child_process_redir(msh, fullpath, type);
	else
		parent_process_redir(msh, pid, fullpath);
}
