/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:28:01 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/28 22:55:06 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static int	verify_varenv(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
			return (i);
		i++;
	}
    return (-1);
}

void    acces_varenv(t_msh *msh, char *input)7
{
    int pos;

    pos = verify_varenv(input);
    //Look to env 
}*/

int	find_envb(t_msh *msh, char *envar)
{
	int	i;

	i = 0;
	while(*msh->env[i].names[i] != '\0')
	{
		if (ft_strcmp(envar, msh->env->names[i]) == 0)
			return (i);
		i++;
	}
	return(-1);
}