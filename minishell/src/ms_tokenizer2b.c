/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer2b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:19:26 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/05 10:36:10 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '$');
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

t_ttype	get_operator_type(char curr, char next)
{
	if (curr == '|')
		return (T_PIPE);
	else if (curr == '<' && next == '<')
		return (T_HEREDOC);
	else if (curr == '>' && next == '>')
		return (T_APPEND);
	else if (curr == '<')
		return (T_REDIR_IN);
	else if (curr == '>')
		return (T_REDIR_OUT);
	else if (curr == '$')
		return (T_ENV);
	return (T_WORD);
}
