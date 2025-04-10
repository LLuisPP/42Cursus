/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:45:27 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/03 19:52:31 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_pipe(char *token)
{
	return (token && ft_strcmp(token, "|") == 0);
}

static int	validate_pipe_syntax(t_tok *tok)
{
	int	i;

	i = 0;
	while (tok->args[i])
	{
		if (has_pipe(tok->args[i]))
		{
			if (i == 0 || !tok->args[i + 1])
			{
				ft_fd_printf(2, E_PIP_SNTX);
				return (TRUE);
			}
		}
		i++;
	}
	return (1);
}

static void	init_command_struct(t_cmd *cmd)
{
	int	i;

	i = 0;
	cmd->args = malloc(sizeof(char *) * MAX_ARGS);
	if (!cmd->args)
		return ;
	while (i < MAX_ARGS)
	{
		cmd->args[i] = NULL;
		i++;
	}
	cmd->arg_count = 0;
}

static int	split_commands(t_tok *tok, t_cmd *cmds)
{
	int	i;
	int	cmd_idx;
	int	arg_idx;

	i = 0;
	cmd_idx = 0;
	arg_idx = 0;
	init_command_struct(&cmds[cmd_idx]);
	while (tok->args[i])
	{
		if (has_pipe(tok->args[i]))
		{
			cmds[cmd_idx].args[arg_idx] = NULL;
			cmd_idx++;
			arg_idx = 0;
			init_command_struct(&cmds[cmd_idx]);
		}
		else
		{
			cmds[cmd_idx].args[arg_idx] = ft_strdup(tok->args[i]);
			arg_idx++;
		}
		i++;
	}
	return (cmd_idx + 1);
}

int	parse_and_validate_commands(t_tok *tok, t_cmd **commands)
{
	int		cmd_count;
	t_cmd	*cmds;
	int		i;

	if (!validate_pipe_syntax(tok))
		return (TRUE);
	cmd_count = 1;
	i = 0;
	while (tok->args[i])
	{
		if (has_pipe(tok->args[i]))
			cmd_count++;
		i++;
	}
	cmds = malloc(sizeof(t_cmd) * (cmd_count + 1));
	if (!cmds)
		return (TRUE);
	if (split_commands(tok, cmds) != cmd_count)
	{
		free(cmds);
		return (TRUE);
	}
	*commands = cmds;
	return (cmd_count);
}
