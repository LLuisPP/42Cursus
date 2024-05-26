/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:08:55 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/26 11:37:22 by lprieto-         ###   ########.fr       */
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
        while (path[++i] && !pipe->path)
        {
            tmp = ft_strjoin(path[i], pipe->path);
            if (!tmp)
                exit(ft_fd_printf(2, "%s", E_MALLOC) * 0 + 1);
            if (access(tmp, F_OK) == 0)
                pipe->path = ft_strdup(tmp);
            if (tmp)
            {
                free(tmp);
                tmp = NULL;
            }
        }
    }
    return(0);
}

int parse_data(int argc, char **argv, t_p *pipe)
{
    if (argc != 5)
        exit(ft_fd_printf(2, "%s", E_ARG) * 0 -1);
    if (access(argv[1], F_OK) == -1)
        ft_fd_printf(2, "%s", E_OPEN);
    else if (access(argv[1], R_OK) == -1)
        pipe->file = ft_fd_printf(2, "%s: %s", argv[1], E_NOFILE) * 0 -1;
    if (access(argv[4], F_OK) == -1)
        ft_fd_printf(2, "%s", E_WR);
    return (0);
}
