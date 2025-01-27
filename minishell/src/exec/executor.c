/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:13:10 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/13 17:46:16 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_command_executable(char *fullpath)
{
	if (access(fullpath, F_OK) == 0 && access(fullpath, X_OK) == 0)
		return (FALSE);
	return (TRUE);
}

static void	child_process(t_msh *msh, char *fullpath)
{
    // printf("Debug args:\n");
    // printf("cmd = %s\n", msh->tkns->cmd);
    // printf("args[0] = %s\n", msh->tkns->args ? msh->tkns->args[0] : "NULL");
	if (execve(fullpath, msh->tkns->args, msh->envs) == -1)
	{
        // printf("execve error: %d\n", errno);
        // perror("execve failed with error");
        // printf("Command attempted: %s\n", fullpath);
        // printf("First arg: %p\n", &msh->tkns->cmd);
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

// // char	*make_path(char *tkn)
// // {
// // 	char	*fullpath;
// // 	fullpath = malloc(strlen("/bin/") + strlen(tkn) + 1);
// // 	if (tkn == NULL || !fullpath)
// // 		return (NULL);
// // 	ft_strcpy(fullpath, "/bin/");
// // 	ft_strcat(fullpath, tkn);
// // 	return (fullpath);
// // }
// char    *make_path(char *tkn)
// {
//     char    *fullpath;
//     const char *paths[] = {"/bin/", "/usr/bin/", NULL};
//     int     i;
//     if (!tkn)
//         return (NULL);
//     i = 0;
//     while (paths[i])
//     {
//         fullpath = malloc(ft_strlen(paths[i]) + ft_strlen(tkn) + 1);
//         if (!fullpath)
//             return (NULL);
//         ft_strcpy(fullpath, paths[i]);
//         ft_strcat(fullpath, tkn);
//         // Si encontramos el comando en esta ruta, lo devolvemos
//         if (access(fullpath, F_OK | X_OK) == 0)
//             return (fullpath);
//         // Si no lo encontramos, liberamos y probamos la siguiente ruta
//         free(fullpath);
//         i++;
//     }
//     return (NULL);
// }

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

	fullpath = make_path(tkn, msh);
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
	return (TRUE);
}

static char	**get_path_dirs(char **envs)
{
	int		i;

	i = 0;
	while (envs[i])
	{
		if (ft_strncmp(envs[i], "PATH=", 5) == 0)
			return (ft_split(envs[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

static char	*check_absolute_path(char *cmd)
{
	if (!cmd)
		return (NULL);
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/')
		|| (cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
	}
	return (NULL);
}

static char	*try_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*cmd_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	cmd_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!cmd_path)
		return (NULL);
	if (access(cmd_path, F_OK | X_OK) == 0)
		return (cmd_path);
	free(cmd_path);
	return (NULL);
}

char	*make_path(char *cmd, t_msh *msh)
{
	char	**paths;
	char	*cmd_path;
	int		i;

	if (!cmd || !msh || !msh->envs)
		return (NULL);
	cmd_path = check_absolute_path(cmd);
	if (cmd_path)
		return (cmd_path);
	paths = get_path_dirs(msh->envs);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		cmd_path = try_path(paths[i], cmd);
		if (cmd_path)
		{
			ft_free_array(paths);
			return (cmd_path);
		}
		i++;
	}
	ft_free_array(paths);
	return (NULL);
}
