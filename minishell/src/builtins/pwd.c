/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:23 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/08 09:36:16 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_msh *msh)
{
	char	*pwdpath;
	char	*tmp;
	int		status;

	status = 0;
	pwdpath = getcwd(NULL, 0);
	if (!pwdpath)
		return (FALSE);
	tmp = ft_strdup(pwdpath);
	if (!tmp)
	{
		free(pwdpath);
		return (FALSE);
	}
	update_env(msh, "PWD", tmp);
	if (ft_fd_printf(1, "%s\n", pwdpath) < 0)
		status = -1;
	else
		status = TRUE;
	free(tmp);
	free(pwdpath);
	return (status);
}

int	builtin_redir_check(t_msh *msh)
{
	if (ft_strcmp(msh->tkns->args[1], ">") == 0
		|| ft_strcmp(msh->tkns->args[1], ">>") == 0
		|| ft_strcmp(msh->tkns->args[1], "<") == 0
		|| ft_strcmp(msh->tkns->args[1], "<<") == 0)
		return (TRUE);
	return (FALSE);
}
