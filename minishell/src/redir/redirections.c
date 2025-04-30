/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:50:55 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/16 00:20:41 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_redirection(t_msh *msh, t_tok *tok)
{
	int	i;

	i = 0;
	(void)msh;
	while (tok->args[i])
	{
		if (is_operator(tok->args[i][0]) || is_pipe(tok->args[i][0]))
			return (i);
		i++;
	}
	return (-1);
}

t_redir	check_syntax_redir(t_msh *msh, char **tkn, int pos)
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
	{
		print_error_msg(msh, tkn[pos][1]);
		msh->last_exit_code = 2;
		return (REDIR_ERROR);
	}
	return (REDIR_ERROR);
}

void	handle_redir_out(t_msh *msh, t_redir type)
{
	int	file_pos;

	file_pos = msh->tkns->redir_pos + 1;
	msh->mpip->outfile = msh->tkns->args[file_pos];
	if (msh->mpip->outfile == NULL)
	{
		ft_fd_printf(2, E_NW);
		msh->last_exit_code = 2;
		return ;
	}
	if (is_builtin(msh->tkns->cmd))
	{
		manage_builting_redir(msh, type);
		return ;
	}
	exec_redir(msh, msh->tkns->cmd, type);
	restore_redirections(msh);
}

int	redir_checker(t_msh *msh)
{
	int		redir_count;
	int		result;

	redir_count = count_redir(msh);
	result = FALSE;
	if (!msh || !msh->tkns || !msh->tkns->args)
		return (FALSE);
	if (find_piperedir(msh) == NULL)
		return (FALSE);
	type_def(msh);
	msh->tkns->redir_pos = msh->tkns->countpip[0];
	if (redir_count == 1)
		result = handle_one_redir(msh, msh->tkns->countpip[0],
				msh->tkns->typepip[0]);
	if (redir_count > 1)
		result = handle_multip_redir(msh, redir_count);
	return (result);
}
