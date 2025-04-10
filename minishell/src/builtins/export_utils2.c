/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_export_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:40:25 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/05 10:40:44 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export_vars(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->env->names[i])
	{
		ft_fd_printf(1, "declare -x %s", msh->env->names[i]);
		if (msh->env->values[i][0])
			ft_fd_printf(1, "=\"%s\"", msh->env->values[i]);
		ft_fd_printf(1, "\n");
		i++;
	}
}
