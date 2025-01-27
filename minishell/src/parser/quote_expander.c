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

/*

	expand_and_remove function must do:

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

int	ft_varlen(char *str, int start)
{
	int	len;

	len = 0;
	while (str[start] && ((str[start] >= 'A' && str[start] <= 'Z')
		|| (str[start] == '_')))
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
	while(len--)
	{
		result[lola] = str[i];
		i++;
		lola++;
	}
	result[lola] = 0;
	return (result);
}

void	look_existence(char *var, t_msh *msh)
{
	char	*value;

	if (search_env(var, msh) != NULL) // La variable existe en el environment (es real hasta la muerte, no fake)
	{
		value = malloc(sizeof(ft_strlen(search_env(var, msh))) + 1);
		if (!value)
			return ;
		value = ft_strcpy(value, search_env(var, msh));
		printf("%s", value);
	}
	else
		printf("%s", var);
	free(value);
}

void	expand_and_remove_quotes(char *str, t_msh *msh)
{
	int	i;
	int	varlen;
	char	*tmp;
	char	*var_copy;

	i = 0;
	varlen = 0;
	if (!str || !msh || !msh->env)
		return ;
	tmp = remove_quotes(str, '\"');
	while (tmp[i])
	{
		if (tmp[i] == '$' && tmp[i + 1])
		{
			i++;
			varlen = ft_varlen(tmp, i); // Funcion que calcula longitud del nombre de la variable
			if (varlen > 0)
			{
				var_copy = copy_var(tmp, i, varlen); // Funcion que copia nombre de la variable	
				look_existence(var_copy, msh);
				free(var_copy);
				i += varlen - 1;
			}
		}
		else
			printf("%c", tmp[i]);
		i++;
	}
	free(tmp);
}
