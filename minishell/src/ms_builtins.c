/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:12:48 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/06 19:23:18 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_not_found(t_msh *msh)
{
	ft_fd_printf(2, "Error: ");
	ft_fd_printf(2, "%s", msh->tkns->cmd);
	ft_fd_printf(2, ": command not found\n");
}

void	check_tokens(char *input, t_msh *msh)
{
	int		i;
	int		count_tok;

	i = 0;
	count_tok = 0;
	if (tokenize_input(input, msh) == 0)
	{
		while (msh->tkns[count_tok].cmd)
			count_tok++;
		while (msh->tkns[i].cmd != NULL)
		{
			if (is_builtin(msh) == 0)
			{
				exc_cmd(msh, count_tok);
				break ;
			}
			else
			{
				find_cmd(msh);
				//	cmd_not_found(msh);
				break ;
			}
			i++;
		}
	}
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
	else if (ft_strcmp(msh->tkns->cmd, "clear") == 0)
		ft_fd_printf(1, "%s", CLEAR);
}

int	is_builtin(t_msh *msh)
{
	if (ft_strcmp(msh->tkns->cmd, "echo") == 0)
		return (0);
	else if (ft_strcmp(msh->tkns->cmd, "cd") == 0)
		return (0);
	else if (ft_strcmp(msh->tkns->cmd, "pwd") == 0)
		return (0);
	else if (ft_strcmp(msh->tkns->cmd, "env") == 0)
		return (0);
	else if (ft_strcmp(msh->tkns->cmd, "exit") == 0)
		return (0);
	else if (ft_strcmp(msh->tkns->cmd, "clear") == 0)
		return (0);
	return (1);
}