/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:26:23 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/03 11:28:01 by lprieto-         ###   ########.fr       */
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

typedef enum e_token_type
{
    T_WORD,         /* comandos, argumentos, palabras */
    T_PIPE,         /* | */
    T_REDIR_IN,     /* < */
    T_REDIR_OUT,    /* > */
    T_APPEND,       /* >> */
    T_HEREDOC,      /* << */
    T_ENV,          /* $ */
}   t_ttype;

struct	s_tokenizer
{
	char	*cmd;
	char	**args;
	int		is_heredoc;
	char	*heredoc_delim;
	size_t	t_len;
	char	*input;
	size_t	position;
	t_ttype	type;
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
	int		env_var_count;
	int		shlvl;
};

/******************************* minishell.c ******************************/
void	shell_loop(t_msh *msh);

/******************************* ms_b_cd_utils ****************************/

char	*built_abspath(char *relative_path, char *pwd);
char	*make_relative(char *arg, t_msh *msh);

/******************************* ms_b_cd **********************************/

/*static void	handle_cd_error(char *path, int error_type);
static void	update_pwd_vars(t_msh *msh);
static char	*handle_cd_home(t_msh *msh, char *cmd);
static char	*handle_cd_minus(t_msh *msh);
static void	handle_cd_execute(t_msh *msh, char *path);*/
void	handle_cd_path(t_msh *msh);
void	ft_cd(t_msh *msh, int num_cmd);

/******************************* ms_b_echo ********************************/

/*static int	is_n_flag(char *str);
static int	check_n_flags(t_msh *msh, int *i);
static void	print_arg(char *arg, int has_next);*/
void	ft_echo(t_msh *msh, int num_cmd);

/******************************* ms_b_env *********************************/

int	update_env_var(t_msh *msh, char *name, char *value);
int		ft_env(t_msh *msh);

/******************************* ms_b_exit ********************************/

/*static int	is_numeric_arg(char *str);
static void	handle_numeric_arg(t_msh *msh, char *arg);
static void	handle_exit_error(t_msh *msh, char *arg);*/
void	ft_exit(t_msh *msh);

/******************************* ms_b_export ******************************/
int	find_env_var(t_msh *msh, char *var_name);
/*static int	is_valid_identifier(char *str);
static void	print_export_vars(t_msh *msh);
static char	*get_var_name(char *var);
static char	*get_var_value(char *var);*/
int	add_env_var(t_msh *msh, char *name, char *value);
/*static int	update_env_variable(t_msh *msh, char *name, char *value);
static void	handle_export_arg(t_msh *msh, char *arg);*/
int		ft_export(t_msh *msh, char **new_var);

/******************************* ms_b_pwd *********************************/

int		ft_pwd(t_msh *msh);

/******************************** ms_b_unset ******************************/

/*static int	is_valid_identifier(char *str);
static void	remove_var_from_env(t_msh *msh, int pos);
static int	find_var_in_env(t_msh *msh, char *var_name);*/
int		ft_unset(t_msh *msh, char **new_var);

/******************************* ms_builtins ******************************/

void	cmd_not_found(t_msh *msh);
void	check_tokens(char *input, t_msh *msh);
void	exc_cmd(t_msh *msh, int count_tok);
int		is_builtin(t_msh *msh);

/******************************* ms_env ***********************************/

int		env_var_count(t_msh *msh);
int	check_envs(void);
void update_shlvl(t_msh *msh);
int		env_init_values(t_env *env, t_msh *msh);

/******************************* ms_executor ******************************/

/*static int	is_command_executable(char *fullpath)
static void	child_process(t_msh *msh, char *fullpath)
static void	parent_process(pid_t pid, char *fullpath)*/
int	execute_command(t_msh *msh, char *fullpath);
int		find_cmd(char *tkn, t_msh *msh);
/*static char	**get_path_dirs(char **envs);
static char	*check_absolute_path(char *cmd);
static char	*try_path(char *dir, char *cmd);*/
char	*make_path(char *tkn, t_msh *msh);

/******************************* ms_free **********************************/

void	ft_free_array(char **array);
void	free_tok(t_tok *tok);
void	free_env(t_env *env);
void	free_structs(t_env *env, t_tok *tok, t_exe *mpip);

/******************************* ms_init **********************************/

int		env_alloc_struct(t_env **env, t_msh *msh);
int		tok_alloc_struct(t_tok **tok);
int		mpip_alloc_struct(t_exe **mpip);
int		init_structs(t_env **env, t_msh *msh, t_exe **mpip, t_tok **tok);

/******************************* ms_lexer *********************************/

int		quote_lexer(t_msh *msh);
int		lexer(char **tokens, t_msh *msh);

/******************************* ms_parser ********************************/

char	*parse_path(char **env);
char	*parse_pwd(char **env);
// static char	**extract_args(t_tok *tokens);
int		parse_input(char *input, t_msh *mshll);

/******************************* ms_rline *********************************/

char	*cmd_gen(const char *text, int state);
char	**cmd_comp(const char *text, int start, int end);
char	*cmd_match(const char *text, int state);

/******************************* ms_signals ********************************/

/*static	void	handle_sigint(int sig);
static void	handle_sigquit(int sig); */
void	init_signals(void);

/******************************* ms_tokenizer *****************************/

char	*ft_strtok(char *str, const char *separator);
int		tokenize_input(char *input, t_msh *msh);

/******************************* ms_tokenizer2 ****************************/

/*static int	is_operator(char c);
static int	is_whitespace(char c);
static t_ttype	get_operator_type(char curr, char next);
static void	init_token(t_tok *token);
static void	handle_operator(char *input, size_t *pos, t_tok *token);
static void	handle_word(char *input, size_t *pos, t_tok *token);
static size_t	count_tokens(char *input); */

int	tokenize_input(char *input, t_msh *msh);


/******************************* ms_env_utils *****************************/

/******************************* ms_tools *********************************/

/******************************* ms_varenv ********************************/
char	*varenv(char *input);
char	*serach_env(char *var, t_msh *msh);
int		varenv_man(t_msh *msh, char *builting, char *input);




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
# define PATH_MAX		4096
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
