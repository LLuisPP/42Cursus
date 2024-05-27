/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/27 07:24:23 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	child_2(int fork, t_p *pipe, char **env)
{
	if (fork == -1)
	{
		perror("Pipex: ");
		exit(1);
	}
	if (pipe->status_2 < 0)
		exit(1);
	if (dup2(pipe->fd_1[0], 0) == -1)
	{
		perror("Pipex: ");
		exit(1);
	}
	close(pipe->fd_1[0]);
	close(pipe->fd_1[1]);
	if (dup2(pipe->fd_inp, 1) == -1)
	{
		perror("Pipex: ");
		exit(1);
	}
	close(pipe->fd_inp);
	close(pipe->fd_outp);
	execve(pipe->cmd[1].path, pipe->cmd[1].cmd, env);
	exit(ft_fd_printf(2, "Pipex: [%s] Command not found\n", \
				pipe->cmd[0].cmd[0]) * 0 + 127);
}

int	child_1(int fork, t_p *pipe, char **env)
{
	if (fork == -1)
	{
		perror("Pipex: ");
		exit(1);
	}
	if (pipe->status_1 < 0)
		exit(1);
	if (dup2(pipe->fd_1[1], 1) == -1)
	{
		perror("Pipex: ");
		exit(1);
	}
	close(pipe->fd_1[0]);
	close(pipe->fd_1[1]);
	if (dup2(pipe->fd_inp, 0) == -1)
	{
		perror("Pipex: ");
		exit(1);
	}
	close(pipe->fd_inp);
	close(pipe->fd_outp);
	execve(pipe->cmd[0].path, pipe->cmd[0].cmd, env);
	exit(ft_fd_printf(2, "Pipex: [%s] Command not found\n", \
				pipe->cmd[0].cmd[0]) * 0 + 127);
}

int	main(int argc, char **argv, char **env)
{
	t_p	*pipe;
	int	fork_1;
	int	fork_2;

	ft_bzero(&pipe, sizeof(t_p));
	pipe = (t_p *)malloc(sizeof(t_p));
	if (!pipe)
		exit(ft_fd_printf(2, "%s", E_PATH) * 0 + 1);
	parse_data(argc, argv, pipe, env);
	fork_1 = fork();
	if (fork_1 == 0)
		child_1(fork_1, pipe, env);
	fork_2 = fork();
	if (fork_2 == 0)
		child_2(fork_2, pipe, env);
	close(pipe->fd_1[0]);
	close(pipe->fd_2[1]);
	close(pipe->fd_inp);
	close(pipe->fd_outp);
	waitpid(fork_1, &pipe->status_1, 0);
	waitpid(fork_2, &pipe->status_2, 0);
	free(pipe);
	return (0);
}
