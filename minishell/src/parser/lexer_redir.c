/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:21:38 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/16 00:15:52 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*find_piperedir(t_msh *msh)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	msh->tkns->countpip = malloc(sizeof(int) * 1024);
	if (has_redirection(msh, msh->tkns) == -1)
		return (NULL);
	while (msh->tkns->args[i])
	{
		if (i == 0)
		{
			msh->tkns->countpip[j] = has_redirection(msh, msh->tkns);
			j++;
		}
		if (msh->tkns->countpip[j - 1] != find_next_redir(msh, i)
			&& find_next_redir(msh, i) != -1)
		{
			msh->tkns->countpip[j] = find_next_redir(msh, i);
			j++;
		}
		i++;
	}
	msh->tkns->countpip[j] = -1;
	return (msh->tkns->countpip);
}

void	type_def(t_msh *msh)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	msh->tkns->typepip = malloc(sizeof(int) * 1024);
	while (msh->tkns->countpip[i] != -1)
	{
		msh->tkns->typepip[j] = check_syntax_redir(msh, msh->tkns->args,
				msh->tkns->countpip[i]);
		j++;
		i++;
	}
}

int	is_redir(char *token)
{
	if (!token)
		return (0);
	if (ft_strcmp(token, "<") == 0)
		return (1);
	if (ft_strcmp(token, ">") == 0)
		return (1);
	if (ft_strcmp(token, "<<") == 0)
		return (1);
	if (ft_strcmp(token, ">>") == 0)
		return (1);
	return (0);
}
