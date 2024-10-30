/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:26:23 by lprieto-          #+#    #+#             */
/*   Updated: 2024/10/30 08:31:13 by lprieto-         ###   ########.fr       */
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
typedef struct s_environment	t_env;
typedef struct s_minishell		t_msh;
typedef struct s_tokenizer		t_tok;
typedef struct s_executor		t_exe;

/******************************** Structs *********************************/

struct	s_environment
{
	char	**names;
	char	**values;
	char	*pwd;
	char	*old_pwd;
	char	*home;
	char	*path;
	int		env_count;
	int		exit_status;
};

struct	s_tokenizer
{
	char	*cmd;
	char	**args;
	int		is_heredoc;
	char	*heredoc_delim;
	size_t	t_len;
};

struct s_executor
{
	int		fd_1[2];
	int		status_1;
	int		status_2;
	int		fd_in;
	int		fd_out;
};

struct	s_minishell
{
	t_tok	*tkns;
	t_env	*env;
	t_exe	*mpip;
	int		end_sig;
	int		last_exit_code;
	char	**envs;
};

/******************************* minishell ********************************/
void	shell_loop(t_msh *msh);

/******************************* ms_init **********************************/
int		init_envi(t_env **env, t_msh *msh);
int		init_tok(t_tok **tok);
int		init_mpip(t_exe **mpip);
int		init_strc(t_env **env, t_msh *msh, t_exe **mpip, t_tok **tok);

/******************************* ms_parser ********************************/
char	*parse_path(char **env);
char	*parse_pwd(char **env);
int		parse_input(char *input, t_msh *mshll);

/******************************* ms_tokenizerenizer ***********************/
char	*ft_strtok(char *str, const char *separator);
int		tokenize_input(char *input, t_msh *msh);

/******************************* ms_rline *********************************/
char	*cmd_gen(const char *text, int state);
char	**cmd_comp(const char *text, int start, int end);
char	*cmd_match(const char *text, int state);

/******************************* ms_environment ***************************/
int		env_var_count(t_msh *msh);
int		init_env(t_env *env, t_msh *msh);

/******************************* ms_lexer *********************************/
int		lexer(char **tokens, t_msh *msh);
int		quote_lexer(t_msh *msh);

/******************************* ms_executor ******************************/
int		find_cmd(char *tkn, t_msh *msh);
char	*make_path(char *tkn, t_msh *msh);

/******************************* ms_echo **********************************/
void	ft_echo(t_msh *msh, int num_cmd);

/******************************** ms_cd ***********************************/
char	*built_abspath(char *relative_path, char *pwd);
char	*make_relative(char *arg, t_msh *msh);
void	handle_cd_path(t_msh *msh);
void	ft_cd(t_msh *msh, int num_cmd);

/******************************* ms_builtins ******************************/
int		ft_env(t_msh *msh);
void	ft_exit(t_msh *msh);
int		ft_pwd(t_msh *msh);
int		is_builtin(t_msh *msh);
void	cmd_not_found(t_msh *msh);
void	exc_cmd(t_msh *msh, int count_tok);
void	env_pos(t_msh *msh);
void	check_tokens(char *input, t_msh *msh);

/******************************* ms_tools *********************************/
void    ft_free_array(char **array);
/******************************* ms_varenv ********************************/
char	*varenv(char *input);
char	*serach_env(char *var, t_msh *msh);
int		varenv_man(t_msh *msh, char *builting, char *input);

/******************************* ms_free **********************************/
void	free_structs(t_env *env, t_tok *tok, t_exe *mpip);

/******************************* ms_export ********************************/
int		ft_export(t_msh *msh, char **new_var);

/******************************* ms_unset *********************************/
int		ft_unset(t_msh *msh);

/******************************* ms_signals *********************************/
void    init_signals(void);


/******************************* Error macros *****************************/
# define E_ARG			"Invalid number of parameters\n"
# define E_MALLOC		"Malloc failure\n"
# define E_ENV			"Error: No environment\n"
# define E_PATH			"No such path\n"
# define E_CMD			"Error: Command not found\n"
# define E_OPEN			"Can't open file\n"
# define E_WR			"W Permission denied\n"
# define E_RD			"R Permission denied\n"
# define E_X			"X Permission denied\n"
# define E_NOFILE		"No such file or directory\n"
# define E_DIRECTORY	"Is a directory\n"
# define E_EXECARG		"Error: minishell doesn't accept arguments\n"
# define E_MEMASF		"Error: memory assignment failed\n"
# define E_ENVGET		"Error: env var retrieval failed\n"
# define E_TOKMEM		"Error: tok mem asignation failed\n"
# define E_PIPMEM		"Error: mpip mem asignation failed\n"
# define E_CDARG		"cd: $ARG: No such file or directory\n"

/******************************** Exec macros ****************************/

# define E_PIPE			"Pipe error"
# define E_FORK			"Fork error"
# define E_DUP			"Dup2 error"
# define E_EXECVE		"Execve error"
# define E_NOCMD		"Command not found"
# define E_NOEXEC		"Permission denied"

/******************************** Exec macros ****************************/

# define PIPE_READ    0
# define PIPE_WRITE   1
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_NOCMD   127    /* Comando no encontrado */
# define EXIT_NOEXEC  126    /* Comando no ejecutable */

/******************************** Other macros ***************************/
//# define PATH_MAX		4096
# define MAX_ARGS		4096
# define MAX_ENV_VARS	4096

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
