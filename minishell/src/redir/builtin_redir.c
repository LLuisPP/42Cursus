/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:37:18 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/01 14:37:32 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Preparación de STDIN_FIELNO en caso builtins 
static int	manage_builting_redir_out(t_msh *msh, t_redir type)
{
	msh->mpip->backup_in = 0;
	msh->mpip->backup_in = dup(STDIN_FILENO);
	if (!handle_input_file(msh, msh->mpip->outfile, type))
	{
		restore_redirections(msh);
		return (FALSE);
	}
	return (TRUE);
}

// Función que maneja las redirecciones usando builtings 
int	manage_builting_redir(t_msh *msh, t_redir type)
{
	int	file_pos;

	file_pos = msh->tkns->redir_pos + 1;
	msh->mpip->outfile = msh->tkns->args[file_pos];
	if (type == REDIR_OUT || type == REDIR_APPEND)
	{
		msh->mpip->backup_out = 0;
		msh->mpip->backup_out = dup(STDOUT_FILENO);
		if (!handle_output_file(msh, msh->mpip->outfile, type))
		{
			restore_redirections(msh);
			return (FALSE);
		}
	}
	if (type == REDIR_IN || type == REDIR_HERE)
		if (!manage_builting_redir_out(msh, type))
			return (FALSE);
	exc_cmd(msh, msh->tkns->redir_pos);
	restore_redirections(msh);
	return (TRUE);
}
