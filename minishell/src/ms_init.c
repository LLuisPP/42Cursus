/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:27 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/21 10:41:11 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* inicia las estructuras del .h (no borrar) No trabajo en ella */
int	init_structs(t_env *env, t_mshll *msh)
{
	ft_bzero(env, sizeof(t_env));
	ft_bzero(msh, sizeof(t_mshll));
	return (0);
}
