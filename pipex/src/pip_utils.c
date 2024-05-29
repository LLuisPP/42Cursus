/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:08:55 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/29 12:35:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	check_abpath (char **argv, t_p *pipex)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (++i <= 3)
	{
		len = 0;
		j = ft_strlen(argv[i]);
		while (j > 0 && len == 0)
		{
			if (argv[i][j] == '/')
				len = j;	
			j--;
		}
		if (len != 0)
		{
			len++;
			free (pipex->cmd[i - 2].path);
			pipex->cmd[i - 2].path = malloc((ft_strlen(argv[i]) + 1)*(sizeof (char)));
			if (!pipex->cmd[i - 2].path)
				exit(ft_fd_printf(2, "%s", E_MALLOC) * 0 + 1);
			ft_strlcpy(pipex->cmd[i - 2].path, argv[i], ft_strlen(argv[i]) + 1);
			ft_strlcpy(pipex->cmd[i -2].cmd[0], &argv[i][len], len - ft_strlen(argv[i]));
		}
	}
	return (0);
}

int	get_path(char **path, t_p *pipex)
{
	char	*tmp;
	int		i;
	int		j;

	j = -1;
	while (++j <= 1)
	{
		i = -1;
		while (path[++i] && !pipex->cmd[j].path)
		{
			tmp = ft_strjoin(path[i], pipex->cmd[j].cmd[0]);
			if (!tmp)
				exit(ft_fd_printf(2, "%s", E_MALLOC) * 0 + 1);
			if (access(tmp, F_OK) == 0)
				pipex->cmd[j].path = ft_strdup(tmp);
			// ft_printf("path_line: %s\n", tmp);
			if (tmp)
			{
				free(tmp);
				tmp = NULL;
			}
		}
	}
	return (0);
}

int	get_data(char **argv, t_p *pipex, char **path)
{
	char	*tmp;
	int		i;

	i = 0;
	pipex->cmd[0].cmd = ft_split(argv[2], ' ');
	pipex->cmd[1].cmd = ft_split(argv[3], ' ');
	if (!pipex->cmd[0].cmd || !pipex->cmd[1].cmd)
		exit(ft_fd_printf(2, "%s", E_MALLOC) * 0 + 1);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			exit(ft_fd_printf(2, "%s", E_MALLOC) * 0 + 1);
		else
		{
			free(path[i]);
			path[i] = ft_strdup(tmp);
			free(tmp);
			tmp = NULL;
		}
		i++;
	}
	get_path(path, pipex);
	check_abpath(argv, pipex);
	return (0);
}

int	parse_path(char **env, char **argv, t_p *pipex)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (env[i] && !path)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(&env[i][5], ':');
			if (!path)
				exit(ft_fd_printf(2, "%s", E_MALLOC) * 0 + 1);
		}
		i++;
	}
	if (!path)
		exit(ft_fd_printf(2, "%s", E_PATH) * 0 + 1);
	get_data(argv, pipex, path);
	return (0);
}

int	parse_data(int argc, char **argv, t_p *pipex, char **env)
{
	if (!env)
		exit(ft_fd_printf(2, "%s", E_ENV) * 0 + 1);
	if (argc != 5)
		exit(ft_fd_printf(2, "%s", E_ARG) * 0 + 1);
	if (access(argv[1], F_OK) == -1)
		pipex->status_1 = ft_fd_printf(2, "%s: %s", argv[1], E_NOFILE) * 0 - 1;
	else if (access(argv[1], R_OK) == -1)
		pipex->status_1 = ft_fd_printf(2, "%s: %s", argv[1], E_RD) * 0 - 1;
	if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) == -1)
		pipex->status_2 = ft_fd_printf(2, "%s: %s", argv[4], E_WR) * 0 - 1;
	pipex->fd_inp = open(argv[1], O_RDONLY);
	if (pipex->fd_inp < 0)
		pipex->status_1 = ft_fd_printf(2, "%s: %s", argv[1], E_OPEN) * 0 - 1;
	pipex->fd_outp = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0666);
	if (pipex->fd_outp < 0)
		pipex->status_2 = ft_fd_printf(2, "%s: %s", argv[4], E_OPEN) * 0 - 1;
	if (!pipex->fd_inp || !pipex->fd_outp)
		exit(ft_fd_printf(2, "%s", E_MALLOC) * 0 + 1);
	if (ft_strchr(argv[2], '/') != 0 && access(argv[2], X_OK) == -1)
		exit(ft_fd_printf(2, "%s", E_X) * 0 + 126);
	if (ft_strchr(argv[3], '/') != 0 && access(argv[3], X_OK) == -1)
		exit(ft_fd_printf(2, "%s", E_X) * 0 + 126 );
		
	return (0);
}


