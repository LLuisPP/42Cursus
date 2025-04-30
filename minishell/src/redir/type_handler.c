/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:02:30 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/18 20:02:32 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_multip_redir(t_msh *msh, int count)
{
	if (just_pipes(msh, count))
		handle_pipes(msh);
	if (just_redirs(msh, count))
		handle_just_redirs(msh, count);
	return (TRUE);
}

int	just_pipes(t_msh *msh, int count)
{
	int	pipe;

	pipe = 0;
	while (pipe < count)
	{
		if (msh->tkns->typepip[pipe] == PIPE)
			pipe++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	just_redirs(t_msh *msh, int count)
{
	int	red;

	red = 0;
	while (red < count)
	{
		if (msh->tkns->typepip[red] != PIPE)
			red++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	handle_just_redirs(t_msh *msh, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		msh->tkns->redir_pos = msh->tkns->countpip[j];
		if (!process_redirection(msh, msh->tkns->typepip[j],
				msh->tkns->countpip[j]))
			return (FALSE);
		if (msh->tkns->countpip[j + 1] == -1)
			break ;
		i++;
		j++;
	}
	handle_last_redirection(msh, msh->tkns->typepip[j]);
	return (TRUE);
}
