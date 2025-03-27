/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:35:57 by lprieto-          #+#    #+#             */
/*   Updated: 2025/02/19 02:04:55 by lprieto-         ###   ########.fr       */
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
			if (is_operator(input[i + 1]))
				i += 1;
		}
		if (is_pipe(input[i]))
		{
			if (i == 0)
				return (TRUE);
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

	new_token = ft_strndup(input, len);
	(void)tok;
	return (new_token);
}

void	ft_token(char *input, t_tok *tok)
{
	int		i;
	int		arg_index;

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
		tok->len = size_token(&input[i], tok);
		if (tok->len > 0)
		{
			tok->args[arg_index] = create_token(&input[i], tok->len, tok);
			if (!tok->args[arg_index])
			{
				ft_free_array(tok->args);
				return ;
			}
			arg_index++;
			i += tok->len;
		}
		else
			i++;
	}
	tok->args[arg_index] = NULL;
	if (arg_index == 0)
	{
		free(tok->args);
		tok->args = NULL;
	}
	// for (i=0; i < arg_index; i++){
	// 	printf("tok[%d] = %s\n", i, tok->args[i]);
	// }
}
