/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_err_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:32:36 by lprieto-          #+#    #+#             */
/*   Updated: 2024/11/06 17:50:58 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_err(t_msh *msh, int err_code)
{
    int final_err;

    final_err = err_code % 256;
    if(err_code < 0)
        final_err += 256;
    msh->last_exit_code = final_err;
    return (final_err);
}