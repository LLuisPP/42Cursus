/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:46:50 by lauriago          #+#    #+#             */
/*   Updated: 2025/03/27 10:13:59 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Calculates the size of the variable
int	ft_varlen(char *str, int start)
{
	int	len;

	if (str[start] == '?')
		return (1);
	len = 0;
	while (str[start] && (ft_isalpha(str[start]) || (str[start] == '_')))
	{
		len++;
		start++;
	}
	return (len);
}

char	*copy_var(char *str, int i, int len)
{
	char	*result;
	int		lola;

	result = malloc(sizeof(char) * len + 1);
	lola = 0;
	if (!result)
		return (NULL);
	while (len--)
	{
		result[lola] = str[i];
		i++;
		lola++;
	}
	result[lola] = 0;
	return (result);
}

// Imprime valor de variable de entorno si existe
void	print_variable(char *var, t_msh *msh)
{
	char	*env_value;

	env_value = search_value(msh, var);
	if (env_value)
		ft_putstr(env_value);
}

// Expande una variable, buscando si la variable dada como parametro existe
// si existe la expande, si no, pues no hace na'
void	process_variable(char *tmp, int *i, t_msh *msh)
{
	int		varlen;
	char	*var_copy;

	(*i)++;
	varlen = ft_varlen(tmp, *i);
	if (varlen > 0)
	{
		var_copy = copy_var(tmp, *i, varlen);
		if (ft_strcmp(var_copy, "?") == 0)
			handle_exit_status(msh);
		else
			print_variable(var_copy, msh);
		free(var_copy);
		*i += varlen - 1;
	}
	else
	{
		ft_putchar(tmp[*i - 1]);
		ft_putchar(tmp[*i]);
	}
}

void	ft_expander(char *str, t_msh *msh)
{
	int		i;
	char	*tmp;

	if (!str || !msh || !msh->env)
		return ;
	tmp = ft_strdup(str);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '$' && tmp[i + 1])
			process_variable(tmp, &i, msh);
		else
			ft_putchar(tmp[i]);
		i++;
	}
	free(tmp);
}
