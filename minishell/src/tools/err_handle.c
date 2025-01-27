/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handle_ms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:32:36 by lprieto-          #+#    #+#             */
/*   Updated: 2025/01/13 18:30:30 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_cd_error(char *path, int error_type)
{
	if (error_type == EACCES)
		ft_fd_printf(2, "cd: %s: Permission denied\n", path);
	else if (error_type == ENOTDIR)
		ft_fd_printf(2, "cd: %s: Not a directory\n", path);
	else
		ft_fd_printf(2, "cd: %s: No such file or directory\n", path);
}

int	ft_err(t_msh *msh, int err_code)
{
	int	final_err;

	final_err = err_code % 256;
	if (err_code < 0)
		final_err += 256;
	msh->last_exit_code = final_err;
	return (final_err);
}
