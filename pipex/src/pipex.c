/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/29 12:37:27 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_2(int fork, t_p *pipex, char **env)
{
	if (fork == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (pipex->status_2 < 0)
		exit(EXIT_FAILURE);
	if (dup2(pipex->fd_1[0], 0) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	close(pipex->fd_1[0]);
	close(pipex->fd_1[1]);
	if (dup2(pipex->fd_outp, 1) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	close(pipex->fd_inp);
	close(pipex->fd_outp);
	execve(pipex->cmd[1].path, pipex->cmd[1].cmd, env);
	exit(ft_fd_printf(2, "f2: %s: command not found\n", \
				pipex->cmd[1].cmd[0]) * 0 + 127);
}

int	child_1(int fork, t_p *pipex, char **env)
{
	if (fork == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (pipex->status_1 < 0)
		exit(EXIT_FAILURE);
	if (dup2(pipex->fd_1[1], 1) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	close(pipex->fd_1[0]);
	close(pipex->fd_1[1]);
	if (dup2(pipex->fd_inp, 0) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	close(pipex->fd_inp);
	close(pipex->fd_outp);
	execve(pipex->cmd[0].path, pipex->cmd[0].cmd, env);
	exit(ft_fd_printf(2, "f1: %s: command not found\n", \
				pipex->cmd[0].cmd[0]) * 0 + 127);
}

int	main(int argc, char **argv, char **env)
{
	t_p	pipex;
	int	fork_1;
	int	fork_2;

	ft_bzero(&pipex, sizeof(t_p));
	parse_data(argc, argv, &pipex, env);
	parse_path(env, argv, &pipex);
	pipe(pipex.fd_1);
	fork_1 = fork();
	if (fork_1 == 0)
		child_1(fork_1, &pipex, env);
	fork_2 = fork();
	if (fork_2 == 0)
		child_2(fork_2, &pipex, env);
	close(pipex.fd_1[0]);
	close(pipex.fd_1[1]);
	close(pipex.fd_inp);
	close(pipex.fd_outp);
	waitpid(fork_1, &pipex.status_1, 0);
	waitpid(fork_2, &pipex.status_2, 0);
	return (WEXITSTATUS(pipex.status_2));
}
