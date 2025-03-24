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

// 1.Verificar que hay minimo 2 comillas o numero multiple de 2
void	handle_single_quotes(t_msh *msh, int i)
{
	char	*str;

	str = ft_strdup(msh->tkns->args[i]);
	if (!analyze_quotes(msh, msh->tkns->args[i], '\''))
		ft_fd_printf(2, E_SYNTX);
	else
		printf("%s", remove_quotes(str, '\''));
}

// 1.Verificar que hay minimo 2 comillas o numero multiple de 2
void	handle_double_quotes(t_msh *msh, int i)
{
	char	*str;

	str = ft_strdup(msh->tkns->args[i]);
	if (!analyze_quotes(msh, msh->tkns->args[i], '\"'))
		ft_fd_printf(2, E_SYNTX);
	else
	{
		str = remove_quotes(str, '\"');
		ft_expander(str, msh);
	}
}
