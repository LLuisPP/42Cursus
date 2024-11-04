/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:00:38 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/02 11:07:22 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '$');
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

// static int	is_quote(char c)
// {
// 	return (c == '"' || c == '\'');
// }

static t_ttype	get_operator_type(char curr, char next)
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

static void	init_token(t_tok *token)
{
	token->cmd = NULL;
	token->args = NULL;
	token->is_heredoc = 0;
	token->heredoc_delim = NULL;
	token->t_len = 0;
	token->input = NULL;
	token->position = 0;
	token->type = T_WORD;
}

static void	handle_operator(char *input, size_t *pos, t_tok *token)
{
	char	curr;
	char	next;

	curr = input[*pos];
	next = input[*pos + 1];
	token->type = get_operator_type(curr, next);
	if ((token->type == T_HEREDOC || token->type == T_APPEND)
		&& next == curr)
	{
		token->cmd = ft_substr(input, *pos, 2);
		(*pos) += 2;
	}
	else
	{
		token->cmd = ft_substr(input, *pos, 1);
		(*pos)++;
	}
	if (token->type == T_HEREDOC)
		token->is_heredoc = 1;
}

static void	handle_word(char *input, size_t *pos, t_tok *token)
{
	size_t	start;
	size_t	len;

	start = *pos;
	len = 0;
	while (input[*pos] && !is_whitespace(input[*pos])
		&& !is_operator(input[*pos]))
	{
		len++;
		(*pos)++;
	}
	token->cmd = ft_substr(input, start, len);
	token->type = T_WORD;
	token->t_len = len;
}

static size_t	count_tokens(char *input)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (input[i])
	{
		while (is_whitespace(input[i]))
			i++;
		if (input[i])
		{
			count++;
			if (is_operator(input[i]))
			{
				if ((input[i] == '<' && input[i + 1] == '<')
					|| (input[i] == '>' && input[i + 1] == '>'))
					i += 2;
				else
					i++;
			}
			else
				while (input[i] && !is_whitespace(input[i])
					&& !is_operator(input[i]))
					i++;
		}
	}
	return (count);
}

int	tokenize_input(char *input, t_msh *msh)
{
	size_t	pos;
	size_t	token_count;
	size_t	current_token;

	if (!input)
		return (-1);
	token_count = count_tokens(input);
	msh->tkns = malloc(sizeof(t_tok) * (token_count + 1));
	if (!msh->tkns)
		return (-1);
	pos = 0;
	current_token = 0;
	while (input[pos] && current_token < token_count)
	{
		while (is_whitespace(input[pos]))
			pos++;
		if (!input[pos])
			break ;
		init_token(&msh->tkns[current_token]);
		if (is_operator(input[pos]))
			handle_operator(input, &pos, &msh->tkns[current_token]);
		else
			handle_word(input, &pos, &msh->tkns[current_token]);
		current_token++;
	}
	msh->tkns[current_token].cmd = NULL;
	return (0);
}
