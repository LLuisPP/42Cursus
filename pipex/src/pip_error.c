/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:27:42 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/24 10:41:05 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_end(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_printf("\n");
	ft_printf("   ╔══ SYNTAX PROTOTYPE ══════════════════════════════╗\n");
	ft_printf("   ║                                                  ║\n");
	ft_printf("   ║     ./pipex  arg 1   arg 2   arg 3   arg 4       ║\n");
	ft_printf("   ║             [file1] [cmnd1] [cmnd2] [file2]      ║\n");
    ft_printf("   ║                                                  ║\n");
    ft_printf("   ╠══ EXAMPLE                                      ══╣\n");
	ft_printf("   ║                                                  ║\n");
	ft_printf("   ║   ./pipex input.txt 'ls -l' 'wc -l' output.txt   ║\n");
	ft_printf("   ║            [file1]  [cmnd1] [cmnd2]  [file2]     ║\n");
    ft_printf("   ║                                                  ║\n");
	ft_printf("   ╚══════════════════════════════════════════════════╝\n\n");
	perror("hola que tal");
	//exit(1);
}
