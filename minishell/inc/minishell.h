/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:26:23 by lprieto-          #+#    #+#             */
/*   Updated: 2024/12/12 17:02:40 by leegon           ###   ########.fr       */
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
typedef struct s_quote			t_quote;

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
	int		env_len;
	int		exit_status;
};

typedef enum e_quote_type {
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
} t_quote_type;

struct s_quote {
	int		single_count;
	int		double_count;
	t_quote_type	active_quote;
	int		is_closed;
};

typedef enum {
	T_WORD,
	T_OPERATOR,
	T_WHITESPACE,
	T_QUOTE
}	token_type_t;

struct	s_tokenizer
{
	char	*cmd;
	char	**args;
	int		token_count;
	int		len;
	int		is_heredoc;
	char	*heredoc_delim;
	token_type_t	type;
	struct s_tokenizer *prev;
	struct s_tokenizer *next;
};

struct s_executor
{
	int		fd_1[2];
	int		status_1;
	int		status_2;
	int		fd_in;
	int		fd_out;
};

typedef struct s_command
{
	char	**args;
	int		arg_count;
}	t_cmd;

struct	s_minishell
{
	t_tok	*tkns;
	t_env	*env;
	t_exe	*mpip;
	t_cmd	*cmds;
	t_quote	*quote;
	int			cmd_count;
	int		end_sig;
	int		last_exit_code;
	char	**envs;
	int		env_var_count;
	int		shlvl;
};

/*	QUOTE_LEXER_MS	*/
t_quote	*init_quotes(void);
int		analyze_quotes(t_msh *msh, char *arg);
char	*remove_quotes(char *str, char quote_type);
void	expand_and_remove_quotes(char *str, t_msh *msh);

/*	BUILTINS	*/

/***************************** cd.c ********************************/
void	handle_cd_path(t_msh *msh);
void	ft_cd(t_msh *msh, int num_cmd);
/******************************** cd_utils.c ********************************/
char	*built_abspath(char *relative_path, char *pwd);
char	*make_relative(char *arg, t_msh *msh);
/******************************* echo.c *************************************/
void	ft_echo(t_msh *msh, int num_cmd);
/******************************* env.c **************************************/
int		update_env_var(t_msh *msh, char *name, char *value);
int		ft_env(t_msh *msh);
char	*update_env(t_msh *msh, char *name, char *value);
// void	debug_env(t_msh *msh); borrar?
/******************************* exit.c ***********************************/
void	ft_exit(t_msh *msh);
/******************************* export.c **********************************/
int		add_env_var(t_msh *msh, char *name, char *value);
int		ft_export(t_msh *msh, int tok_num);
/**************************** export_utils.c *******************************/
char	*get_var_name(char *var);
char	*get_var_value(char *var);
int		update_env_variable(t_msh *msh, char *name, char *value);
/******************************* pwd.c ************************************/
int		ft_pwd(t_msh *msh);
/******************************** unset.c **********************************/
int		ft_unset(t_msh *msh, char **new_var);

/*		ENV		*/

/******************************* ms_env.c ***********************************/
int		env_var_count(t_msh *msh);
int		find_env_var(t_msh *msh, char *var_name);
int		check_envs(void);
void	update_shlvl(t_msh *msh);
int		env_init_values(t_env *env, t_msh *msh);
/******************************* ms_env_tools.c *****************************/
char	*update_env(t_msh *msh, char *name, char *value);
/****************************** ms_varenv.c *********************************/
char	*search_env(char *var, t_msh *msh);
int		varenv_man(t_msh *msh, char *builting, char *var_name);

/*		E		*/
/******************************* minishell.c ******************************/
void	shell_loop(t_msh *msh);



/***************************** quote_lexer_ms *****************************/
void	handle_quotes(t_msh *msh, t_quote *q, int i);
int		analyze_quotes(t_msh *msh, char *arg);
t_quote	*init_quotes(void);


/******************************* ms_builtins ******************************/
void	cmd_not_found(t_msh *msh);
void	check_tokens(char *input, t_msh *msh);
void	cleanup_commands(t_msh *msh);
void	exc_cmd(t_msh *msh, int count_tok);
int		is_builtin(char *token);


/******************************* ms_executor ******************************/
int		is_command_executable(char *fullpath);
int		execute_command(t_msh *msh, char *fullpath);
int		find_cmd(char *tkn, t_msh *msh);
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
// int		quote_lexer(char *arg);
int		lexer(char **tokens, t_msh *msh);
int		parse_and_validate_commands(t_tok *tok, t_cmd **commands);

/******************************* ms_parser ********************************/
char	*parse_path(char **env);
char	*parse_pwd(char **env);
int		parse_input(char *input, t_msh *mshll);

/******************************* ms_rline *********************************/
char	*cmd_gen(const char *text, int state);
char	**cmd_comp(const char *text, int start, int end);
char	*cmd_match(const char *text, int state);

/******************************* ms_signals ********************************/
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	init_signals(void);

/******************************* ms_tokenizer *****************************/
int		size_token(char *input, t_tok *tok);
char	*create_token(char *input, int len, t_tok *tok);
void	ft_token(char *input, t_tok *tok);

/***************************** token_tools.c *******************************/
int	is_quote(char c);
int	is_whitespace(char c);
int	is_operator(char c);
token_type_t	type_token_def(t_tok *tok, char c);

/******************************* ms_tools *********************************/

/******************************* ms_err_handle ****************************/
void	handle_cd_error(char *path, int error_type);
int	ft_err(t_msh *msh, int err_code);

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
# define E_SYNTX		"Error: syntax not accepted\n"

/******************************** Exec macros ****************************/

# define E_PIPE			"Pipe error"
# define E_FORK			"Fork error"
# define E_DUP			"Dup2 error"
# define E_EXECVE		"Execve error"
# define E_NOCMD		"Command not found"
# define E_NOEXEC		"Permission denied"
# define PIPE_READ		0
# define PIPE_WRITE		1
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
# define EXIT_MISUSE	2
# define EXIT_NOEXEC	126
# define EXIT_NOFOUND	127
# define EXIT_SIGBASE	128

/******************************** General macros **************************/

# define TRUE			0
# define FALSE			1

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
# define F		"\033[0m"

#endif
