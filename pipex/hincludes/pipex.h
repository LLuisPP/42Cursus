/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:23:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/29 12:34:23 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

/* * * * * * * * *   Error macros * * * * * * * * * */

# define E_ARG "Invalid number of parameters\n"
# define E_MALLOC "Malloc failure\n"
# define E_ENV "Error: No environment\n"
# define E_PATH "No such path\n"
# define E_CMD "Error: Command not found\n"
# define E_OPEN "Can't open file\n"
# define E_WR "W Permission denied\n"
# define E_RD "R Permission denied\n"
# define E_X "X Permission denied\n"
# define E_NOFILE "No such file or directory\n"
# define E_DIRECTORY "Is a directory\n"

/* Structs */

typedef struct s_commands
{
	char	*path;
	char	**cmd;
}	t_cmd;

typedef struct s_pipe
{
	t_cmd	cmd[2];
	int		fd_1[2];
	int		status_1;
	int		status_2;
	int		fd_inp;
	int		fd_outp;
}	t_p;

/* Pipex functions */

int	parse_data(int argc, char **argv, t_p *pipex, char **env);
int	parse_path(char **env, char **argv, t_p *pipex);
int	get_data(char **argv, t_p *pipex, char **path);
int	get_path(char **envpath, t_p *pipex);
int	child_1(int fork, t_p *pipex, char **env);
int	child_2(int fork, t_p *pipex, char **env);
int	check_abpath(char **argv, t_p *pipex);

#endif
