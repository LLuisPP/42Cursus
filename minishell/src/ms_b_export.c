/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:15:46 by lauriago          #+#    #+#             */
/*   Updated: 2024/11/03 11:44:34 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_export_vars(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->env->names[i])
	{
		ft_fd_printf(1, "declare -x %s", msh->env->names[i]);
		if (msh->env->values[i][0])
			ft_fd_printf(1, "=\"%s\"", msh->env->values[i]);
		ft_fd_printf(1, "\n");
		i++;
	}
}

int	add_env_var(t_msh *msh, char *name, char *value)
{
	int		count;
	char	**new_names;
	char	**new_values;

	count = env_var_count(msh);
	new_names = ft_calloc(count + 2, sizeof(char *));
	new_values = ft_calloc(count + 2, sizeof(char *));
	if (!new_names || !new_values)
		return (0);
	count = -1;
	while (msh->env->names[++count])
	{
		new_names[count] = ft_strdup(msh->env->names[count]);
		new_values[count] = ft_strdup(msh->env->values[count]);
	}
	new_names[count] = ft_strdup(name);
	new_values[count] = ft_strdup(value);
	ft_free_array(msh->env->names);
	ft_free_array(msh->env->values);
	msh->env->names = new_names;
	msh->env->values = new_values;
	msh->env_var_count++;
	return (1);
}

static void	handle_export_arg(t_msh *msh, char *arg)
{
	char	*name;
	char	*value;

	if (!is_valid_identifier(arg))
	{
		ft_fd_printf(2, "export: `%s': not a valid identifier\n", arg);
		return ;
	}
	name = get_var_name(arg);
	if (!name)
		return ;
	value = get_var_value(arg);
	if (!value)
	{
		free(name);
		return ;
	}
	if (!update_env_variable(msh, name, value))
		ft_fd_printf(2, "export: memory allocation error\n");
	free(name);
	free(value);
}

int	ft_export(t_msh *msh, char **args)
{
	int	i;

	if (!args[1])
	{
		print_export_vars(msh);
		return (0);
	}
	i = 1;
	while (args[i])
	{
		handle_export_arg(msh, args[i]);
		i++;
	}
	return (0);
}
