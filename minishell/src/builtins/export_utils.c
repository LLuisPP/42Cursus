/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_export_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:40:25 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/05 10:40:44 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_name(char *var)
{
	int		i;
	char	*name;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	name = ft_substr(var, 0, i);
	return (name);
}

char	*get_var_value(char *var)
{
	int		i;
	char	*value;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	if (!var[i])
		return (ft_strdup(""));
	value = ft_strdup(var + i + 1);
	return (value);
}

int	update_env_variable(t_msh *msh, char *name, char *value)
{
	int	pos;

	pos = find_env_var(msh, name);
	if (pos >= 0)
	{
		free(msh->env->values[pos]);
		msh->env->values[pos] = ft_strdup(value);
		return (1);
	}
	return (add_env_var(msh, name, value));
}
