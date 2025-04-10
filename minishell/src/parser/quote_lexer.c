/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:00:22 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/08 09:52:42 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_quote	*init_quotes(void)
{
	t_quote	*quote;

	quote = malloc(sizeof(t_quote));
	if (!quote)
		return (NULL);
	*quote = (t_quote){0, 0, NO_QUOTE, FALSE};
	return (quote);
}

int	analyze_quotes(t_msh *msh, char *arg, char quote)
{
	t_quote	*q;
	int		i;

	i = 0;
	msh->quote = init_quotes();
	q = msh->quote;
	if (!arg || !msh || !msh->quote)
		return (FALSE);
	while (arg[i] != '\0')
	{
		if (arg[i] == '\'')
			q->single_count++;
		if (arg[i] == '\"')
			q->double_count++;
		i++;
	}
	if (q->single_count % 2 == 0 && quote == '\'')
		return (TRUE);
	if (q->double_count % 2 == 0 && quote == '\"')
		return (TRUE);
	return (FALSE);
}

void	handle_single_quotes(t_msh *msh, int i)
{
	char	*str;
	char	*str_rmv;

	str = ft_strdup(msh->tkns->args[i]);
	if (!analyze_quotes(msh, msh->tkns->args[i], '\''))
	{
		ft_fd_printf(2, E_SYNTX);
		msh->last_exit_code = 2;
	}
	else
	{
		str_rmv = remove_quotes(str, '\'');
		ft_putstr(str_rmv);
		free(str_rmv);
	}
	free(str);
	if (msh->quote)
	{
		free(msh->quote);
		msh->quote = NULL;
	}
}

void	handle_double_quotes(t_msh *msh, int i)
{
	char	*cleaned;

	if (!analyze_quotes(msh, msh->tkns->args[i], '\"'))
	{
		ft_fd_printf(2, E_SYNTX);
		msh->last_exit_code = 2;
	}
	else
	{
		cleaned = remove_quotes(msh->tkns->args[i], '\"');
		if (!cleaned)
			return ;
		ft_expander(cleaned, msh);
		free(cleaned);
	}
	if (msh->quote)
	{
		free(msh->quote);
		msh->quote = NULL;
	}
}
