/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:31:02 by lauriago          #+#    #+#             */
/*   Updated: 2025/02/26 16:31:16 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//This function copy all the args without the redirection token 
static char	**redir_args(char **args, int redir_pos)
{
	char	**result;
	int		i;

	if (!args || redir_pos <= 0)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (redir_pos + 1));
	if (!result)
	{
		ft_fd_printf(2, "malloc failed");
		return (NULL);
	}
	i = 0;
	while (i < redir_pos && args[i])
	{
		result[i] = ft_strdup(args[i]);
		if (!result[i])
		{
			ft_free_array(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

static void	child_process_redir(t_msh *msh, char *fullpath, t_redir type)
{
	char	**new_args;

	new_args = redir_args(msh->tkns->args, msh->tkns->redir_pos);
	if (type == REDIR_OUT || type == REDIR_APPEND)
		handle_output_file(msh, msh->mpip->outfile, type);
	else if (type == REDIR_IN || type == REDIR_HERE)
		handle_input_file(msh, msh->mpip->outfile, type);
	if (execve(fullpath, new_args, msh->envs) == -1)
	{
		cmd_not_found(msh);
		free(fullpath);
		exit(EXIT_FAILURE);
	}
	ft_free_array(new_args);
}

void	exec_redir(t_msh *msh, char *tkn, t_redir type)
{
	pid_t	pid;
	char	*fullpath;
	int		status;

	msh->mpip->backup_out = dup(STDOUT_FILENO);
	msh->mpip->backup_in = dup(STDIN_FILENO);
	fullpath = make_path(tkn, msh);
	pid = fork();
	if (pid == -1)
	{
		ft_fd_printf(2, "bash: fork: Cannot allocate memory\n");
		return ;
	}
	else if (pid == 0)
		child_process_redir(msh, fullpath, type);
	else
	{
		waitpid(pid, &status, 0);
		free (fullpath);
	}
	printf("TERMINANDO EXEC_REDIR\n");
}

// Función que maneja las redirecciones usando builtings 
void	manage_builting_redir(t_msh *msh, t_redir type)
{
	if (type == REDIR_OUT || type == REDIR_APPEND)
	{
		msh->mpip->backup_out = 0;
		msh->mpip->backup_out = dup(STDOUT_FILENO);
		if (!handle_output_file(msh, msh->mpip->outfile, type))
		{
			restore_redirections(msh);
			return ;
		}
		exc_cmd(msh, msh->tkns->redir_pos);
	}
	if (type == REDIR_IN || type == REDIR_HERE)
	{
		msh->mpip->backup_in = 0;
		if (!handle_input_file(msh, msh->mpip->outfile, type))
		{
			restore_redirections(msh);
			return ;
		}
		exc_cmd(msh, msh->tkns->token_count);
	}
	restore_redirections(msh);
}
