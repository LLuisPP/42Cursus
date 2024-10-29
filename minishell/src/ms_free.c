/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:41:30 by lprieto-          #+#    #+#             */
/*   Updated: 2024/10/29 22:44:02 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* libera la memoria reservada para la estructura de env */
void	free_env(t_env *env)
{
	int	i;

	free(env->pwd);
	free(env->home);
	if (env->names)
	{
		i = 0;
		while (env->names[i] != NULL)
			free(env->names[i++]);
		free(env->names);
	}
	if (env->values)
	{
		i = 0;
		while (env->values[i] != NULL)
			free(env->values[i++]);
		free(env->values);
	}
	free(env);
}

/* libera la memoria reservada para la estructura de token */
void	free_tok(t_tok *tok)
{
	int	i;

	if (tok->cmd)
		free(tok->cmd);
	if (tok->args)
	{
		i = 0;
		while (tok->args[i] != NULL)
			free(tok->args[i++]);
		free(tok->args);
	}
	free(tok);
}

/* libera la memoria reservada para las estructuras al final del programa */
void	free_structs(t_env *env, t_tok *tok, t_exe *mpip)
{
	if (env)
		free_env(env);
	if (tok)
		free_tok(tok);
	if (mpip)
		free(mpip);
}
