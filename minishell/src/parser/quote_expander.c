/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:46:50 by lauriago          #+#    #+#             */
/*   Updated: 2025/03/26 11:14:48 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Calculates the size of the variable
int	ft_varlen(char *str, int start)
{
	int	len;

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
void	ft_expander(char *str, t_msh *msh)
{
	int		i;
	int		varlen;
	char	*tmp;
	char	*var_copy;

	i = 0;
	varlen = 0;
	if (!str || !msh || !msh->env)
		return ;
	tmp = ft_strdup(str);
	while (tmp[i])
	{
		if (tmp[i] == '$' && tmp[i + 1])
		{
			i++;
			varlen = ft_varlen(tmp, i);
			if (varlen > 0)
			{
				var_copy = copy_var(tmp, i, varlen);
				print_variable(var_copy, msh);
				free(var_copy);
				i += varlen - 1;
			}
			else
			{
				ft_putchar(tmp[i - 1]);
				ft_putchar(tmp[i]);
			}
		}
		else
			ft_putchar(tmp[i]);
		i++;
	}
}
// --> MAS DE 25 LINEAS