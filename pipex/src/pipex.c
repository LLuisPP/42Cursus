/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/26 18:53:37 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **env)
{
	t_p	pipe;

	// pipe = (t_p *)malloc(sizeof(t_p)); // inicio struct
	// if(!pipe){ // proteccion fallo
	// 	perror(E_MALLOC);
	// 	exit(0);
	// }
	ft_bzero(&pipe, sizeof(t_p)); // Limpiar struct
	parse_data(argc, argv, &pipe, env); // parseo de datos
	
	
	getpath(env, &pipe); // recibir direcciones path
	
	ft_printf("Control del finaldel programa\n");
	// free(pipe); // liberamos estructura
	return (0);
}
