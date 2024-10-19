/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:13:10 by lprieto-          #+#    #+#             */
/*   Updated: 2024/10/07 13:49:37 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*make_path(t_msh *msh)
{
	char	*dir;
	char	*fullpath;

	dir = ft_strtok(msh->env->path, ":");
	fullpath = malloc(sizeof(char) * 1024);
	ft_strcpy(fullpath, dir);
	ft_strcat(fullpath, dir);
	ft_strcat(fullpath, "/");
	ft_strcat(fullpath, msh->tkns->cmd);
	return (fullpath);
}

int	find_cmd(t_msh *msh)
{
	char	*fullpath;

	printf("Hola\n");
	fullpath = make_path(msh);
	printf("fullpath = %s\n", fullpath);
	if (access(fullpath, F_OK) == 0)
	{
		printf("Es accesible\n");
		if (execve(fullpath, &msh->tkns->cmd, msh->envs) == -1)
		{
			printf("Error execve\n");
			cmd_not_found(msh);
			free(fullpath);
			return (-1);
		}
	}
	return (0);
}