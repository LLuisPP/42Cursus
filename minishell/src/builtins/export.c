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
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		if (str[i] == '=')
			return (TRUE);
	}
	return (FALSE);
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
	count = -1;
	while (msh->env->names[++count])
	{
		new_names[count] = ft_strdup(msh->env->names[count]);
		new_values[count] = ft_strdup(msh->env->values[count]);
	}
	new_names[count] = ft_strdup(name);
	new_values[count] = ft_strdup(value);
	new_names[count + 1] = NULL;
	new_values[count + 1] = NULL;
	ft_free_array(msh->env->names);
	ft_free_array(msh->env->values);
	msh->env->names = new_names;
	msh->env->values = new_values;
	msh->env_var_count++;
	return (TRUE);
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

void	handle_export_arg(t_msh *msh)
{
	char	*name;
	char	*value;
	int		pos;

	pos = 0;
	if (!is_valid_identifier(msh->tkns->args[1]))
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
	else
		handle_export_arg(msh);
	return (TRUE);
}
