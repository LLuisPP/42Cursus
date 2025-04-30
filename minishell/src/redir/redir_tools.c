/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:28:23 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/10 01:21:57 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_redir(t_msh *msh)
{
	int	i;

	i = 0;
	msh->tkns->count_redir = 0;
	while (msh->tkns->args[i])
	{
		if (ft_strcmp(msh->tkns->args[i], ">") == 0)
			msh->tkns->count_redir++;
		else if (ft_strcmp(msh->tkns->args[i], "<") == 0)
			msh->tkns->count_redir++;
		else if (ft_strcmp(msh->tkns->args[i], ">>") == 0)
			msh->tkns->count_redir++;
		else if (ft_strcmp(msh->tkns->args[i], "<<") == 0)
			msh->tkns->count_redir++;
		else if (ft_strcmp(msh->tkns->args[i], "|") == 0)
			msh->tkns->count_redir++;
		i++;
	}
	return (msh->tkns->count_redir);
}

int	handle_one_redir(t_msh *msh, int redir_pos, t_redir	redir_type)
{
	if (redir_pos == 0)
	{
		open_files(msh, redir_type, msh->tkns->args[redir_pos + 1]);
		return (TRUE);
	}
	if (redir_type == REDIR_ERROR || redir_type == NO_REDIR)
		return (FALSE);
	if (redir_type == REDIR_OUT || redir_type == REDIR_APPEND)
		handle_redir_out(msh, redir_type);
	if (redir_type == REDIR_IN)
		handle_redir_in(msh, redir_type);
	if (redir_type == REDIR_HERE)
	{
		if (!handle_heredoc(msh, msh->tkns->args[redir_pos + 1]))
			return (TRUE);
		exec_redir(msh, msh->tkns->cmd, redir_type);
		return (TRUE);
	}
	if (redir_type == PIPE)
		handle_pipes(msh);
	return (TRUE);
}

int	find_next_redir(t_msh *msh, int start_pos)
{
	int	i;

	i = start_pos;
	while (msh->tkns->args[i])
	{
		if (ft_strcmp(msh->tkns->args[i], ">") == 0
			|| ft_strcmp(msh->tkns->args[i], "<") == 0
			|| ft_strcmp(msh->tkns->args[i], ">>") == 0
			|| ft_strcmp(msh->tkns->args[i], "<<") == 0
			|| ft_strcmp(msh->tkns->args[i], "|") == 0)
			return (i);
		i++;
	}
	return (-1);
}
