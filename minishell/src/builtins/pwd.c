/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:23 by lauriago          #+#    #+#             */
/*   Updated: 2024/11/11 12:44:50 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_msh *msh)
{
	char	*pwdpath;
	int		status;

	status = 0;
	if (!has_redirection(msh->tkns))
	{
		if (msh->tkns->args[1])
		{
			ft_fd_printf(2, "pwd: too many arguments\n");
			status = -1;
			return (status);
		}
	}
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
