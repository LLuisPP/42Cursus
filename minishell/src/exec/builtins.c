/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:12:48 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/15 23:52:36 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	reset_cmd_and_args(t_msh *msh)
{
	if (msh->tkns->cmd)
	{
		free(msh->tkns->cmd);
		msh->tkns->cmd = NULL;
	}
	if (msh->tkns->args)
	{
		ft_free_array(msh->tkns->args);
		msh->tkns->args = NULL;
	}
	if (msh->tkns->countpip)
	{
		free(msh->tkns->countpip);
		msh->tkns->countpip = NULL;
	}
	if (msh->tkns->typepip)
	{
		free(msh->tkns->typepip);
		msh->tkns->typepip = NULL;
	}
}

void	check_tokens(char *input, t_msh *msh)
{
	if (!input || !*input)
		return ;
	reset_cmd_and_args(msh);
	ft_token(input, msh->tkns);
	if (basic_syntax_checker(input, msh) == FALSE)
		return ;
	if (!msh->tkns->args || !msh->tkns->args[0])
		return ;
	msh->tkns->token_count = 0;
	while (msh->tkns->args[msh->tkns->token_count])
		msh->tkns->token_count++;
	msh->tkns->cmd = ft_strdup(msh->tkns->args[0]);
	if (!redir_checker(msh))
	{
		if (msh->tkns->first_redir_type == REDIR_ERROR)
			return ;
		if (is_builtin(msh->tkns->cmd))
			exc_cmd(msh, msh->tkns->token_count);
		else if (find_cmd(msh->tkns->cmd, msh) == -1)
			cmd_not_found(msh);
	}
	restore_signals();
	cleanup_commands(msh);
}

void	cleanup_commands(t_msh *msh)
{
	int	i;
	int	j;

	i = 0;
	while (i < msh->cmd_count)
	{
		j = 0;
		while (msh->cmds[i].args[j])
		{
			free(msh->cmds[i].args[j]);
			j++;
		}
		free(msh->cmds[i].args);
		i++;
	}
	free(msh->cmds);
	msh->cmds = NULL;
	msh->cmd_count = 0;
}

int	is_builtin(char	*token)
{
	static char	*builtins[8];
	int			i;

	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "env";
	builtins[4] = "exit";
	builtins[5] = "export";
	builtins[6] = "unset";
	builtins[7] = NULL;
	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(token, builtins[i]) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	exc_cmd(t_msh *msh, int count_tok)
{
	if (ft_strcmp(msh->tkns->cmd, "echo") == 0)
		ft_echo(msh, count_tok);
	else if (ft_strcmp(msh->tkns->cmd, "cd") == 0)
		ft_cd(msh, count_tok);
	else if (ft_strcmp(msh->tkns->cmd, "pwd") == 0)
		ft_pwd(msh);
	else if (ft_strcmp(msh->tkns->cmd, "env") == 0)
		ft_env(msh);
	else if (ft_strcmp(msh->tkns->cmd, "exit") == 0)
		ft_exit(msh);
	else if (ft_strcmp(msh->tkns->cmd, "export") == 0)
		ft_export(msh, count_tok);
	else if (ft_strcmp(msh->tkns->cmd, "unset") == 0)
		ft_unset(msh, count_tok);
	else
		return ;
}
