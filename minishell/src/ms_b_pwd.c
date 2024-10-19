/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:23 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/07 13:51:33 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_msh *msh)
{
	char	*pwdpath;

	pwdpath = (char *)malloc(sizeof(char) * PATH_MAX);
	if (!pwdpath)
		return (-1);
	getcwd(pwdpath, PATH_MAX);
	msh->env->pwd = pwdpath;
	ft_fd_printf(1, "%s\n", pwdpath);
	return (1);
}
