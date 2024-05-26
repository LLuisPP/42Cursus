/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:08:55 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/26 18:53:28 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int    getpath(char **path, t_p *pipe)
{
    char    *tmp;
    int     i;
    int     j;

    j = -1;
    while (++j <= 1)
    {
        i = -1;
        while (path[++i] && !pipe->cmd[j].path)
        {
            tmp = ft_strjoin(path[i], pipe->cmd[j].path);
            if (!tmp)
                exit(ft_fd_printf(2, "%s", E_MALLOC) * 0 + 1);
            if (access(tmp, F_OK) == 0)
                pipe->cmd[j].path = ft_strdup(tmp);
            if (tmp)
            {
                free(tmp);
                tmp = NULL;
            }
        }
    }
    return(0);
}

int parse_data(int argc, char **argv, t_p *pipe, char **env)
{
    if (!env) // verificamos existe environment
		exit(ft_fd_printf(2, "%s", E_ENV) * 0 + 1);
        
    if (argc != 5) // verificamos existen suficientes argumentos (pipex + 4)
        exit(ft_fd_printf(2, "%s", E_ARG) * 0 + 1);

    // verificacion existencia archivo de entrada in_file
    if (access(argv[1], F_OK) == -1)
        pipe->status_1 = ft_fd_printf(2, "%s: %s", argv[1], E_NOFILE) * 0 - 1;
    else if (access(argv[1], R_OK) == -1)
        pipe->status_1 = ft_fd_printf(2, "%s: %s", argv[1], E_RD) * 0 -1;
    // verificacion existencia archivo de salida out_file    
    if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) == -1)
        pipe->status_2 = ft_fd_printf(2, "%s: %s", argv[4], E_WR) * 0 -1;
    // apertura del archivo de entrada    
    pipe->fd_inp = open(argv[1], O_RDONLY);
    // verificacion apertura in_file
    if (pipe->fd_inp < 0)
		pipe->status_1 = ft_fd_printf(2, "%s: %s", argv[1], E_OPEN) * 0 - 1;
	// apertura del archivo de salida
    pipe->fd_outp = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0666);
    // verificacion apertura out_file    
	if (pipe->fd_outp < 0)
		pipe->status_2 = ft_fd_printf(2, "%s: %s", argv[4], E_OPEN) * 0 - 1;
        
    return (0);
}
