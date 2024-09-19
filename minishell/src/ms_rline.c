/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_rline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:34:50 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/19 19:18:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*command_generator(const char *cmnd, int state)
{
	static int	lst_idx;
	static int	len;
	char		*name;
	static char	*cmd_lst[] = {"cd", "exit", "ls", "echo", "touch", "clear",
		 "mkdir", NULL};

	if (!state)
	{
		lst_idx = 0;
		len = ft_strlen(cmnd);
		if (len == 0)
			return (NULL);
	}
	name = cmd_lst[lst_idx];
	while (name)
	{
		if (ft_strncmp(name, cmnd, len) == 0)
			return (ft_strdup(name));
		name = cmd_lst[lst_idx];
		lst_idx++;
	}
	return (NULL);
}

char	**command_completion(const char *cmnd, int start, int end)
{
	char	**matches;

	matches = NULL;
	if (start != 0 && end > start)
		matches = rl_completion_matches(cmnd, file_generator);
	else
		matches = rl_completion_matches(cmnd, command_generator);
	return (matches);
}

char	*file_generator(const char *cmnd, int state)
{
	static DIR				*dir;
	static struct dirent	*entry;
	int						len;

	len = ft_strlen(cmnd);
	if (!state)
		dir = opendir(".");
	if (dir)
	{
		entry = readdir(dir);
		while (entry != NULL)
		{
			if (ft_strncmp(entry->d_name, cmnd, len) == 0)
				return (ft_strdup(entry->d_name));
			entry = readdir(dir);
		}
		closedir (dir);
		dir = NULL;
	}
	return (NULL);
}
