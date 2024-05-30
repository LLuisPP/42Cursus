/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/30 07:59:01 by lprieto-         ###   ########.fr       */
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
		exit(ft_fd_printf(2, "%s", E_X) * 0 + 126);
	return (0);
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
