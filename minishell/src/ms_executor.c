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

static int	is_command_executable(char *fullpath)
{
	if (access(fullpath, F_OK) == 0 && access(fullpath, X_OK) == 0)
		return (1);
	return (0);
}

static void	child_process(t_msh *msh, char *fullpath)
{
	if (execve(fullpath, &msh->tkns->cmd, msh->envs) == -1)
	{
		printf("Error execve\n");
		cmd_not_found(msh);
		free(fullpath);
		exit(EXIT_FAILURE);
	}
}

static void	parent_process(pid_t pid, char *fullpath)
{
	int	status;

	waitpid(pid, &status, 0);
	free(fullpath);
}

char	*make_path(char *tkn)
{
	char	*fullpath;

	fullpath = malloc(strlen("/bin/") + strlen(tkn) + 1);
	if (tkn == NULL || !fullpath)
		return (NULL);
	ft_strcpy(fullpath, "/bin/");
	ft_strcat(fullpath, tkn);
	return (fullpath);
}

int	execute_command(t_msh *msh, char *fullpath)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		printf("Error fork\n");
		free(fullpath);
		return (-1);
	}
	else if (pid == 0)
		child_process(msh, fullpath);
	else
		parent_process(pid, fullpath);
	return (0);
}

int	find_cmd(char *tkn, t_msh *msh)
{
	char	*fullpath;

	fullpath = make_path(tkn);
	printf("fullpath is --> %s\n", fullpath);
	if (is_command_executable(fullpath))
	{
		if (execute_command(msh, fullpath) == -1)
			return (-1);
	}
	else
	{
		free(fullpath);
		return (-1);
	}
	return (0);
}
/*

==1071002== Conditional jump or move depends on uninitialised value(s)
==1071002==    at 0x10BE93: ft_strcat (in /home/lauriago/Projects42/minishell/23-oct/minishell)
==1071002==    by 0x10A531: make_path (ms_executor.c:49)
==1071002==    by 0x10A5CB: find_cmd (ms_executor.c:75)
==1071002==    by 0x109EDB: check_tokens (ms_builtins.c:40)
==1071002==    by 0x109485: shell_loop (minishell.c:34)
==1071002==    by 0x1095D6: main (minishell.c:62)
==1071002== 

*/
