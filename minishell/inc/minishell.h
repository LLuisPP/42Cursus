/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:26:23 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/15 23:54:21 by lprieto-         ###   ########.fr       */
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

typedef enum e_quote_type		t_quote_type;
typedef enum e_types			t_tokty;
typedef enum e_redir			t_redir;

typedef struct s_environment	t_env;
typedef struct s_executor		t_exe;
typedef struct s_quote			t_quote;
typedef struct s_tokenizer		t_tok;
typedef struct s_minishell		t_msh;

/* ************************************************************************** */
/* ******************************* [ STRCTURES ] **************************** */
/* ************************************************************************** */

enum e_quote_type
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
};

enum e_types
{
	T_WORD,
	T_OPERATOR,
	T_WHITESPACE,
	T_QUOTE
};

enum e_redir
{
	NO_REDIR = 0,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HERE,
	PIPE,
	REDIR_ERROR
};

struct	s_environment
{
	char	**names;
	char	**values;
	char	*pwd;
	char	*old_pwd;
	char	*home;
	char	*path;
	int		exit_status;
};

struct s_executor
{
	int		fd_1[2];
	int		status_1;
	int		status_2;
	int		fd_in;
	int		fd_out;
	int		backup_in;		/* Backup del fd de entrada original */
	int		backup_out;		/* Backup del fd de salida original */
	char	*infile;		/* Nombre del archivo de entrada */
	char	*outfile;		/* Nombre del archivo de salida */
	int		append;			/* Flag para modo append (>>) */
	int		heredoc;		/* Flag para heredoc (<<) */
	char	*delimiter;		/* Delimitador para heredoc */
};

typedef struct s_command
{
	char	**args;
	int		arg_count;
}	t_cmd;

struct s_quote
{
	int				single_count;
	int				double_count;
	t_quote_type	active_quote;
	int				to_expand;
};

struct	s_tokenizer
{
	char				*cmd;
	char				**args;
	int					token_count;
	int					len;
	t_tokty				type;
	int					is_heredoc;
	char				*heredoc_delim;
	// ------------------------------------
	int					count_redir;
	int					redir_pos;
	t_redir				redir_type;
	int					*countpip;
	t_redir				*typepip;
	t_redir				first_redir_type;
	// ------------------------------------
	struct s_tokenizer	*prev;
	struct s_tokenizer	*next;
};

struct	s_minishell
{
	t_tok	*tkns;
	t_env	*env;
	t_exe	*mpip;
	t_cmd	*cmds;
	t_quote	*quote;
	int		cmd_count;
	int		end_sig;
	int		last_exit_code;
	char	**envs;
	int		env_var_count;
	int		shlvl;
	char	*heredoc_file;
	int		saved_stdout;
};

/* ************************************************************************** */
/* ****************************** [ BUILTINS ] ****************************** */
/* ************************************************************************** */

/* ----------------------------------------------------------------cd_utils.c */
char	*built_abspath(char *relative_path, char *pwd);
/*static char	*go_back_dir(char *pwd)*/
/*static char	*handle_multiple_back(char *path, t_msh *msh)*/
char	*make_relative(char *arg, t_msh *msh);
void	expand_cd_home(t_msh *msh);

/* ----------------------------------------------------------------------cd.c */
/*static void	handle_cd_minus(t_msh *msh)*/
/*static void	cd_home(t_msh *msh)*/
void	update_pwd_opwd(t_msh *msh, char *new_path);
void	handle_cd_path(t_msh *msh);
void	ft_cd(t_msh *msh, int num_cmd);

/* --------------------------------------------------------------echo_utils.c */
int		echo_has_2_expand(char *str);
void	handle_echo_quotes(t_msh *msh, char k, int i);
void	print_echo_argument(t_msh *msh, char *arg, int i, int is_last_arg);
void	change_to_oldpwd(t_msh *msh, char *tmp_oldpwd, char *tmp_pwd);

