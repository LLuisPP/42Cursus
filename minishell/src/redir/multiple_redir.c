/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:32:12 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/08 14:32:23 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_files(t_msh *msh, t_redir type, char *file)
{
	if (type == REDIR_OUT || type == REDIR_APPEND)
	{
		msh->mpip->outfile = file;
		if (msh->mpip->outfile == NULL)
		{
			ft_fd_printf(2, E_NW);
			msh->last_exit_code = 2;
			return ;
		}
		msh->mpip->backup_out = dup(STDOUT_FILENO);
		handle_output_file(msh, msh->mpip->outfile, type);
	}
	if (type == REDIR_IN)
	{
		msh->mpip->infile = file;
		if (msh->mpip->infile == NULL)
		{
			ft_fd_printf(2, E_NW);
			msh->last_exit_code = 2;
			return ;
		}
		msh->mpip->backup_in = dup(STDIN_FILENO);
		handle_input_file(msh, msh->mpip->infile, type);
	}
	restore_redirections(msh);
}

int	process_redirection(t_msh *msh, t_redir type, int current_pos)
{
	if (type == REDIR_OUT || type == REDIR_APPEND || type == REDIR_IN)
		open_files(msh, type, msh->tkns->args[current_pos + 1]);
	else if (type == REDIR_HERE)
		handle_heredoc(msh, msh->tkns->args[current_pos + 1]);
	else if (type == PIPE)
		handle_pipes(msh);
	if (msh->last_exit_code == 2)
		return (FALSE);
	return (TRUE);
}

void	handle_last_redirection(t_msh *msh, int is_last_redir, t_redir type)
{
	if (!is_last_redir)
		return ;
	// if (is_builtin(msh->tkns->cmd))
	// 	manage_builting_redir(msh, type);
	if (type == REDIR_OUT || type == REDIR_APPEND)
		handle_redir_out(msh, type);
	if (type == REDIR_IN)
		handle_redir_in(msh, type);
}
