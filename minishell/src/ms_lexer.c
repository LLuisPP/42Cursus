/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:45:27 by lprieto-          #+#    #+#             */
/*   Updated: 2024/10/03 13:42:18 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Comprueba caso de comillas simples / dobles y si estan bien cerradas o no */
int	quote_lexer(t_msh *msh)
{
	int	quote;
	int	i;
	int	len;

	quote = 2;
	i = 0;
	len = ft_strlen(msh->tkns->cmd);
	if (ft_strcmp(msh->tkns->cmd, "\'") != 0 ||
		ft_strcmp(msh->tkns->cmd, "\"") != 0)
		return (-1);
	while (msh->tkns[1].cmd[i] && i <= len)
	{
		if (msh->tkns->cmd[0] == '\'' || msh->tkns->cmd[0] == '\"')
			quote -= 1;
	}
	return (quote);
}

/* Comprueba cada token y su siguiente para operador (incompleta) */
int	lexer(char **tokens, t_msh *msh)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], "|") == 0)
		{
			if (i == 0 || tokens[i + 1] == NULL)
			{
				perror("syntax error with | operator\n");
				return (-1);
			}
		}
		if (ft_strcmp(tokens[i], "<<") == 0)
		{
			if (tokens[i + 1] == NULL)
			{
				perror("syntax error: missing delimiter for heredoc\n");
				return (-1);
			}
			msh->tkns->is_heredoc = 1;
			msh->tkns->heredoc_delim = ft_strdup(tokens[i + 1]);
			i++;
		}
		i++;
	}
	return (0);
}
