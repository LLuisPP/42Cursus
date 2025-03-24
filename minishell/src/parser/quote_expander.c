/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:46:50 by lauriago          #+#    #+#             */
/*   Updated: 2025/01/14 17:54:22 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	expand_and_remove function must do:

	1. REMOVE QUOTES

	2.0	If the string without quotes are normal text, just print the 
	following text. 

		2.1	In the moment the string has the '$' character:

			2.1.1 	Should count how many characters has after the '$' symbol.
			2.1.2	One time the name variable copied, we search the variable
			in our environment structure.. 

				2.1.2.1 If it exist, we copy the value of the environment name, 
				and return it for print it.

				2.1.2.2	If it doesn't exist we DON'T PRINT ANYTHING,
				just ignore the random environment variable.

*/
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
		printf("%s", env_value);
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
				printf("%c%c", tmp[i - 1], tmp[i]);
		}
		else
			printf("%c", tmp[i]);
		i++;
	}
}
// --> MAS DE 25 LINEAS