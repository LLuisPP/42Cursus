/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_lexer_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:12:17 by lauriago          #+#    #+#             */
/*   Updated: 2025/01/13 18:28:59 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_quotes(char *str, char quote_type)
{
	char *result;
	int i;
	int j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (str[i] != quote_type)
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

char	*search_value(t_msh *msh, char *name)
{
	char	*value;
	int		i;
	
	i = 0;
	value = NULL;
	if (!msh || !msh->env || !msh->env->names || !msh->env->values || !name)
		return (NULL);
	while (msh->env->names[i] && msh->env->values[i])
	{
		if (ft_strcmp(msh->env->names[i], name) == 0)
		{
			value = ft_strdup(msh->env->values[i]);
			return (value);
		}
		i++;
	}
	return (NULL);
}

/*void	expand_and_remove_quotes(char *str, t_msh *msh)
{
	char	*env_var;
	str = remove_quotes(str, '\"');
	env_var = extract_var(str, msh);
	if (!str || !msh || !msh->env)
		printf("NULL\n");
	char *value = search_value(msh, env_var);
	ft_putstr_fd(value, 1);
}*/

    // Aquí implementarías la expansión de variables
    // Por ejemplo: $USER -> "username"
    // Esta función debe manejar la expansión de variables
    // cuando se encuentran dentro de comillas dobles
    // return ; // Placeholder
