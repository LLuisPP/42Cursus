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

void	verify_varenv(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->tkns->cmd[i])
	{
		if (msh->tkns->cmd[i] == '$')
			printf("Is calling a varenv\n");
		i++;
	}
}