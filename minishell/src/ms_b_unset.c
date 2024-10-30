/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:14:37 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/29 22:34:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_find_env_var(char **env_names, char *var_name)
{
	int	i;
	int	len;

	i = 0;
	if (!env_names || !var_name)
		return (-1);
	len = ft_strlen(var_name);
	while (env_names[i])
	{
		if (ft_strncmp(env_names[i], var_name, len) == 0
			&& (env_names[i][len] == '=' || env_names[i][len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

static int	get_env_len(char **env)
{
	int	len;

	len = 0;
	if (!env)
		return (0);
	while (env[len])
		len++;
	return (len);
}

static void	free_env_array(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

static char	**remove_var(char **src, int skip_idx)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_env = malloc(sizeof(char *) * get_env_len(src));
	if (!new_env)
		return (NULL);
	while (src[i])
	{
		if (i != skip_idx)
		{
			new_env[j] = ft_strdup(src[i]);
			if (!new_env[j])
			{
				free_env_array(new_env);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}

int	ft_unset(t_msh *msh)
{
	char	**new_names;
	char	**new_values;
	int		var_pos;

	if (!msh->env->names || !msh->tkns->args[1])
		return (1);
	var_pos = ft_find_env_var(msh->env->names, msh->tkns->args[1]);
	if (var_pos == -1)
		return (1);
	new_names = remove_var(msh->env->names, var_pos);
	new_values = remove_var(msh->env->values, var_pos);
	if (!new_names || !new_values)
	{
		free_env_array(new_names);
		free_env_array(new_values);
		return (-1);
	}
	free_env_array(msh->env->names);
	free_env_array(msh->env->values);
	msh->env->names = new_names;
	msh->env->values = new_values;
	msh->env->env_count--;
	return (1);
}
