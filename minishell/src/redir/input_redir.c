/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:57:05 by lauriago          #+#    #+#             */
/*   Updated: 2025/03/27 10:37:42 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_fd(char *filename)
{
	if (!access(filename, R_OK))
		ft_fd_printf(2, "minishell: %s: Permission denied\n", filename);
	else
		ft_fd_printf(2, "minishell: %s: No such file or directory\n",
			filename);
}

int	handle_input_file(t_msh *msh, char *filename, t_redir type)
{
	int	fd;

	if (msh->mpip->backup_in == -1)
		return (FALSE);
	if (type == REDIR_IN)
		fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error_fd(filename);
		msh->last_exit_code = 1;
		return (FALSE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("Error redirecting input");
		close(msh->mpip->backup_in);
		restore_redirections(msh);
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

void	handle_redir_in(t_msh *msh, t_redir type)
{
	int	file_pos;

	file_pos = msh->tkns->redir_pos + 1;
	if (type == REDIR_HERE)
		msh->mpip->infile = msh->heredoc_file;
	else
		msh->mpip->infile = msh->tkns->args[file_pos];
	if (msh->mpip->infile == NULL)
	{
		ft_fd_printf(2, E_NW);
		msh->last_exit_code = 2;
		return ;
	}
	exec_redir(msh, msh->tkns->cmd, type);
	restore_redirections(msh);
}
