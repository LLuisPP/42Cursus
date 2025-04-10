/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:27 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/07 23:08:15 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_alloc_struct(t_env **env, t_msh *msh)
{
	size_t	env_count;

	*env = malloc(sizeof(t_env));
	if (!*env)
		return (FALSE);
	ft_memset(*env, 0, sizeof(t_env));
	(*env)->pwd = NULL;
	env_count = env_var_count(msh);
	(*env)->names = malloc(sizeof(char *) * (env_count + 1));
	if (!(*env)->names)
	{
		free_env(*env);
		return (FALSE);
	}
	(*env)->values = malloc(sizeof(char *) * (env_count + 1));
	if (!(*env)->values)
	{
		free((*env)->names);
		free_env(*env);
		return (FALSE);
	}
	(*env)->names[env_count] = NULL;
	(*env)->values[env_count] = NULL;
	return (TRUE);
}

int	tok_alloc_struct(t_tok **tok)
{
	*tok = malloc(sizeof(t_tok));
	if (!*tok)
		return (FALSE);
	ft_memset(*tok, 0, sizeof(t_tok));
	(*tok)->cmd = NULL;
	(*tok)->args = NULL;
	(*tok)->token_count = 0;
	(*tok)->len = 0;
	(*tok)->type = T_WORD;
	(*tok)->is_heredoc = 0;
	(*tok)->heredoc_delim = NULL;
	(*tok)->redir_pos = -1;
	(*tok)->redir_type = NO_REDIR;
	(*tok)->prev = NULL;
	(*tok)->next = NULL;
	return (TRUE);
}

int	mpip_alloc_struct(t_exe **mpip)
{
	*mpip = malloc(sizeof(t_exe));
	if (!*mpip)
		return (FALSE);
	ft_memset(*mpip, 0, sizeof(t_exe));
	(*mpip)->backup_in = -1;
	(*mpip)->backup_out = -1;
	return (TRUE);
}

int	init_structs(t_env **env, t_msh *msh, t_exe **mpip, t_tok **tok)
{
	if (!env_alloc_struct(env, msh))
		return (ft_fd_printf(2, "%s", E_ENVGET) * -1);
	msh->env = *env;
	if (!tok_alloc_struct(tok))
	{
		free_env(*env);
		return (ft_fd_printf(2, "%s", E_TOKMEM) * -1);
	}
	msh->tkns = *tok;
	if (!mpip_alloc_struct(mpip))
	{
		free_env(*env);
		free(*tok);
		return (ft_fd_printf(2, "%s", E_PIPMEM) * -1);
	}
	msh->mpip = *mpip;
	return (TRUE);
}
