/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:12:48 by lauriago          #+#    #+#             */
/*   Updated: 2025/03/28 11:14:10 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_not_found(t_msh *msh)
{
	ft_fd_printf(2, "Error: %s : command not found\n", msh->tkns->cmd);
	msh->last_exit_code = 127;
}

void	check_tokens(char *input, t_msh *msh)
{
	int	count_tok;

	if (!input || !*input)
		return ;
	ft_token(input, msh->tkns);
	if (!msh->tkns->args || !msh->tkns->args[0])
		return ;
	count_tok = 0;
	while (msh->tkns->args[count_tok])
		count_tok++;
	msh->tkns->token_count = count_tok;
	msh->tkns->cmd = ft_strdup(msh->tkns->args[0]);
	if (!redir_checker(msh))
	{
		if (is_builtin(msh->tkns->cmd))
			exc_cmd(msh, count_tok);
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
	static char	*builtins[10];
	int			i;

	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "env";
	builtins[4] = "exit";
	builtins[5] = "export";
	builtins[6] = "unset";
	builtins[7] = "test";
	builtins[8] = "test2";
	builtins[9] = NULL;
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
	else if (ft_strcmp(msh->tkns->cmd, "test") == 0)
		ft_fd_printf(1, "Envarcount: %d\n", msh->env_var_count);
	else
		return ;
}
