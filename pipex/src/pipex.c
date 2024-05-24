/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/24 10:47:01 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int	main(int argc, char **argv, char **env)
{
	t_p	*pipe;
	int fd;

	fd = open("1", O_RDONLY);
	perror("hola frank:");
return (0);
	if (argc != 5)
		err_end(E_ARG);
	ft_bzero(&pipe, sizeof(t_p));
	pipe = (t_p *)malloc(sizeof(t_p));
	if(!pipe){
		perror(E_MALLOC);
		exit(0);
	}

	ft_printf("\n", env);
	ft_printf("\n", argv[0]);
	ft_printf("que hay en pipe?\n", pipe);	
	return (0);
}
