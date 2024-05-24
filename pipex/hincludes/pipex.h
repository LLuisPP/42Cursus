/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:23:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/24 10:29:05 by lprieto-         ###   ########.fr       */
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

/* structs */

typedef struct s_pipe
{
	int		argc;
	char	**argv;
	char	**env;
	char	**path;

}	t_p;

/* pipex functions */

void	err_end(char *msg);

#endif
