/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:26:23 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/21 22:40:08 by lprieto-         ###   ########.fr       */
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

typedef struct s_env		t_env;
typedef struct s_mshll		t_mshll;
typedef struct s_token		t_tok;

/******************************** Structs *********************************/

struct	s_env
{
	char	*name;
	char	*value;
	char	*pwd;
	char	*home;
};

struct	s_token
{
	char	*value;
	size_t	t_len;
};

struct	s_mshll
{
	int		end_sig;
};

/******************************* minishell ********************************/
void	shell_loop(t_env *env, t_mshll *msh);

/******************************* ms_init **********************************/
int		init_structs(t_env *env, t_mshll *msh);

/******************************* ms_parser ********************************/
char	*parse_path(char **env);
char	*parse_pwd(char **env);

/******************************* ms_tokenizer *****************************/
char	*ft_strtok(char *str, const char *separator);

/******************************* ms_rline *********************************/
char	*command_generator(const char *text, int state);
char	**command_completion(const char *text, int start, int end);
char	*file_generator(const char *text, int state);

/******************************* ms_env ***********************************/
int		env_var_count(char **envs);
int		init_env(t_env *env, char **envs);

/******************************* ms_echo **********************************/
int		num_arg(char **argv);
char	*ft_echo(char **argv);

/******************************* ms_tools ******************************/
void	ft_pts(char *s);

/******************************* ms_free **********************************/
void    free_structs(t_env *env, t_tok *tok);

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

/******************************** Other macros ***************************/

# define PATH_MAX	4096

/******************************** Color macros ***************************/

# define RD		"\033[1;31m"
# define GR		"\033[1;32m"
# define YL		"\033[1;33m"
# define BL		"\033[1;34m"
# define PK		"\033[0;35m"
# define PP		"\033[1;35m"
# define CY		"\033[1;36m"
# define CLEAR	"\033[2J\033[H"
# define F		"\033[0m"

#endif
