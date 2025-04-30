/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:07:22 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/16 00:18:38 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_double_pipe(t_msh *msh)
{
	int	i;

	if (!msh || !msh->tkns || !msh->tkns->args)
		return (TRUE);
	i = 0;
	while (msh->tkns->args[i])
	{
		if (ft_strcmp(msh->tkns->args[i], "|") == 0
			&& msh->tkns->args[i + 1]
			&& ft_strcmp(msh->tkns->args[i + 1], "|") == 0)
		{
			print_error_msg(msh, '|');
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	check_redir_edges(t_msh *msh)
{
	int	i;

	if (!msh || !msh->tkns || !msh->tkns->args)
		return (TRUE);
	i = 0;
	while (msh->tkns->args[i])
	{
		if (is_redir(msh->tkns->args[i]))
		{
			if (!msh->tkns->args[i + 1] || is_redir(msh->tkns->args[i + 1]))
			{
				print_error_msg(msh, msh->tkns->args[i][0]);
				return (FALSE);
			}
		}
		i++;
	}
	return (TRUE);
}

int	check_unclosed_quotes(char *input)
{
	int	i;
	int	single;
	int	dbl;

	if (!input)
		return (TRUE);
	i = 0;
	single = 0;
	dbl = 0;
	while (input[i])
	{
		if (input[i] == '\'' && dbl == 0)
			single = !single;
		else if (input[i] == '\"' && single == 0)
			dbl = !dbl;
		i++;
	}
	if (single || dbl)
	{
		printf("minishell: syntax error unclosed quotes\n");
		return (FALSE);
	}
	return (TRUE);
}

int	basic_syntax_checker(char *input, t_msh *msh)
{
	if (check_unclosed_quotes(input) == FALSE)
		return (FALSE);
	if (check_redir_edges(msh) == FALSE)
		return (FALSE);
	if (check_double_pipe(msh) == FALSE)
		return (FALSE);
	if (check_redir_edges(msh) == FALSE)
		return (FALSE);
	if (check_pipe_edges(msh) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	check_pipe_edges(t_msh *msh)
{
	int	i;

	if (!msh || !msh->tkns || !msh->tkns->args)
		return (TRUE);
	i = 0;
	while (msh->tkns->args[i])
	{
		if (ft_strcmp(msh->tkns->args[i], "|") == 0)
		{
			if (i == 0 || !msh->tkns->args[i + 1])
			{
				print_error_msg(msh, '|');
				msh->last_exit_code = 2;
				return (FALSE);
			}
			if (ft_strcmp(msh->tkns->args[i + 1], "|") == 0)
			{
				print_error_msg(msh, '|');
				msh->last_exit_code = 2;
				return (FALSE);
			}
		}
		i++;
	}
	return (TRUE);
}
