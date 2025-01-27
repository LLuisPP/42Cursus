/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:19:26 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/13 17:33:22 by leegon           ###   ########.fr       */
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
	return (c == '\"' || c == '\'');
}

// token_type_t	type_token_def(t_tok *tok, char c)
// {
// 	if (is_quote(c))
// 		tok->type = T_QUOTE;
// 	if (is_operator(c))
// 		tok->type = T_OPERATOR;
// 	if (is_whitespace(c))
// 		tok->type = T_WHITESPACE;
// 	else if (!is_operator(c) && !is_quote(c) && !is_whitespace(c))
// 		tok->type = T_WORD;
// 	return (tok->type);
// }