/* --------------------------------------------------------------------echo.c */
/*static int	is_n_flag(char *str)*/
/*static int	check_n_flags(t_msh *msh, int *i)*/
void	ft_echo(t_msh *msh, int num_cmd);

/* ---------------------------------------------------------------------env.c */
int		ft_env(t_msh *msh);

/* --------------------------------------------------------------------exit.c */
/*static int	is_numeric_arg(char *str)*/
/*static void	handle_numeric_arg(t_msh *msh, char *arg)*/
void	ft_exit(t_msh *msh);

/* ------------------------------------------------------------------export.c */
/*static int	is_valid_identifier(t_msh *msh, char *str)*/
int		add_env_var(t_msh *msh, char *name, char *value);
void	print_export_vars(t_msh *msh);
void	handle_export_arg(t_msh *msh);
int		ft_export(t_msh *msh, int tok_num);

/* ------------------------------------------------------------export_utils.c */
int		env_var_exist(t_msh *msh, char *name);
int		env_var_pos(t_msh *msh); // -------> REPETIDO!!!
char	*get_var_name(char *var);
char	*get_var_value(char *var);
int		update_env_var_value(t_msh *msh, int pos, char *value);

/* ---------------------------------------------------------------------pwd.c */
int		ft_pwd(t_msh *msh);
// int		builtin_redir_check(t_msh *msh);

/* -------------------------------------------------------------------unset.c */
/*static int	is_valid_identifier(char *str)*/
/*static void	remove_var_from_env(t_msh *msh, int pos)*/
/*static int	find_var_in_env(t_msh *msh, char *var_name)*/
int		ft_unset(t_msh *msh, int tok_num);

/* ************************************************************************** */
/* ******************************** [ ENV ] ********************************* */
/* ************************************************************************** */

/* ---------------------------------------------------------------------env.c */
int		env_var_count(t_msh *msh);
int		find_env_pos(t_msh *msh, char *var_name);
int		env_init_values(t_env *env, t_msh *msh);
int		env_init(t_env *env, t_msh *msh);

/* ------------------------------------------------------------------varenv.c */
char	*search_value(t_msh *msh, char *var);
char	*manage_cd_var(t_msh *msh, char *arg);
int		cd_varman(t_msh *msh, char *var_name);
char	*update_env(t_msh *msh, char *name, char *value); // ---> REPETIDO!!!

/* ************************************************************************** */
/* ******************************** [ EXECUTOR ] **************************** */
/* ************************************************************************** */

/* ----------------------------------------------------------------builtins.c */
void	cmd_not_found(t_msh *msh);
void	check_tokens(char *input, t_msh *msh);
void	cleanup_commands(t_msh *msh);
int		is_builtin(char *token);
void	exc_cmd(t_msh *msh, int count_tok);

/* --------------------------------------------------------------exec_redir.c */
// static char	**redir_args(char **args, int redir_pos)
// static void	child_process_redir(t_msh *msh, char *fullpath, t_redir type)
// static void	parent_process_redir(t_msh *msh, pid_t pid, char *fullpath)
void	exec_redir(t_msh *msh, char *tkn, t_redir type);

/* ----------------------------------------------------------executor_utils.c */
/*static char	**get_path_dirs(char **envs)*/
/*static char	*check_absolute_path(char *cmd)*/
/*static char	*try_path(char *dir, char *cmd)*/
char	*make_path(char *tkn, t_msh *msh);

/* ----------------------------------------------------------------executor.c */
int		is_command_executable(char *fullpath);
/*static void	child_process(t_msh *msh, char *fullpath)*/
/*static void	parent_process(t_msh *msh, pid_t pid, char *fullpath)*/
int		execute_command(t_msh *msh, char *fullpath);
int		find_cmd(char *tkn, t_msh *msh);

/* -------------------------------------------------------------------pipes.c */
void	handle_pipes(t_msh *msh);
// static void	child_process(t_msh *msh, int i, int prev_fd, int pipe_fd[2])
int		execute_pipeline(t_msh *msh);
void	save_pipe_and_close(int *prev_fd, int *pipe_fd);

