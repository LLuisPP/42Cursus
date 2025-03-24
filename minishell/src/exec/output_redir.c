/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:01 by lauriago          #+#    #+#             */
/*   Updated: 2025/03/16 19:52:42 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_fd(char *filename)
{
	if (access(filename, F_OK) == 0)
		ft_fd_printf(2, "minishell: %s: Permission denied\n", filename);
	else
		ft_fd_printf(2, "minishell: %s: No such file or directory\n", filename);
}

int	handle_output_file(t_msh *msh, char *filename, t_redir type)
{
	int	fd;

	fd = 0;
	if (msh->mpip->backup_out == -1)
		return (FALSE);
	if (type == REDIR_OUT)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == REDIR_APPEND)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		error_fd(filename);
		return (FALSE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Error redirecting output");
		close(msh->mpip->backup_out);
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

void	restore_redirections(t_msh *msh)
{
	if (msh->mpip->backup_out != -1)
	{
		dup2(msh->mpip->backup_out, STDOUT_FILENO);
		close(msh->mpip->backup_out);
		msh->mpip->backup_out = -1;
	}
	if (msh->mpip->backup_in != -1)
	{
		dup2(msh->mpip->backup_in, STDIN_FILENO);
		close(msh->mpip->backup_in);
		msh->mpip->backup_in = -1;
	}
}
