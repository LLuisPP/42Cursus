/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:23 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/03 19:30:52 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_msh *msh)
{
	char	*pwdpath;
	int		status;

	status = 0;
	pwdpath = NULL;
	pwdpath = (char *)malloc(sizeof(char) * PATH_MAX);
	if (!pwdpath)
		return (FALSE);
	if (!getcwd(pwdpath, PATH_MAX))
	{
		free(pwdpath);
		return (FALSE);
	}
	msh->env->pwd = pwdpath;
	if (ft_fd_printf(1, "%s\n", pwdpath) < 0)
		status = -1;
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
