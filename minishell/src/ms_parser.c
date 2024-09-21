/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:37:32 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/21 17:17:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Parsea PATH del env del sistema (modificable) Trabajando en ella*/
char	*parse_path(char **envs)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (envs[i] && !path)
	{
		if (ft_strncmp(envs[i], "PATH=", 5) == 0)
		{
			path = ft_split(&envs[i][5], ';');
			if (!path)
				exit (-1);
		}
		i++;
	}
	if (!path)
		exit (-1);
	return (*path);
}

/* Parsea PWD desde el env del sistema (modificable) Trabajando en ella */
char	*parse_pwd(char **envs)
{
	int		i;
	char	**pwd;

	i = 0;
	pwd = NULL;
	while (envs[i] && !pwd)
	{
		if (ft_strncmp(envs[i], "PWD=", 4) == 0)
		{
			pwd = ft_split(&envs[i][5], ';');
			if (!pwd)
				exit (-1);
		}
		i++;
	}
	if (!pwd)
		exit (-1);
	return (*pwd);
}
