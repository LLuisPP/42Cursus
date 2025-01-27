/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:22:42 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/14 11:13:49 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Actualiza las variables de entorno, buscando el nombre de la variable
	que se le pasa como argumento. Devuelve el nuevo valor actualizado
	*/
char	*update_env(t_msh *msh, char *name, char *value)
{
	char	*new_value;
	int		i;

	i = 0;
	if (!value || !name)
		return (NULL);
	while (msh->env->names[i] && msh->env->values[i])
	{
		if (ft_strcmp(msh->env->names[i], name) == 0)
		{
			new_value = ft_strdup(value);
			if (!new_value)
				return (NULL);
			free(msh->env->values[i]);
			msh->env->values[i] = new_value;
			break ;
		}
		i++;
	}
	return (msh->env->values[i]);
}
