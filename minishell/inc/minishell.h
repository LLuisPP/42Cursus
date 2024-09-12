/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:26:23 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/09 11:31:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "readline/readline.h"
# include "readline/history.h"
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <string.h>

/******************************** Structs Simplification ******************/

typedef struct s_history t_hist;
typedef	struct s_env t_env;

/******************************** Structs *********************************/

struct	s_history
{
	char	**commands;
	int		count;
	int		capacity;
};

struct	s_env
{
	char	*path;
	char	*pwd;
	char	*home;
};

/******************************* Functions ********************************/

char	*command_generator(const char *text, int state);
char	**command_completion(const char *text, int start, int end);
char	*file_generator(const char *text, int state);
char	*parse_path(char **env);

/******************************* Parsing **********************************/

char	*ft_strtok(char *str, const char *separator);
char	*parse_pwd(char **env);

/******************************* Tokenizer ********************************/

/******************************* Initialize *******************************/

int	init_structs(t_env *env, t_hist *hist);

/******************************* Executor *********************************/


/******************************* Error macros *****************************/

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
# define E_EXECARG "Error: minishell doesn't accept arguments\n"

/******************************** Color macros ***************************/

# define RD		"\033[1;31m"
# define GR		"\033[1;32m"
# define YL		"\033[1;33m"
# define BL		"\033[1;34m"
# define PK		"\033[0;35m"
# define PP		"\033[1;35m"
# define CY		"\033[1;36m"
# define F		"\033[0m"

#endif
