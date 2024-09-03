/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:08:55 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/30 08:00:50 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	abpath_fill(char **argv, int len, t_p *pipex, int i)
{
	len++;
	free (pipex->cmd[i - 2].path);
	pipex->cmd[i - 2].path = malloc((ft_strlen(argv[i]) + 1) * (sizeof (char)));
	if (!pipex->cmd[i - 2].path)
		exit(ft_fd_printf(2, "%s", E_MALLOC) * 0 + 1);
	ft_strlcpy(pipex->cmd[i - 2].path, argv[i], ft_strlen(argv[i]) + 1);
	ft_strlcpy(pipex->cmd[i - 2].cmd[0], &argv[i][len], len
		- ft_strlen(argv[i]));
}

int	check_abpath(char **argv, t_p *pipex)
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
			abpath_fill(argv, len, pipex, i);
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
