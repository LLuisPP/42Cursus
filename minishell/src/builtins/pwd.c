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
	char	*dir;

	(void)msh;
	dir = ft_calloc(PATH_MAX, 1);
	if (!dir)
		exit(FALSE);
	if (getcwd(dir, PATH_MAX) == NULL)
	{
		free(dir);
		return (FALSE);
	}
	dir = getcwd(dir, PATH_MAX);
	printf("%s\n", dir);
	if (dir)
	{
		free(dir);
		dir = NULL;
	}
	return (TRUE);
}
