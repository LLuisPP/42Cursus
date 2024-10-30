/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:15:46 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/30 10:12:29 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* cuenta las variables del env*/
int	count_env_vars(t_msh *msh)
{
	int	l;

	l = 0;
	while (msh->env->names[l])
		l++;
	return (l);
}

static void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* busca una variable especifica en el env y nos retorna el valor de su indice*/
int	find_env_var(t_msh *msh, char *var_name)
{
	int	i;

	i = 0;
	while (msh->env->names[i])
	{
		if (ft_strcmp(msh->env->names[i], var_name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

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

static char	*get_var_name(char *var)
{
	int		i;
	char	*name;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	name = ft_substr(var, 0, i);
	return (name);
}

static char	*get_var_value(char *var)
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

static int	add_env_var(t_msh *msh, char *name, char *value)
{
	int		count;
	char	**new_names;
	char	**new_values;

	count = count_env_vars(msh);
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
	free_array(msh->env->names);
	free_array(msh->env->values);
	msh->env->names = new_names;
	msh->env->values = new_values;
	return (1);
}

static int	update_env_var(t_msh *msh, char *name, char *value)
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
	if (!update_env_var(msh, name, value))
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