/* ************************************************************************** */
/* ****************************** [ HEREDOC ] ******************************* */
/* ************************************************************************** */

/* -----------------------------------------------------------------heredoc.c */
int		handle_heredoc(t_msh *msh, char *delimiter);
void	cleanup_heredoc(t_msh *msh);
int		redirect_input_output(t_msh *msh);

/* ************************************************************************** */
/* ******************************* [ MAIN ] ********************************* */
/* ************************************************************************** */

/* --------------------------------------------------------------------init.c */
int		env_alloc_struct(t_env **env, t_msh *msh);
int		tok_alloc_struct(t_tok **tok);
int		mpip_alloc_struct(t_exe **mpip);
int		init_structs(t_env **env, t_msh *msh, t_exe **mpip, t_tok **tok);

/* --------------------------------------------------------------------main.c */
void	shell_loop(t_msh *msh);

/* -----------------------------------------------------------------signals.c */
void	handle_sigint(int sig);
// void	handle_sigquit(int sig);
void	init_signals(void);
void	restore_signals(void);

/* ----------------------------------------------------------------signals2.c */
void	handle_sigint_heredoc(int sig);
void	handle_heredoc_signals(void);

/* ************************************************************************** */
/* ******************************* [ PARSER ] ******************************* */
/* ************************************************************************** */

/* -------------------------------------------------------------lexer_redir.c */
int		*find_piperedir(t_msh *msh);
void	type_def(t_msh *msh);
int		type_verif(t_msh *msh);
int		is_redir(char *token);

/* ------------------------------------------------------------lexer_syntax.c */
int		basic_syntax_checker(char *input, t_msh *msh);
int		check_unclosed_quotes(char *input);
int		check_redir_edges(t_msh *msh);
int		check_double_pipe(t_msh *msh);
int		check_pipe_edges(t_msh *msh);

/* -------------------------------------------------------------------lexer.c */
/*static int	has_pipe(char *token)*/
/*static int	validate_pipe_syntax(t_tok *tok)*/
/*static void	init_command_struct(t_cmd *cmd)*/
/*static int	split_commands(t_tok *tok, t_cmd *cmds)*/
int		parse_and_validate_commands(t_msh *msh, t_tok *tok, t_cmd **commands);

/* ------------------------------------------------------------------parser.c */
char	*parse_path(char **env);
char	*parse_pwd(char **env);

/* ----------------------------------------------------------quote_expander.c */
int		ft_varlen(char *str, int start);
char	*copy_var(char *str, int i, int len);
void	print_variable(char *var, t_msh *msh);
void	ft_expander(char *str, t_msh *msh);

/* -------------------------------------------------------quote_lexer_tools.c */
char	*remove_quotes(char *str, char quote_type);
// char	*search_value(t_msh *msh, char *name);

/* -------------------------------------------------------------quote_lexer.c */
t_quote	*init_quotes(void);
int		analyze_quotes(t_msh *msh, char *arg, char quote);
void	handle_single_quotes(t_msh *msh, int i);
void	handle_double_quotes(t_msh *msh, int i);

/* -------------------------------------------------------------token_tools.c */
int		is_quote(char c);
int		is_pipe(char c);
int		is_whitespace(char c);
int		is_operator(char c);

/* ---------------------------------------------------------------tokenizer.c */
int		size_token(char *input);
char	*create_token(char *input, int len, t_tok *tok);
void	ft_token(char *input, t_tok *tok);

/* ************************************************************************** */
/* ******************************* [ REDIR ] ******************************** */
/* ************************************************************************** */

/* -----------------------------------------------------------builtin_redir.c */
// static int	manage_builting_redir_out(t_msh *msh, t_redir type)
int		manage_builting_redir(t_msh *msh, t_redir type);

/* -------------------------------------------------------------input_redir.c */
// static void	error_fd(char *filename)
int		handle_input_file(t_msh *msh, char *filename, t_redir type);
void	handle_redir_in(t_msh *msh, t_redir type);

