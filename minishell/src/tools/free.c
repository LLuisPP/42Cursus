/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:41:30 by lprieto-          #+#    #+#             */
/*   Updated: 2025/01/13 18:42:37 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* libera la memoria reservada en un array */
void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

/* libera la memoria reservada para la estructura de env */
void	free_env(t_env *env)
{
	int	i;

	free(env->pwd);
	free(env->home);
	if (env->names)
	{
		i = 0;
		while (env->names[i])
			free(env->names[i++]);
		free(env->names);
	}
	if (env->values)
	{
		i = 0;
		while (env->values[i])
			free(env->values[i++]);
		free(env->values);
	}
	free(env);
}

/* libera la memoria reservada para la estructura de token */
void	free_tok(t_tok *tok)
{
	int	i;

	if (!tok)
		return ;
	if (tok->cmd)
		free(tok->cmd);
	if (tok->args)
	{
		i = 0;
		while (tok->args[i])
		{
			free(tok->args[i]);
			i++;
		}
		free(tok->args);
	}
	if (tok->heredoc_delim)
		free(tok->heredoc_delim);
	tok->prev = NULL;
	tok->next = NULL;
	free(tok);
}

/* libera la memoria reservada para las estructuras al final del programa */
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
