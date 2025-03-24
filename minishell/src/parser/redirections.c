/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:50:55 by lauriago          #+#    #+#             */
/*   Updated: 2025/03/10 10:20:48 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// print error message
static void	print_error_msg(char c)
{
	ft_fd_printf(2, "minishell: syntax error near unexpected token `%c'\n", c);
}

// Verifies if it has a redirection and returns the position
int	has_redirection(t_tok *tok)
{
	int	i;

	i = 0;
	while (tok->args[i])
	{
		if (is_operator(tok->args[i][0]) || is_pipe(tok->args[i][0]))
			return (i);
		i++;
	}
	return (-1);
}

// Returns the redirection type
t_redir	check_syntax_redir(char **tkn, int pos)
{
	int		len;

	if (!tkn || pos < 0 || !tkn[pos])
		return (NO_REDIR);
	len = ft_strlen(tkn[pos]);
	if (len == 2 || len == 1)
	{
		if (ft_strcmp(tkn[pos], ">") == 0)
			return (REDIR_OUT);
		if (ft_strcmp(tkn[pos], ">>") == 0)
			return (REDIR_APPEND);
		if (ft_strcmp(tkn[pos], "<") == 0)
			return (REDIR_IN);
		if (ft_strcmp(tkn[pos], "<<") == 0)
			return (REDIR_HERE);
		if (ft_strcmp(tkn[pos], "|") == 0)
			return (PIPE);
	}
	if (len > 2)
		print_error_msg(tkn[pos][1]);
	return (REDIR_ERROR);
}

void	handle_redir(t_msh *msh, t_redir type)
{
	int	file_pos;

	file_pos = msh->tkns->redir_pos + 1;
	msh->mpip->outfile = msh->tkns->args[file_pos];
	if (msh->mpip->outfile == NULL)
	{
		ft_fd_printf(2, E_NW);
		return ;
	}
	if (is_builtin(msh->tkns->cmd))
	{
		manage_builting_redir(msh, type);
		return ;
	}
	if (type == REDIR_OUT || type == REDIR_APPEND)
		msh->mpip->backup_out = 0;
	if (type == REDIR_IN || type == REDIR_HERE)
		msh->mpip->backup_in = 0;
	exec_redir(msh, msh->tkns->cmd, type);
	restore_redirections(msh);
}

// Función generica para verificar sintaxis redirecciones
int	redir_checker(t_msh *msh)
{
	int		redir_pos;
	t_redir	redir_type;

	if (!msh || !msh->tkns || !msh->tkns->args)
		return (FALSE);
	redir_pos = has_redirection(msh->tkns);
	msh->tkns->redir_pos = redir_pos;
	redir_type = check_syntax_redir(msh->tkns->args, redir_pos);
	if (redir_pos >= 0)
	{
		if (redir_type == REDIR_ERROR || redir_type == NO_REDIR)
			return (FALSE);
		else
			handle_redir(msh, redir_type);
		return (TRUE);
	}
	return (FALSE);
}
