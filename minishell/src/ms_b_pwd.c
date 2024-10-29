/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:23 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/29 22:29:18 by lprieto-         ###   ########.fr       */
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
		return (-1);
	if (!getcwd(pwdpath, PATH_MAX))
	{
		free(pwdpath);
		return (-1);
	}
	msh->env->pwd = pwdpath;
	if (ft_fd_printf(1, "%s\n", pwdpath) < 0)
		status = -1;
	free(pwdpath);
	return (status);
}
