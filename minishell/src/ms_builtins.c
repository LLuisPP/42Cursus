/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:12:48 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/29 20:03:04 by lprieto-         ###   ########.fr       */
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
			else if (find_cmd(msh->tkns[i].cmd, msh) == -1)
			{
				cmd_not_found(msh);
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
	else if (ft_strcmp(msh->tkns->cmd, "export") == 0)
		ft_export(msh, "hola");	
	else if (ft_strcmp(msh->tkns->cmd, "unset") == 0)
		ft_unset(msh);	
}

int	is_builtin(t_msh *msh)
{
	char	*builtins[8];
	int		i;

	i = 0;
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "env";
	builtins[4] = "exit";
	builtins[5] = "export";
	builtins[6] = "unset";
	builtins[7] = NULL;

	while (builtins[i])
	{
		if (ft_strcmp(msh->tkns->cmd, builtins[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
