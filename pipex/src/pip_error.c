/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:27:42 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/20 11:38:37 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	err_end(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_printf("\n");
	ft_printf("   ╔═══════════════════════ SYNTAX PROTOTYPE ═══╗\n");
	ft_printf("   ║                                            ║\n");
	ft_printf("   ║    ./pipex [prm 1][prm 2][prm 3][prm 4]    ║\n");
	ft_printf("   ║             file   cmnd   cmnd   file2     ║\n");
    ft_printf("   ║                                            ║\n");
	ft_printf("   ╚════════════════════════════════════════════╝\n");
    ft_printf("   ╔════════════════════════ SYNTAX EXAMPLES ═══╗\n");
	ft_printf("   ║                                            ║\n");
	ft_printf("   ║ ./pipex text.txt 'ls -l' 'wc -l output.txt ║\n");
	ft_printf("   ║           file1   cmnd1   cmnd2   file2    ║\n");
    ft_printf("   ║                                            ║\n");
	ft_printf("   ╚════════════════════════════════════════════╝\n");
	exit(0);
}