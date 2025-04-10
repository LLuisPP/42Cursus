/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:35:57 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/08 09:21:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_quote(char *input, int i)
{
	char	quote;

	quote = input[i];
	i++;
	while (input[i] && input[i] != quote)
		i++;
	if (input[i])
		i++;
	return (i);
}

int	size_token(char *input)
{
	int	i;

	i = 0;
	while (input[i] && !is_whitespace(input[i]))
	{
		if (is_operator(input[i]))
		{
			if (is_operator(input[i + 1]))
				i += 1;
			if (i == 0)
				return (TRUE);
		}
		if (is_pipe(input[i]))
		{
			if (i == 0)
				return (TRUE);
		}
		if (is_quote(input[i]))
		{
			i = process_quote(input, i);
			continue ;
		}
		i++;
	}
	return (i);
}

char	*create_token(char *input, int len, t_tok *tok)
{
	char	*new_token;

	new_token = ft_strndup(input, len);
	(void)tok;
	return (new_token);
}

int	process_token(char *input, int i, t_tok *tok, int *arg_index)
{
	tok->len = size_token(&input[i]);
	if (tok->len > 0)
	{
		tok->args[*arg_index] = create_token(&input[i], tok->len, tok);
		if (!tok->args[*arg_index])
		{
			ft_free_array(tok->args);
			return (-1);
		}
		(*arg_index)++;
		i += tok->len;
	}
	else
		i++;
	return (i);
}

void	ft_token(char *input, t_tok *tok)
{
	int	i;
	int	arg_index;

	tok->args = malloc(sizeof(char *) * MAX_ARGS);
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
		i = process_token(input, i, tok, &arg_index);
		if (i == -1)
			return ;
	}
	tok->args[arg_index] = NULL;
	if (arg_index == 0)
	{
		free(tok->args);
		tok->args = NULL;
	}
}