/* ----------------------------------------------------------multiple_redir.c */
void	open_files(t_msh *msh, t_redir type, char *file);
int		process_redirection(t_msh *msh, t_redir type, int current_pos);
void	handle_last_redirection(t_msh *msh, t_redir type);

/* ------------------------------------------------------------output_redir.c */
// static void	error_fd(char *filename)
int		handle_output_file(t_msh *msh, char *filename, t_redir type);
void	restore_redirections(t_msh *msh);

/* -------------------------------------------------------------redir_tools.c */
int		count_redir(t_msh *msh);
int		handle_one_redir(t_msh *msh, int redir_pos, t_redir	redir_type);
int		find_next_redir(t_msh *msh, int start_pos);

/* ------------------------------------------------------------redirections.c */
// static void	print_error_msg(char c)
int		has_redirection(t_msh *msh, t_tok *tok);
t_redir	check_syntax_redir(t_msh *msh, char **tkn, int pos);
// static void	init_redir(t_msh *msh)
// static void	print_redir_info(t_redir redir_type, int redir_pos)
void	handle_redir_out(t_msh *msh, t_redir type);
int		redir_checker(t_msh *msh);

/* ------------------------------------------------------------type_handler.c */
int		handle_multip_redir(t_msh *msh, int count);
int		just_redirs(t_msh *msh, int count);
int		just_pipes(t_msh *msh, int count);
int		handle_just_redirs(t_msh *msh, int count);

/* ************************************************************************** */
/* ******************************* [ TOOLS ] ******************************** */
/* ************************************************************************** */

/* --------------------------------------------------------------err_hanlde.c */
void	handle_exit_error(t_msh *msh, char *arg);
void	handle_cd_error(t_msh *msh, int error_type);
int		ft_err(t_msh *msh, int err_code);
void	handle_exit_status(t_msh *msh);
void	print_error_msg(t_msh *msh, char c);

/* --------------------------------------------------------------------free.c */
void	free_tmp_paths(char *tmp_oldpwd, char *tmp_pwd);
void	ft_free_array(char **array);
void	free_env(t_env *env);
void	free_tok(t_tok *tok);
void	free_structs(t_env *env, t_tok *tok, t_exe *mpip);

/* ----------------------------- Error macros ------------------------------- */

# define E_ARG		"Invalid number of parameters\n"
# define E_MALLOC	"Malloc failure\n"
# define E_ENV		"Error: No environment\n"
# define E_PATH		"No such path\n"
# define E_CMD		"Error: Command not found\n"
# define E_OPEN		"Can't open file\n"
# define E_WR		"W Permission denied\n"
# define E_RD		"R Permission denied\n"
# define E_X		"X Permission denied\n"
# define E_NOFILE	"No such file or directory\n"
# define E_DIRCTRY	"Is a directory\n"
# define E_EXECARG	"Error: minishell doesn't accept arguments\n"
# define E_MEMASF	"Error: memory assignment failed\n"
# define E_ENVGET	"Error: env var retrieval failed\n"
# define E_TOKMEM	"Error: tok mem asignation failed\n"
# define E_PIPMEM	"Error: mpip mem asignation failed\n"
# define E_CDARG	"cd: $ARG: No such file or directory\n"
# define E_SYNTX	"Error: syntax not accepted"
# define E_PIP_SNTX	"bash: syntax error near unexpected token `|'\n"
# define E_NW		"bash: syntax error near unexpected token `newline'\n"
# define E_PIPE		"Pipe error"
# define E_FORK		"Fork error"
# define E_DUP		"Dup2 error"
# define E_EXECVE	"Execve error"
# define E_NOCMD	"Command not found"
# define E_NOEXEC	"Permission denied"

/******************************** Exec macros ****************************/

# define PIPE_READ		0
# define PIPE_WRITE		1
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
# define EXIT_MISUSE	2
# define EXIT_NOEXEC	126
# define EXIT_NOFOUND	127
# define EXIT_SIGBASE	128

/******************************** General macros **************************/

# define TRUE			1
# define FALSE			0

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
