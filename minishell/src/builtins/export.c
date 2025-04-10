/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:15:46 by lauriago          #+#    #+#             */
/*   Updated: 2025/04/09 21:31:43 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(t_msh *msh, char *str)
{
	int	i;

	i = 0;
	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
	{
		ft_fd_printf(2, "export: `%s': not a valid identifier\n", str);
		msh->last_exit_code = 1;
		return (FALSE);
	}
	while (str[i])
	{
		if (str[i] == '$' || str[i] == '#')
		{
			print_export_vars(msh);
			return (FALSE);
		}
		if (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		if (str[i] == '=')
			return (TRUE);
	}
	return (FALSE);
}

static int	copy_env_vars(t_msh *msh, char **new_names, char **new_values)
{
	int	i;

	i = -1;
	while (msh->env->names[++i])
	{
		new_names[i] = ft_strdup(msh->env->names[i]);
		new_values[i] = ft_strdup(msh->env->values[i]);
	}
	return (i);
}

int	add_env_var(t_msh *msh, char *name, char *value)
{
	int		count;
	char	**new_names;
	char	**new_values;

	count = env_var_count(msh) + 1;
	new_names = malloc(sizeof(char *) * (count * 2));
	new_values = malloc(sizeof(char *) * (count * 2));
	if (!new_names || !new_values)
		return (FALSE);
	count = copy_env_vars(msh, new_names, new_values);
	new_names[count] = ft_strdup(name);
	if (value)
		new_values[count] = ft_strdup(value);
	else
		new_values[count] = ft_strdup("");
	new_names[count + 1] = NULL;
	new_values[count + 1] = NULL;
	ft_free_array(msh->env->names);
	ft_free_array(msh->env->values);
	msh->env->names = new_names;
	msh->env->values = new_values;
	msh->env_var_count++;
	return (TRUE);
}

void	handle_export_arg(t_msh *msh)
{
	char	*name;
	char	*value;
	int		pos;

	pos = 0;
	if (!is_valid_identifier(msh, msh->tkns->args[1]))
		return ;
	name = get_var_name(msh->tkns->args[1]);
	value = get_var_value(msh->tkns->args[1]);
	if (!name)
		return ;
	if (env_var_exist(msh, name))
	{
		pos = env_var_pos(msh);
		update_env_var_value(msh, pos, value);
		free(name);
		free(value);
		return ;
	}
	if (!add_env_var(msh, name, value))
		ft_fd_printf(2, "export: memory allocation error\n");
	free(name);
	free(value);
}

int	ft_export(t_msh *msh, int tok_num)
{
	if (tok_num == 1)
	{
		print_export_vars(msh);
		return (TRUE);
	}
	if (tok_num != 2)
		return (FALSE);
	handle_export_arg(msh);
	if (msh->last_exit_code != 0)
		return (FALSE);
	return (TRUE);
}
