/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_lexer_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:00:22 by lauriago          #+#    #+#             */
/*   Updated: 2025/01/09 16:59:04 by lauriago         ###   ########.fr       */
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

/*static void	quote_status(t_msh *msh, char c)
{
	if (c == '\'')
		msh->quote->single_count++;
	else if (c == '\"')
		msh->quote->double_count++;
	if (c == '\'' && msh->quote->active_quote != DOUBLE_QUOTE)
	{
		if (msh->quote->active_quote == NO_QUOTE)
			msh->quote->active_quote = SINGLE_QUOTE;
		else if (msh->quote->active_quote == SINGLE_QUOTE)
			msh->quote->active_quote = NO_QUOTE;
	}
	else if (c == '\"' && msh->quote->active_quote != SINGLE_QUOTE)
	{
		if (msh->quote->active_quote == NO_QUOTE)
			msh->quote->active_quote = DOUBLE_QUOTE;
		else if (msh->quote->active_quote == DOUBLE_QUOTE)
			msh->quote->active_quote = NO_QUOTE;
	}
}*/

int	analyze_quotes(t_msh *msh, char *arg)
{
	t_quote	*q;
	int		i;

	i = 0;
	msh->quote = init_quotes();
	q = msh->quote;
	if (!arg || !msh || !msh->quote)
		return(FALSE);
	//Contador de comillas simples y dobles
	while (arg[i] != '\0')
	{
		if (arg[i] == '\'')
			q->single_count++;
		else if (arg[i] == '\"')
			q->double_count++;
		i++;
	}
	// si solo hay comillas dobles, si son pares
	if (q->single_count == 0 && q->double_count % 2 == 0)
	{
		q->active_quote = SINGLE_QUOTE;
		return (TRUE);
	}
	if (q->double_count == 0 && q->single_count % 2 == 0)
	{
		q->active_quote = DOUBLE_QUOTE;
		return (TRUE);
	}
	printf("SD %% 2 = %d\nDC %% 2 = %d\n", msh->quote->single_count % 2, msh->quote->double_count % 2);
	printf("is_closed = %d\n", q->is_closed);
	return (FALSE);
}

void	handle_quotes(t_msh *msh, t_quote *q, int i)
{
	char	*str;

	msh->quote = init_quotes();
	q = msh->quote;
	if (!q || !msh || !msh->tkns || !msh->tkns->args[i])
		return;
	if (analyze_quotes(msh, msh->tkns->args[i]))
	{
		if (q->active_quote == SINGLE_QUOTE)
		{
			str = remove_quotes(msh->tkns->args[i], '\'');
			ft_putstr_fd(str, 1);
			free(str);
		}
		else if (q->active_quote == DOUBLE_QUOTE)
			expand_and_remove_quotes(msh->tkns->args[i], msh);
		else
			ft_putstr_fd(msh->tkns->args[i], 1);
	}
	else //(!(analyze_quotes(msh, msh->tkns->args[i])))
		ft_fd_printf(2, E_CMD);
}
