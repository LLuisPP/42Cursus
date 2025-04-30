/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:41:30 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/08 10:18:53 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tmp_paths(char *tmp_oldpwd, char *tmp_pwd)
{
	free(tmp_oldpwd);
	free(tmp_pwd);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
	}
}

void	free_env(t_env *env)
{
	if (!env)
		return ;
	if (env->pwd)
		free(env->pwd);
	if (env->home)
		free(env->home);
	if (env->old_pwd)
		free(env->old_pwd);
	if (env->path)
		free(env->path);
	if (env->names)
		ft_free_array(env->names);
	if (env->values)
		ft_free_array(env->values);
	free(env);
}

void	free_tok(t_tok *tok)
{
	t_tok	*tmp;

	while (tok)
	{
		tmp = tok->next;
		if (tok->cmd)
			free(tok->cmd);
		if (tok->args)
			ft_free_array(tok->args);
		if (tok->heredoc_delim)
			free(tok->heredoc_delim);
		if (tok->typepip)
			free(tok->typepip);
		if (tok->countpip)
			free(tok->countpip);
		free(tok);
		tok = tmp;
	}
}

void	free_structs(t_env *env, t_tok *tok, t_exe *mpip)
{
	if (env)
	{
		free_env(env);
		env = NULL;
	}
	if (tok)
	{
		free_tok(tok);
		tok = NULL;
	}
	if (mpip)
	{
		free(mpip);
		mpip = NULL;
	}
}
