/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:23:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/26 17:25:42 by lprieto-         ###   ########.fr       */
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

# define E_ARG "Error: Invalid number of parameters\n"
# define E_MALLOC "Error: Malloc failure\n"
# define E_ENV "Error: No environment\n"
# define E_PATH "Error: No such path\n"
# define E_CMD "Error: Command not found\n"
# define E_OPEN "Error: Can't open file\n"
# define E_WR "Error: Write permission denied\n"
# define E_RD "Error: Read permission denied\n"
# define E_NOFILE "Error: No such file or directory\n"
# define E_DIRECTORY "Error: Is a directory\n"

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
	int		fd_2[2];
	int		status_1;
	int		status_2;
	int		fd_inp;
	int		fd_outp;
}	t_p;

/* Pipex functions */

int parse_data(int argc, char **argv, t_p *pipe, char **env);
void	err_end(char *msg);
int		getpath(char **envpath, t_p *pipe);

#endif
