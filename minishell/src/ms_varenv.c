/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_varenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:12:48 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/06 19:23:18 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	
	Verificación de si el input menciona una variable de entorno;
	En caso de que así sea, se busca la variable y se intenta ejecutar;

*/

char	*varenv(char *input)
{
	int		i;
	int		j;
	char	*varenv;

	i = 0;
	j = 0;
	varenv = malloc(sizeof(char) * ft_strlen(input) + 1);
	while (input[i])
	{
		if (input[i] == '$')
			break ;
		i++;
	}
	i += 1;
	if (input[i] != '\0')
	{
		while (input[i])
		{
			varenv[j] = input[i];
			i++;
			j++;
		}
		return (varenv);
	}
	return (NULL);
}

char	*serach_env(char *var, t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->env->names[i] && msh->env->values[i])
	{
		if (ft_strcmp(msh->env->names[i], var) == 0)
		{
			return (msh->env->values[i]);
		}
		i++;
	}
	return (NULL);
}

int	varenv_man(t_msh *msh, char *builting, char *input)
{
	if (ft_strcmp(builting, "cd") == 0)
	{
		if (varenv(input) != NULL)
		{
			if (chdir(serach_env(varenv(input), msh)) != -1)
			{
				msh->env->old_pwd = msh->env->pwd;
				msh->env->pwd = getcwd(NULL, 0);
				env_pos(msh);
				return (1);
			}
		}
	}
	if (ft_strcmp(builting, "echo") == 0)
	{
		if (varenv(input) != NULL)
		{
			if (serach_env(varenv(input), msh) != NULL)
				printf("%s", serach_env(varenv(input), msh));
			return (1);
		}
	}
	return (0);
}
