/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:35:57 by lprieto-          #+#    #+#             */
/*   Updated: 2025/01/13 18:40:11 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	size_token(char *input, t_tok *tok)
{
	char	quote;
	int		i;

	(void)tok;
	i = 0;
	while (input[i] && !is_whitespace(input[i]))
	{
		if (is_operator(input[i]))
		{
			if (i == 0)
				return (1);
			break ;
		}
		if (is_quote(input[i]))
		{
			quote = input[i];
			i++;
			while (input[i] && input[i] != quote)
				i++;
			if (input[i])
				i++;
			continue ;
		}
		i++;
	}
	return (i);
}

char	*create_token(char *input, int len, t_tok *tok)
{
	char	*new_token;
	int		i;

	new_token = malloc(sizeof(char) * (len + 1));
	if (!new_token)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_token[i] = input[i];
		i++;
	}
	new_token[i] = '\0';
	tok->cmd = new_token;
	return (new_token);
}

void	ft_token(char *input, t_tok *tok)
{
	int		i;
	int		arg_index;

	tok->args = malloc(MAX_ARGS * sizeof(char *));
	if (!tok->args)
		return ;
	i = 0;
	arg_index = 0;
	while (input[i])
	{
		while (input[i] && is_whitespace(input[i]))
			i++;
		if (!input[i])
			break ;
		tok->len = size_token(&input[i], tok);
		if (tok->len > 0)
		{
			tok->args[arg_index] = create_token(&input[i], tok->len, tok);
			if (!tok->args[arg_index])
				return ;
			arg_index++;
			i += tok->len;
		}
		else
			i++;
	}
	tok->args[arg_index] = NULL;
}
